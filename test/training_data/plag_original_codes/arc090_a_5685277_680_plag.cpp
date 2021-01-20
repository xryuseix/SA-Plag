/*
引用元：https://atcoder.jp/contests/abc087/tasks/arc090_a
C - CandiesEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc087/submissions/5685277
// 提出ID : 5685277
// 問題ID : arc090_a
// コンテストID : abc087
// ユーザID : xryuseix
// コード長 : 1502
// 実行時間 : 1



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
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define P 1000000007
using namespace std;


int main(void) {
    int n;
    cin >> n;
    int a[2][n];
    rep(i, n) cin >> a[0][i];
    rep(i, n) cin >> a[1][i];
    ll dp[2][n];
    dp[0][0] = a[0][0];
    dp[1][0] = a[0][0] + a[1][0];
    for (i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + a[0][i];
    }
    for (i = 1; i < n; i++) {
        dp[1][i] = max(dp[1][i - 1], dp[0][i]) + a[1][i];
    }
    cout << dp[1][n - 1] << endl;
}
