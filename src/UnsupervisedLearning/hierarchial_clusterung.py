# 階層クラスタリング

# Import libraries
"""Main"""
import numpy as np
import pandas as pd
import os, time, re
import pickle, gzip

"""Data Viz"""
import matplotlib.pyplot as plt
import seaborn as sns

color = sns.color_palette()
import matplotlib as mpl

"""Algorithms"""
import fastcluster
from scipy.cluster.hierarchy import dendrogram, cophenet, fcluster
from scipy.spatial.distance import pdist


# Load the data
# X_train = pd.read_csv("./data.csv")
X_train = pd.read_csv("../classification/tfidf.csv")

# print(X_train.shape) # (140, 12)
# print(X_train.head())

# 標準化
def normalization(X_train):
    for c in X_train.columns.values.tolist():
        X_train[c] = (X_train[c] - X_train[c].mean()) / X_train[c].std()
    return X_train


# 閾値をもとにクラスターを形成する
def make_cluster(distance_threshold, Z, X_train):
    # distance_threshold = 0.05065  # クラスター数がちょうど70になる値, 二分探索でよかったな
    clusters = fcluster(Z, distance_threshold, criterion="distance")
    X_train_hierClustered = pd.DataFrame(
        data=clusters, index=X_train.index, columns=["cluster"]
    )
    return clusters, X_train_hierClustered


# 二分探索で指定した数のクラスターができる距離の閾値を探す
def binary_distance_threshold(X_train, Z, SIZE, log=False):

    ok = 10000
    ng = 0
    memo = {}
    while abs(ok - ng) > 0.00001:
        mid = (ok + ng) / 2
        clusters, X_train_hierClustered = make_cluster(mid, Z, X_train)
        clusters_size = len(X_train_hierClustered["cluster"].unique())
        memo[clusters_size] = mid
        if log:
            print(
                "threshold : {:>20.15f}, clusters_size : {:>3}".format(
                    mid, clusters_size
                )
            )
        if clusters_size == SIZE:
            ok = mid
            break
        elif clusters_size < SIZE:
            ok = mid
        else:
            ng = mid
    if log:
        print(
            "Number of distinct clusters: ",
            len(X_train_hierClustered["cluster"].unique()),
        )
    return ok, clusters, X_train_hierClustered, memo


# クラスターの評価
def analyzeCluster(clusterDF, log=False):
    if log:
        print(clusterDF)
    # クラスターを配列に変換
    clusters = [[] for i in range(len(clusterDF["cluster"].unique()))]
    for i in range(len(clusterDF)):
        clusters[int(clusterDF.loc[i]) - 1].append(i // 2 * 2)
    if log:
        print(clusters)

    # 精度を計算
    tp = fp = fn = tn = 0.0
    for cluster in clusters:
        cluster.sort()
        same = 0
        for i in range(len(cluster) - 1):
            same += cluster[i] == cluster[i + 1]
        tp += same
        fp += len(cluster) * (len(cluster) - 1) / 2 - same
    remain_pair = len(clusterDF) * (len(clusterDF) - 1) / 2
    fn = len(clusterDF) / 2 - tp
    tn = remain_pair - tp - fp - fn

    accuracy = (tp + tn) / (fp + fn + tp + tn)
    precision = tp / (tp + fp) if (tp + fp) else 0.0
    recall = tp / (tp + fn) if (tp + fn) else 0.0
    f_measure = (
        2 * precision * recall / (precision + recall) if (precision + recall) else 0.0
    )

    if log:
        print("tp: {}".format(tp))
        print("fp: {}".format(fp))
        print("fn: {}".format(fn))
        print("tn: {}".format(tn))
        print("accuracy: {}".format(accuracy))
        print("precision: {}".format(precision))
        print("recall: {}".format(recall))
        print("f_measure: {}".format(f_measure))

    return (
        {
            "tp": tp,
            "fp": fp,
            "fn": fn,
            "tn": tn,
            "accuracy": accuracy,
            "precision": precision,
            "recall": recall,
            "f_measure": f_measure,
        },
        clusters,
    )


# 少ない列を削除
print(X_train.shape)
# drop_columns = X_train.columns[X_train.var(axis='index') <= 2]#  0.5 by bunsan  のとき
# X_train = X_train.drop(drop_columns, axis=1)
# print(X_train.shape)

X_train = X_train[:880]
print(X_train.shape)

# 正規化
# X_train = normalization(X_train)


methods = ["ward"]
# methods = ["ward", "single", "centroid", "median"]
for method in methods:
    Z = fastcluster.linkage_vector(X_train, method=method, metric="euclidean")

    Z_dataFrame = pd.DataFrame(
        data=Z, columns=["clusterOne", "clusterTwo", "distance", "newClusterSize"]
    )

    # print(Z_dataFrame[:10])

    BINARY_SEARCH = 0
    LINER_SEARCH = 1
    if BINARY_SEARCH:
        # クラスター数を要素数の半分とした時の閾値を決めて評価
        (
            distance_threshold,
            clusters,
            X_train_hierClustered,
            memo,
        ) = binary_distance_threshold(X_train, Z, len(X_train) // 2, True)
        analyzeCluster(X_train_hierClustered, True)

    if LINER_SEARCH:
        # accuracy, f_measureが最大になる時のクラスター数を探して評価
        threshold_by_group = {}
        max_f_measure = {"f_measure": 0.0}  # F値が最大になるときのパラメータとか
        max_f_cluster_sets = []  # F値が最大になるときのグループの集合
        for group in range(1, len(X_train) + 1):
            if group in threshold_by_group:  # メモ化ですでに計算済みの場合
                clusters, X_train_hierClustered = make_cluster(
                    threshold_by_group[group], Z, X_train
                )
            else:
                (
                    distance_threshold,
                    clusters,
                    X_train_hierClustered,
                    memo,
                ) = binary_distance_threshold(X_train, Z, group)
                threshold_by_group.update(memo)  # メモの更新(merge)

            result, cluster_sets = analyzeCluster(X_train_hierClustered)
            if max_f_measure["f_measure"] < result["f_measure"]:
                max_f_measure = result
                max_f_measure["cluster"] = group
                max_f_cluster_sets = cluster_sets
        print("\n[{}]".format(method))
        max_f_measure["threshold"] = threshold_by_group[max_f_measure["cluster"]]
        print(max_f_measure)
        print(max_f_cluster_sets)

