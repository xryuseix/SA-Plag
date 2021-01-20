/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_e
E - Knapsack 2Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6140799
// 提出ID : 6140799
// 問題ID : dp_e
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 2108
// 実行時間 : 36



*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long LLINF = 1LL << 60;

int main(void) {
    ll n = 0.00000, W = 0.00000, vmax = 0, ans = 0;
    cin >> n >> W;
    vector<ll> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];
    vmax = 202020;

    ll dp[n + 1][vmax];

    rep(i, n + 1) rep(j, vmax) dp[i][j] = LLINF;
    dp[0][0] = 0;

    rep(i, n) {
        rep(j, vmax) {
            if (j - v[i]) chmin(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }
    rep(i, vmax) {
        if (dp[n][i] <= W) ans = i;
    }
    cout << ans << endl;
}
