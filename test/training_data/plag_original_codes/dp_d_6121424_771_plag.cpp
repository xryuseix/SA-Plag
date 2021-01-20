/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_d
D - Knapsack 1Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6121424
// 提出ID : 6121424
// 問題ID : dp_d
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 1804
// 実行時間 : 30



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
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << endl
#define P 1000000007
#define STI(s) atoi(s.c_str())  // string to int
#define mp(p, q) make_pair(p, q)
#define Sort(a) sort(a.begin(), a.end())
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const int INF = INT_MAX;
const long long LLINF = 1LL << 60;
// g++ -std=c++1z temp.cpp
//./a.out

int main(void) {
    int n, W;
    cin >> n >> W;

    vector<ll> w(n + 1), v(n + 1);
    rep(i, n) { cin >> w[i + 1] >> v[i + 1]; }
    ll dynamic_programming[n + 1][W + 1];
    rep(i, W + 1) dynamic_programming[0][i] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= W; j++) {
            if (j - w[i] >= 0) {
                dynamic_programming[i][j] = max(dynamic_programming[i - 1][j], dynamic_programming[i - 1][j - w[i]] + v[i]);
            } else {
                dynamic_programming[i][j] = dynamic_programming[i - 1][j];
            }
        }
    }
    cout << dynamic_programming[n][W] << endl;
}
