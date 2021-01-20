/*
引用元：https://atcoder.jp/contests/abc011/tasks/abc011_3
C - 123引き算Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc011/submissions/5120967
// 提出ID : 5120967
// 問題ID : abc011_3
// コンテストID : abc011
// ユーザID : xryuseix
// コード長 : 1398
// 実行時間 : 1



*/
#include <bits/stdc++.h>

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
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
using namespace std;
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
int main(void) {
    int i, n, ng[3], j, k;
    int dp[301];
    cin >> n >> ng[0] >> ng[1] >> ng[2];
    sort(ng, ng + 3);
    rep(i, 301) dp[i] = INF;
    dp[n] = 0;
    for (i = n; i > 0; i--) {
        if (i == ng[0] || i == ng[1] || i == ng[2]) continue;
        rep(j, 4) {
            if (i - j >= 0 && i - j != ng[0] && i - j != ng[1] &&
                i - j != ng[2]) {
                chmin(dp[i - j], dp[i] + 1);
            }
        }
    }
    if (!(dp[0] > 100) && !(dp[0] < 0))
        fin("NO");
    else
        fin("YES");
}
