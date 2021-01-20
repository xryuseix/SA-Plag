/*
引用元：https://atcoder.jp/contests/abc032/tasks/abc032_c
C - 列Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc032/submissions/6659051
// 提出ID : 6659051
// 問題ID : abc032_c
// コンテストID : abc032
// ユーザID : xryuseix
// コード長 : 2046
// 実行時間 : 13



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

int main(void) {
    ll n, k;
    cin >> n >> k;
    vll v(n);
    rep(i, n) cin >> v[i];
    ll ans = 0;
    bool iszero = false;
    rep(i, n) iszero |= !v[i];
    if (iszero) {
        cout << n << endl;
    } else {
        ll tmp = 1, first = 0;
        for (ll i = 0; i < n; i++) {
            tmp *= v[i];
            if (tmp > k) {
                ans = max(ans, (ll)(i - first));
                while (first <= i && tmp > k) {
                    tmp /= v[first++];
                }
            }
        }
        ans = max(ans, n - first);
        cout << ans << endl;
    }
}
