// 引用元 : https://atcoder.jp/contests/abc138/submissions/7497813
// 得点 : 300
// コード長 : 352
// 実行時間 : 11
#define rep(i, n) for (ll i = 0; i < (n); ++i)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i,N) cin >> v[i];
    sort(begin(v), end(v));

    double res = (v[0] + v[1]) / 2.0;
    rep(i,N) {
        res = (res + v[i+2]) / 2.0;
    }
    printf("%.6f\n",res);
}
