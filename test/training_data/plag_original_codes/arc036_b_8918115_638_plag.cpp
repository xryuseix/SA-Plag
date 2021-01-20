/*
引用元：https://atcoder.jp/contests/arc036/tasks/arc036_b
B - 山のデータEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc036/submissions/8918115
// 提出ID : 8918115
// 問題ID : arc036_b
// コンテストID : arc036
// ユーザID : xryuseix
// コード長 : 2548
// 実行時間 : 122



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
#define itn int
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
struct io {
    io() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    };
};
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int main(void) {
    ll n;
    cin >> n;
    vll h(n);
    rep(i, n) cin >> h[i];

    ll pos = 0;
    bool ch = 1;
    if (n == 1) {
        fin(1);
    } else {
        if (h[0] > h[1]) ch = 0;
        vll v, w;
        while (pos < n) {
            ll tmp = pos;
            ll len = 1;
            if (ch) {
                while (tmp + 1 < n && h[tmp] < h[tmp + 1]) {
                    len++;
                    tmp++;
                }
            } else {
                while (tmp + 1 < n && h[tmp] > h[tmp + 1]) {
                    len++;
                    tmp++;
                }
            }
            pos += max(len - 1, 1LL);
            w.push_back(ch);
            v.push_back(len);
            ch ^= 1;
        }
        ll ans = 0;
        rep(i, v.size()) {
            if (!w[i]) {
                chmax(ans, v[i]);
            } else if (w[i] && i < v.size() - 1) {
                chmax(ans, v[i] + v[i++ + 1] - 1);
            } else {
                chmax(ans, v[i]);
            }
        }

        fin(ans);
    }
}
