import pandas as pd

from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import (
    cross_val_score,
    train_test_split,
    ShuffleSplit,
)
from sklearn.metrics import accuracy_score
from sklearn.metrics import f1_score, recall_score
from sklearn.metrics import confusion_matrix
import pickle
from utils import *

# データの読み込み
data = pd.read_csv("./tfidf.csv", encoding="utf-8")

# plag_data = 216
# non_plag_data = 216

# 標準化
def standardization(df):
    return (df - df.values.mean()) / df.values.std()


# 正規化
def normalization(df):
    return (df - df.values.min()) / (df.values.max() - df.values.min())


# 学習用とテスト用に分離する

f1_sum = acc_sum = rec_sum = 0
tp_sum = fp_sum = tn_sum = fn_sum = 0

rep = 10  # 繰り返し回数
for i in range(rep):
    print("\n--", i, "-" * 20)
    
    x_train, x_test, y_train, y_test, plag_num, nonplag_num = split(data)
    print(x_train.shape, x_test.shape, y_train.shape, y_test.shape)
    
    # 学習する
    clf = RandomForestClassifier()
    scores = cross_val_score(clf, x_train, y_train, cv=5)
    print(scores)
    print("cross-val-score : ", scores.mean())
    clf.fit(x_train, y_train)

    # 評価する
    y_pred = clf.predict(x_test)
    y_prob = clf.predict_proba(x_test)  # 確率出す

    acc = accuracy_score(y_test, y_pred)
    rec = recall_score(y_test, y_pred)
    f1 = f1_score(y_test, y_pred)

    print("正解率 = ", acc)
    print("リコール = ", rec)
    print("F値 = ", f1)

    filename = "model.sav"
    pickle.dump(clf, open(filename, "wb"))

    tn, fp, fn, tp = confusion_matrix(y_test, y_pred, labels=[0, 1]).flatten()

    print("TP : {}, FP : {}".format(tp, fp))
    print("FN : {}, TN : {}".format(fn, tn))

    title = "Learning Curves"
    cv = ShuffleSplit(n_splits=5, test_size=0.2, random_state=0)
    plot_learning_curve(clf, title, x_train, y_train, cv=cv)

    acc_sum += acc
    rec_sum += rec
    f1_sum += f1
    tp_sum += tp
    fp_sum += fp
    tn_sum += tn
    fn_sum += fn

acc_sum /= rep
rec_sum /= rep
f1_sum /= rep
tp_sum /= rep
fp_sum /= rep
tn_sum /= rep
fn_sum /= rep

print("accuracy :", acc_sum)
print("recall :", rec_sum)
print("F1-measure :", f1_sum)
print("TP : {}%, FP : {}%".format(tp_sum/x_test.shape[0], fp_sum/x_test.shape[0]))
print("FN : {}%, TN : {}%".format(fn_sum/x_test.shape[0], tn_sum/x_test.shape[0]))
