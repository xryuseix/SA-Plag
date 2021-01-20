/*
引用元：https://atcoder.jp/contests/past202004-open/tasks/past202004_i
I - EliminationEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past202004-open/submissions/12804067
// 提出ID : 12804067
// 問題ID : past202004_i
// コンテストID : past202004-open
// ユーザID : xryuseix
// コード長 : 2975
// 実行時間 : 108



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
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define arep(i, v) for (auto i : v)
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

const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr double EPS = 1e-9;

int main() {
    int n;
    cin >> n;
    vi v(1 << n), w(1 << n);
    rep(i, 1 << n) cin >> v[i];
    rep(i, 1 << n) w[i] = i;
    vi ans(1 << n);
    rep(I, n) {
        vi win;
        for (int i = 0; i < w.size(); i = i + 2) {
            if (v[w[i]] < v[w[1 + i]]) {
                win.pb(w[1 + i]);
                ans[w[i]] = 1 + I;
            } else {
                win.pb(w[i]);
                ans[w[1 + i]] = 1 + I;
            }
        }
        w = win;
        if (I == n - 1) {
            ans[w[0]] = n;
        }
    }
    rep(i, (1 << n)) { cout << ans[i] << endl; }
}
