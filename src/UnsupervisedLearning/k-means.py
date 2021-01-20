# k-means

# Import libraries
"""Main"""
import numpy as np
import pandas as pd
import os, time, re
import pickle, gzip
from tqdm import tqdm
import matplotlib.pyplot as plt

"""Data Viz"""
import matplotlib.pyplot as plt
import seaborn as sns

color = sns.color_palette()
import matplotlib as mpl

"""Algorithms"""
import fastcluster

from scipy.cluster.hierarchy import dendrogram, cophenet, fcluster
from scipy.spatial.distance import pdist
from sklearn.cluster import KMeans


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


def train(X_train, parameters):
    kMeans_inertia = pd.DataFrame(data=[], index=range(10, 31), columns=["inertia"])
    kmeans = KMeans(
        n_clusters=parameters["n_clusters"],
        n_init=parameters["n_init"],
        max_iter=parameters["max_iter"],
        tol=parameters["tol"],
        random_state=parameters["random_state"],
        n_jobs=parameters["n_jobs"],
    )

    kmeans.fit(X_train)
    kMeans_inertia.loc[parameters["n_clusters"]] = kmeans.inertia_
    X_train_kmeansClustered = kmeans.predict(X_train)
    X_train_kmeansClustered = pd.DataFrame(
        data=X_train_kmeansClustered, index=X_train.index, columns=["cluster"]
    )
    return analyzeCluster(X_train_kmeansClustered, False)


def k_means(X_train):
    # パラメータ
    parameters = {
        "n_init": 10,
        "max_iter": 300,
        "tol": 0.0001,
        "random_state": 2018,
        "n_jobs": 2,
    }
    max_f_measure = {"f_measure": 0.0}  # F値が最大になるときのパラメータとか
    max_f_cluster_sets = []  # F値が最大になるときのグループの集合
    f_measutre_transition = [] # F値の推移
    
    for n_clusters in tqdm(range(30, 280)):
        parameters["n_clusters"] = n_clusters
        result, cluster_sets = train(X_train, parameters)
        f_measutre_transition.append(max_f_measure["f_measure"])
        if max_f_measure["f_measure"] < result["f_measure"]:
            max_f_measure = result
            max_f_measure["cluster"] = n_clusters
            max_f_cluster_sets = cluster_sets
    print("[k-means]")
    print(max_f_measure)
    print(max_f_cluster_sets)
    # 折れ線グラフを出力
    left = np.arange(30, 280)
    height = np.array(f_measutre_transition)
    plt.plot(left, height)
    plt.show()




if __name__ == "__main__":
    # Load the data
    # X_train = pd.read_csv("../hierarchial_clusterung/data.csv")
    X_train = pd.read_csv("../classification/tfidf.csv")[:880]
    # 学習
    k_means(X_train)

