/*
引用元：https://atcoder.jp/contests/arc044/tasks/arc044_b
B - 最短路問題Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc044/submissions/8987904
// 提出ID : 8987904
// 問題ID : arc044_b
// コンテストID : arc044
// ユーザID : xryuseix
// コード長 : 2421
// 実行時間 : 38



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
#define MATHPI acos(-1)
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res % mod;
}

int main(void) {
    ll n;
    cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];
    if (v[0] != 0) {
        fin(0);
        return 0;
    }
    rep(i, n) {
        if (i != 0 && !v[i]) {
            fin(0);
            return 0;
        }
    }
    vll cnt(100010, 0);
    rep(i, n) cnt[v[i]]++;
    Sort(v);
    for (ll i = 1; i < n; i++)
        if (v[i] - v[i - 1] > 1) {
            fin(0);
            return 0;
        }
    ll mx = v[n - 1];
    ll ans = 1;
    for (ll i = 1; i <= mx; i++) {
        ans = (ans *
               mod_pow((mod_pow(2ll, cnt[i - 1], MOD) - 1) + MOD, cnt[i], MOD) %
               MOD) %
              MOD;
        ans = (ans * mod_pow(2ll, (cnt[i] * (cnt[i] - 1) / 2ll), MOD) % MOD);
    }
    fin(ans);
}
