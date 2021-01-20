/*
引用元：https://atcoder.jp/contests/abc042/tasks/arc058_b
D - Iroha and a GridEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc042/submissions/7425458
// 提出ID : 7425458
// 問題ID : arc058_b
// コンテストID : abc042
// ユーザID : xryuseix
// コード長 : 2591
// 実行時間 : 67



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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

vll memokai(200010, -1);

ll kai(ll n) {
    if (memokai[n] != -1)
        return memokai[n];
    else
        memokai[n] = kai(n - 1) * n % P;
    return memokai[n];
}

ll modinv(ll a) {
    ll b = P, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= P;
    if (u < 0) u += P;
    return u;
}

int root(pair<int, int> s, pair<int, int> g) {
    //圧縮
    int t = min(s.first, g.first);
    g.first -= t;
    s.first -= t;
    t = min(s.second, g.second);
    g.second -= t;
    s.second -= t;
    ll res = (kai(g.second + g.first)) % P *
             modinv(kai(g.first) * kai(g.second) % P) % P;
    return res;
}

ll ans = 0;
int h, w, a, b;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //////////////////////////////////////////////////////

    memokai[1] = 1;
    memokai[0] = 1;
    cin >> h >> w >> a >> b;
    for (int i = 0; i < w - b; i++) {
        ans += root(mp(0, 0), mp(h - a - 1, b + i)) *
               root(mp(h - a, b + i), mp(h - 1, w - 1)) % P;
        ans %= P;
    }
    fin(ans);

    //////////////////////////////////////////////////////
    return 0;
}
