/*
引用元：https://atcoder.jp/contests/arc074/tasks/arc074_a
C - Chocolate Bar
Time Limit : 2 sec / Memory Limit : 256 MB
配点 : 400 点
*/
#include <algorithm>
#include <bitset>
#include <cassert>
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
#include <unordered_set>
#include <vector>
#pragma GCC optimize("Ofast")
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
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())

const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main(void) {
    ll h, w;
    cin >> h >> w;
    ll ans = LLINF;
    for (int i = 0; i < w - 1; i++) {
        ll Sa = (i + 1) * h;
        ll Sb = h / 2 * (w - (i + 1));
        ll Sc = (h - h / 2) * (w - (i + 1));
        ans = min(ans, max({Sa, Sb, Sc}) - min({Sa, Sb, Sc}));
        ll hb = (w - i - 1) / 2;
        ll hc = w - hb - (i + 1);
        Sb = hb * h;
        Sc = hc * h;
        ans = min(ans, max({Sa, Sb, Sc}) - min({Sa, Sb, Sc}));
    }
    for (int i = 0; i < h - 1; i++) {
        ll Sa = (i + 1) * w;
        ll Sb = w / 2 * (h - (i + 1));
        ll Sc = (w - w / 2) * (h - (i + 1));
        ans = min(ans, max({Sa, Sb, Sc}) - min({Sa, Sb, Sc}));
        ll hb = (h - i - 1) / 2;
        ll hc = h - hb - (i + 1);
        Sb = hb * w;
        Sc = hc * w;
        ans = min(ans, max({Sa, Sb, Sc}) - min({Sa, Sb, Sc}));
    }
    fin(ans);
}
