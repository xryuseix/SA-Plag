/*
引用元：https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_d
D - Many Go Round
Time Limit : 2 sec / Memory Limit : 256 MB
配点 : 100 点
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
#define MATHPI acos(-1)
#define itn int;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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

int main(void) {
    int n, m, l, x;
    cin >> n >> m >> l >> x;
    vi point((1 << 10), 0), next((1 << 10), 0), roop((1 << 10), (1 << 30)),
        a(n);
    rep(i, n) cin >> a[i];
    point[0] = roop[0] = 1;
    for (int i = 0; i < n; i++) {
        rep(j, (1 << 10)) next[j] = false;
        for (int j = 0; j < m; j++) {
            if (!point[j]) continue;
            if ((j + a[i]) / m + roop[j] > x) continue;
            next[j] = point[j];
            next[(j + a[i]) % m] = true;
            chmin(roop[(j + a[i]) % m], (j + a[i]) / m + roop[j]);
        }
        rep(j, (1 << 10)) point[j] = next[j];
    }
    if (point[l])
        fin("Yes");
    else
        fin("No");
}
