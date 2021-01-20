/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_i
I - CoinsEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/7194931
// 提出ID : 7194931
// 問題ID : dp_i
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 2127
// 実行時間 : 48



*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
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
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define mp(p, q) make_pair(p, q)
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {
    int n;
    double ans = 0;
    cin >> n;
    vd p(n);
    rep(i, n) cin >> p[i];
    vector<vector<double>> dp(n + 100, vector<double>(n + 100, 0));

    dp[0][0] = 1.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j] += dp[i][j] * (1 - p[i]);
            dp[i + 1][j + 1] += dp[i][j] * p[i];
        }
    }
    for (int i = (n + 1) / 2; i <= n; i++) ans += dp[n][i];

    printf("%.12f\n", ans);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            continue;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            continue;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            continue;
        }
    }
}
