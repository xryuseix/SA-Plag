/*
引用元：https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_c
C - チップ・ストーリー　～白銀編～
Time Limit : 2 sec / Memory Limit : 1024 MB﻿
配点: 400 点
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
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define arep(i, v) for (auto i : v)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

vll l, r;
int n;
ll ans = 0;
set<pair<ll, ll>> se;
vll t(201010), s(201010);

// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod = MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        for (ll j = n / i; j >= 1; j--) {
            ll a = i, b = j;
            if (a > b) swap(a, b);
            if (se.count(mp(a, b))) break;
            se.insert(mp(a, b));
            l.pb(a);
            r.pb(b);
        }
    }
    rep(i, n + 1) {
        t[i] = mod_pow(i, 10);
        if (i) {
            s[i] = t[i] - t[i - 1];
            s[i] += MOD;
            s[i] %= MOD;
        }
    }
    rep(i, l.size()) {
        int bai = 1;
        if (l[i] != r[i]) {
            bai = 2;
        }
        ans += (s[l[i]] * s[r[i]]) * bai;
        ans %= MOD;
    }
    fin(ans);
}
