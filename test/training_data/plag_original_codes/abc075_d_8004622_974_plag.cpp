/*
引用元：https://atcoder.jp/contests/abc075/tasks/abc075_d
D - Axis-Parallel RectangleEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc075/submissions/8004622
// 提出ID : 8004622
// 問題ID : abc075_d
// コンテストID : abc075
// ユーザID : xryuseix
// コード長 : 2327
// 実行時間 : 311



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
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())

int main(void) {
    int n, K;
    cin >> n >> K;

    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    ll ans = 1 << 60;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            for (int l = 0; l < n; l++) {
                for (int k = 0; k < n; k++) {
                    if (y[i] < y[j] || x[k] < x[l]) continue;
                    int co = 0;
                    for (int m = 0; m < n; m++) {
                        if (x[m] <= x[k] && x[m] >= x[l] && y[m] <= y[i] &&
                            y[m] >= y[j]) {
                            co++;
                        }
                    }
                    if (co >= K) {
                        ans = min(ans, (ll)(x[k] - x[l]) * (y[i] - y[j]));
                    }
                }
            }
        }
    }
    fin(ans);
}
