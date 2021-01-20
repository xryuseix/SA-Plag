import matplotlib.pyplot as plt
import numpy as np
from sklearn.model_selection import learning_curve, train_test_split
from sklearn.feature_selection import SelectKBest, mutual_info_classif
import pandas as pd


def plot_learning_curve(
    estimator,
    title,
    X,
    y,
    ylim=None,
    cv=None,
    n_jobs=-1,
    train_sizes=np.linspace(0.1, 1.0, 5),
):
    plt.figure()
    plt.title(title)
    if ylim is not None:
        plt.ylim(*ylim)
    plt.xlabel("Training examples")
    plt.ylabel("Score")
    train_sizes, train_scores, test_scores = learning_curve(
        estimator, X, y, cv=cv, n_jobs=n_jobs, train_sizes=train_sizes
    )
    train_scores_mean = np.mean(train_scores, axis=1)
    train_scores_std = np.std(train_scores, axis=1)
    test_scores_mean = np.mean(test_scores, axis=1)
    test_scores_std = np.std(test_scores, axis=1)
    plt.grid()

    plt.fill_between(
        train_sizes,
        train_scores_mean - train_scores_std,
        train_scores_mean + train_scores_std,
        alpha=0.1,
        color="r",
    )
    plt.fill_between(
        train_sizes,
        test_scores_mean - test_scores_std,
        test_scores_mean + test_scores_std,
        alpha=0.1,
        color="g",
    )
    plt.plot(train_sizes, train_scores_mean, "o-", color="r", label="Training score")
    plt.plot(
        train_sizes, test_scores_mean, "o-", color="g", label="Cross-validation score"
    )

    plt.legend(loc="best")

    # plt.show()
    plt.savefig("plot_learning_curve.png")


def feature_selection(x_train, y_train, x_test):
    # 特徴選択
    selector = SelectKBest(k=3, score_func=mutual_info_classif)
    selector.fit(x_train, y_train)
    x_train = selector.transform(x_train)
    x_test = selector.transform(x_test)
    return x_train, x_test


def split(data):
    # ラベル1と0で分けて，シャッフル
    plag_num = (data["LABEL"] == 1).sum()
    nonplag_num = (data["LABEL"] == 0).sum()
    
    print("盗作データセット数 :", plag_num)
    print("非盗作データセット数 :", nonplag_num)

    true_data = data[:plag_num].copy().sample(frac=1)
    false_data = data[plag_num:].copy().sample(frac=1)[:plag_num]

    true_data_x = true_data.copy().drop(["LABEL"], axis=1)
    true_data_y = true_data.loc[:, "LABEL"]

    false_data_x = false_data.copy().drop(["LABEL"], axis=1)
    false_data_y = false_data.loc[:, "LABEL"]

    x = pd.concat([true_data_x, false_data_x])
    y = pd.concat([true_data_y, false_data_y])

    x_train, x_test, y_train, y_test = train_test_split(
        x, y, test_size=0.2, random_state=42
    )
    return x_train, x_test, y_train, y_test, plag_num, nonplag_num
