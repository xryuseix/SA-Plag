# hdbscan

# Import libraries
"""Main"""
import numpy as np
import pandas as pd
import os, time, re
import pickle, gzip
from tqdm import tqdm

"""Data Viz"""
import matplotlib.pyplot as plt

"""Algorithms"""
import hdbscan


# クラスターの評価
def analyzeCluster(clusterDF, log=False):
    if log:
        print(clusterDF)
    # クラスターを配列に変換
    clusters = [[] for i in range(len(clusterDF["cluster"].unique()))]
    for i in range(len(clusterDF)):
        clusters[int(clusterDF.loc[i])].append(i // 2 * 2)
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


def train(X_train, parameters):
    hdb = hdbscan.HDBSCAN(
        min_cluster_size=parameters["min_cluster_size"],
        min_samples=parameters["min_samples"],
        cluster_selection_method=parameters["cluster_selection_method"]
    )

    X_train_hdbscanClustered = hdb.fit_predict(X_train)
    X_train_hdbscanClustered = pd.DataFrame(
        data=X_train_hdbscanClustered, index=X_train.index, columns=["cluster"]
    )
    return analyzeCluster(X_train_hdbscanClustered, False)


def get_parametor(X_train):
    # パラメータ
    parameters = {
        "min_cluster_size": 2,
        "min_samples": 20,
        "cluster_selection_method": "leaf",
    }
    max_f_measure = {"f_measure": 0.0}  # F値が最大になるときのパラメータとか
    max_f_cluster_sets = []  # F値が最大になるときのグループの集合
    f_measutre_transition = []  # F値の推移

    for min_samples in tqdm(range(2, 280)):
        parameters["min_samples"] = min_samples
        result, cluster_sets = train(X_train, parameters)
        f_measutre_transition.append(max_f_measure["f_measure"])
        if max_f_measure["f_measure"] < result["f_measure"]:
            max_f_measure = result
            max_f_measure["min_samples"] = min_samples
            max_f_cluster_sets = cluster_sets
    print("[hdbscan]")
    print(max_f_measure)
    print(max_f_cluster_sets)
    # 折れ線グラフを出力
    left = np.arange(2, 280)
    height = np.array(f_measutre_transition)
    plt.plot(left, height)
    plt.show()


if __name__ == "__main__":
    # Load the data
    # X_train = pd.read_csv("../hierarchial_clusterung/data.csv")
    X_train = pd.read_csv("../classification/tfidf.csv")
    # 学習
    get_parametor(X_train[:880])

