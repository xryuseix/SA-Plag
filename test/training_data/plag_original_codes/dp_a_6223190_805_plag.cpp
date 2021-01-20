/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_a
A - Frog 1Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6223190
// 提出ID : 6223190
// 問題ID : dp_a
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 1764
// 実行時間 : 9



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
typedef long double ld;
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
const int INF = INT_MAX;

int main(void) {
    int n;
    cin >> n;
    vector<ll> h(n + 1), dp(n + 1, INF);
    rep(i, n) cin >> h[i + 1];
    dp[1] = 0;
    dp[0] = INF;
    rep(i, n + 1) {
        if (i < 2) continue;
        chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    }
    cout << dp[n] << endl;
}
