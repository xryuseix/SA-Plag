// 引用元 : https://atcoder.jp/contests/abc073/submissions/10044155
// 得点 : 400
// コード長 : 2443
// 実行時間 : 16


#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i,a,b) for(int64_t i=(a); i<(b); ++i) // a ≦ i < b 
#define Rrep(i,a,b) for(int64_t i=(a);i>=(b);--i) // reverse repeat. a から b まで減少．
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend() //逆イテレータ
#define RANGE(a,b,c) (a).begin()+(b),(a).begin()+(c) // [b,c) イテレータ
#define INF 1000000000000000
#define MOD 1000000007
using PII = pair<int64_t, int64_t>;
using VI = vector<int64_t>;
using VVI = vector<VI>;
using VS = vector<string>;
using VP = vector<PII>;
using i64 = int64_t;
template<typename T> void invec(vector<T> &A){for(T& a : A) cin >> a;} // input vector

int main() {
cin.tie(0);
ios::sync_with_stdio(false);

int T, N, S; cin >> T >> N >> S;
VI s(S); invec(s);
sort(ALL(s));
VVI f(T+1, VI(T+1, INF));
rep(i, 1, T+1) f[i][i] = 0;
rep(i, 0, N){
    int64_t a, b, c; cin >> a >> b >> c;
    f[a][b] = c;
    f[b][a] = c;
}
rep(k, 1, T+1) rep(i, 1, T+1) if (f[i][k] < INF) 
    rep(j, 1, T+1) if (f[k][j] < INF)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

i64 mini = INF;
do {
    i64 dist = 0;
    rep(i, 0, S-1) dist += f[s[i]][s[i+1]];
    mini = min(mini, dist);
} while(next_permutation(ALL(s)));

cout << mini << "\n";

return 0;
}
// 書いて考える．場合分け．情報整理．
// 単純に分かる量から．
// 境界，出力文字列 チェック．行末にスペース入れない．
// 可読性優先．高速化次点．
// まずは全探索，分割，次にDP
// 制限を見る．境界に注意．求めたい量の変域．動かせる量．
// 偶奇，逆から，ソート，出現回数，出現位置，DP， 余事象，包除
// データ構造． 問題の特徴量．単調性，二分探索
// 存在判定：構成方法，入力の特徴
// gcd, lcm ,素因数分解．
// 例外を十分に含む一般化．想像力の限界
// 小さい系から例示
// 代数的処理．前処理によるクエリ高速化．
// 始めは過剰に例示・場合分けしてもいい．各場合を確実に対処．
// 自明な例から処理，除外．
// 小数のときは，精度の設定する．doubel 変数に数値を入力するときは 123. とする．
// テストケース作成は数表あり
// 実行エラー：vector添え字超え．0割り．

