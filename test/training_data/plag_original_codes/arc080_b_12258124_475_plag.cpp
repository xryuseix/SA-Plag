/*
引用元：https://atcoder.jp/contests/arc080/tasks/arc080_b
D - Grid ColoringEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/arc080/submissions/12258124
// 提出ID : 12258124
// 問題ID : arc080_b
// コンテストID : arc080
// ユーザID : xryuseix
// コード長 : 2976
// 実行時間 : 4



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
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vi v(n);
    rep(i, n) cin >> v[i];
    vvi g(h, vi(w));
    int x = 0, y = 0, pos = 0, ri = pos + 1, num;
    while (1) {
        num = pos + 1;
        g[y][x] = num;
        if (ri) {
            x++;
            if (x == w) {
                --x;
                ri = 0;
                ++y;
            }
        } else {
            --x;
            if (x == -1) {
                ++x;
                ri = true;
                ++y;
            }
        }
        v[pos]--;
        if (v[pos] == 0) pos++;
        if (pos >= n) break;
    }
    rep(i, h) {
        rep(j, g[i].size()) {
            if (!i)
                cout << g[i][j];
            else
                cout << " " << g[i][j];
        }
        cout << endl;
    }
}