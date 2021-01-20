/*
引用元：https://atcoder.jp/contests/past201912-open/tasks/past201912_g
G - DivisionEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past201912-open/submissions/11740468
// 提出ID : 11740468
// 問題ID : past201912_g
// コンテストID : past201912-open
// ユーザID : xryuseix
// コード長 : 3228
// 実行時間 : 60



*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
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
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    ll ans = -(1LL << 60);
    vvi v(n, vi(n));
    rep(i, n - 1) {
        for (int j = i + 1; j < n; j++) {
            cin >> v[i][j];
        }
    }
    ll MAX = pow(3, n);
    rep(I, MAX) {
        string s = "";
        ll t = I;
        while (t) {
            s += char(t % 3 + '0');
            t /= 3;
        }
        while (s.size() < n) s += '0';
        reverse(all(s));
        vvi group(3);
        rep(i, s.size()) { group[s[i] - '0'].pb(i); }
        ll tans = 0;
        rep(j, group[0].size()) {
            for (int k = j + 1; k < group[0].size(); k++) {
                tans += v[group[0][j]][group[0][k]];
            }
        }
        rep(j, group[1].size()) {
            for (int k = j + 1; k < group[1].size(); k++) {
                tans += v[group[1][j]][group[1][k]];
            }
        }
        rep(j, group[2].size()) {
            for (int k = j + 1; k < group[2].size(); k++) {
                tans += v[group[2][j]][group[2][k]];
            }
        }
        chmax(ans, tans);
    }
    fin(ans);
}
