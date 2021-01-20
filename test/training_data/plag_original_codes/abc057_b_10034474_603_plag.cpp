/*
引用元：https://atcoder.jp/contests/abc057/tasks/abc057_b
B - Checkpoints
Time Limit : 2 sec / Memory Limit : 256 MB
配点 : 200 点
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
int main(void) {
    int n, m, a, b;
    cin >> n >> m;
    vpii v(n);
    rep(i, n) {
        cin >> a >> b;
        v[i] = mp(a, b);
    }
    vpii w(m);
    rep(i, m) {
        cin >> a >> b;
        w[i] = mp(a, b);
    }
    rep(i, n) {
        int ans = 1;
        rep(j, m) {
        int dis = INF;
            int dist =
                abs(v[i].second - w[j].second) + abs(v[i].first - w[j].first);
            if (dis > dist) {
                ans = j + 1;
                dis = dist;
            } else if (dis == dist) {
                ans = min(ans, j + 1);
            }
        }
        fin(ans);
    }
}
