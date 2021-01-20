/*
引用元：https://atcoder.jp/contests/past201912-open/tasks/past201912_h
H - Bulk SellingEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past201912-open/submissions/11745221
// 提出ID : 11745221
// 問題ID : past201912_h
// コンテストID : past201912-open
// ユーザID : xryuseix
// コード長 : 3384
// 実行時間 : 195



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
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {
    ll allMin = INT_MAX, oddMin = INT_MAX;
    ll n, x, a, Q, q, allSum = 0, oddSum = 0;
    cin >> n;
    vll c(n);
    rep(i, n) cin >> c[i];
    rep(i, n) {
        chmin(allMin, c[i]);
        if (!(i % 2)) chmin(oddMin, c[i]);
    }
    ll ans = 0;
    cin >> Q;
    while (Q--) {
        cin >> q;
        if (q == 1) {
            cin >> x >> a;
            x--;
            if ((!x % 2 && c[x] - oddSum - allSum >= a) ||
                (x % 2 && c[x] - allSum >= a)) {
                c[x] -= a;
                ans += a;
                if (!(x % 2)) chmin(oddMin, c[x]);
                chmin(allMin, c[x]);
            }
        } else if (q == 2) {
            cin >> a;
            if (oddMin - a >= 0) {
                ll num = ceil(n / (double)2);
                oddSum += a;
                oddMin -= a;
                ans += num * a;
                chmin(allMin, oddMin);
            }
        } else if (q == 3) {
            cin >> a;
            if (allMin - a >= 0) {
                allSum += a;
                ans += n * a;
                allMin -= a;
                oddMin -= a;
                chmin(allMin, oddMin);
            }
        }
    }
    fin(ans);
}
