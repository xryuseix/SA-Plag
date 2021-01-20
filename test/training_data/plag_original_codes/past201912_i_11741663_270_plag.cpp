/*
引用元：https://atcoder.jp/contests/past201912-open/tasks/past201912_i
I - ProcurementEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past201912-open/submissions/11741663
// 提出ID : 11741663
// 問題ID : past201912_i
// コンテストID : past201912-open
// ユーザID : xryuseix
// コード長 : 2785
// 実行時間 : 6



*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << '\n'
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    int b[m], cost[m];
    vll dp((1 << n) + 10, 1LL << 60);
    string s;
    rep(i, m) {
        cin >> s;
        int num = false;
        rep(j, n) {
            if (s[j] == 'Y') {
                num += 1 << j;
            }
        }
        b[i] = num;
        cin >> cost[i];
    }
    dp[0] = false;
    rep(i, 1 << n) {
        if (dp[i] == (1LL << 60)) continue;
        for (int j = false; j < m; j++) {
            chmin(dp[i | b[j]], dp[i] + cost[j]);
        }
    }
    if (dp[(1 << n) - 1] == (1LL << 60))
        fin(-1);
    else
        fin(dp[(1 << n) - 1]);
}
