# プログラムのトークンから出現頻度を計算しCSVで保存(ver.2)

import numpy as np
import os, glob, csv, copy, pickle
import tfidf
import tokenizecpp as tcp
import tokenizecpp_based_Avraham_Amon_CPP_Tokenizer.tokenize as tokenize
from tqdm import tqdm
from pathlib import Path


class File:
    # ファイル一覧を取得する
    @classmethod
    def get_file_names(cls, path):
        # 末尾の修正
        if path[-1] == "/":
            path = path[:-1]
        return sorted(glob.glob("%s/*" % (path)))

    # ファイルを読み込む
    @classmethod
    def read_file(cls, path, is_csv=False):
        if is_csv:
            with open(path) as f:
                reader = csv.reader(f)
                return [row for row in reader]
        else:
            with open(path) as f:
                return f.read()


# ソースコード管理クラス
class Code:
    # Codeクラスにソースコードを追加
    def add_code(self, str_code: str, visible: bool = False):
        self.token_code, self.str_len, self.token_len = self.tokenize(str_code)
        self.make_dic()
        if visible:
            print(self.code_vec)

    # 文字列のソースコードを受け取って，コメントを除き，トークン化した配列と文字列の長さを返す
    def tokenize(self, code: str, usetcp=True):
        rm_comment = tcp.remove_comment(code)
        if usetcp:
            token_str = tcp.to_tokenize(rm_comment)
            rm_stopwords_arr = self.remove_stop_words(token_str.split(" "))
            return (rm_stopwords_arr, len(rm_comment), len(token_str.split(" ")))
        else:
            token_arr = tokenize.tokenize(rm_comment)
            rm_stopwords_arr = self.remove_stop_words(token_arr)
            return (rm_stopwords_arr, len(rm_comment), len(token_arr))

    # ストップワードを取り除く
    def remove_stop_words(self, words):
        res = []
        for s in words:
            if s != "PUNC" and s != "PAREN" and s != "COMMENT":
                res.append(s)
        return res

    # 辞書を作成する
    def make_dic(self):
        tfidf.add_text(self.token_code)

    # 辞書をもとにtfidfの配列を取得する
    def to_indexed(self, tfidf_data, idx: int):
        self.tfidf_vec = tfidf_data[idx].tolist()

    # 文字列長，トークン長をmeanとstdをもとに再計算
    def recalc_len(self, len_mean, len_std, tok_mean, tok_std):
        self.str_std = (self.str_len - len_mean) / len_std
        self.token_std = (self.token_len - tok_mean) / tok_std

    # トークンベクトル，ソースコード長，トークン長を結合する
    def make_code_vector(self):
        self.vector = np.concatenate(
            [self.tfidf_vec, np.array([self.str_std, self.token_std]),]
        ).round(7)


# ファイル読み込み
print("盗作ファイル読み込み中...")
plag_code_filename = File.get_file_names("./plag_original_codes/")
print("オリジナルファイル読み込み中...")
nonplag_code_filename = File.get_file_names("./nonplag_original_codes/")


# 盗作データセット数
plag_num = len(plag_code_filename)
nonplag_num = len(nonplag_code_filename)

# ソースコードをクラスに追加
print("ソースコードをクラスに追加")
bar_class = tqdm(total=plag_num + nonplag_num)  # 進捗バー

plag_Code_class = [Code() for i in range(plag_num)]
nonplag_Code_class = [Code() for i in range(nonplag_num)]
str_len = []  # 文字列長
token_len = []  # トークン長

for i, file in enumerate(plag_code_filename):
    plag_Code_class[i].add_code(File.read_file(file))
    str_len.append(plag_Code_class[i].str_len)
    token_len.append(plag_Code_class[i].token_len)
    bar_class.update(1)
for i, file in enumerate(nonplag_code_filename):
    nonplag_Code_class[i].add_code(File.read_file(file))
    str_len.append(nonplag_Code_class[i].str_len)
    token_len.append(nonplag_Code_class[i].token_len)
    bar_class.update(1)
bar_class.close()

# TF-IDFの計算
tfidf_data = tfidf.calc_files()

# str_lenとtoken_lenのstdとmeanを計算
len_mean = np.array(str_len).mean()
len_std = np.array(str_len).std()
tok_mean = np.array(token_len).mean()
tok_std = np.array(token_len).std()

# ソースコードベクトルを作成
print("ソースコードベクトルを作成")
bar_code_vec = tqdm(total=plag_num + nonplag_num)  # 進捗バー

for i, code in enumerate(plag_Code_class):
    plag_Code_class[i].to_indexed(tfidf_data, i)
    plag_Code_class[i].recalc_len(len_mean, len_std, tok_mean, tok_std)
    plag_Code_class[i].make_code_vector()
    bar_code_vec.update(1)
for i, code in enumerate(nonplag_Code_class):
    nonplag_Code_class[i].to_indexed(tfidf_data, i + plag_num)
    nonplag_Code_class[i].recalc_len(len_mean, len_std, tok_mean, tok_std)
    nonplag_Code_class[i].make_code_vector()
    bar_code_vec.update(1)
bar_code_vec.close()


# 盗作ソースコードペアのベクトル
plag_code_vec = []
nonplag_code_vec = []

print("盗作ソースコードペアのベクトル作成")
bar_pair1 = tqdm(total=plag_num // 2)  # 進捗バー
for i in range(0, plag_num, 2):
    plag_code_vec.append(
        np.concatenate([plag_Code_class[i].vector, plag_Code_class[i + 1].vector, [1]])
    )
    bar_pair1.update()
bar_pair1.close()

print("非盗作ソースコードペアのベクトル作成")
bar_pair2 = tqdm(
    total=len(nonplag_Code_class) * (len(nonplag_Code_class) - 1) // 2
)  # 進捗バー
for i in range(0, len(nonplag_Code_class)):
    for j in range(i + 1, len(nonplag_Code_class)):
        nonplag_code_vec.append(
            np.concatenate(
                [nonplag_Code_class[i].vector, nonplag_Code_class[j].vector, [0]]
            )
        )
        bar_pair2.update()
bar_pair2.close()

# ヘッダー作成
keys = list(tfidf.word_dic.keys())
keys.remove("_id")
header = keys.copy()
extend_features = ["LENGTH", "TOKENLENGTH"]
header.extend(extend_features)
header.extend(keys.copy())
header.extend(extend_features)
header.append("LABEL")

# 非盗作ペアのみシャッフル
perm = np.random.permutation(len(nonplag_code_vec))
nonplag_code_vec = np.array(nonplag_code_vec)[perm]

# CSVに出力
print("CSV作成中...")
csv_data = np.concatenate([plag_code_vec, nonplag_code_vec])
with open("./tfidf.csv", "w") as f:
    writer = csv.writer(f)
    writer.writerow(header)
    writer.writerows(csv_data.tolist())

with open("./std_mean.csv", "w") as f:
    writer = csv.writer(f)
    writer.writerows([[len_mean, len_std], [tok_mean, tok_std]])

# dicファイル作成
tfidf.save_dic("./tfidf.dic")
