/*
引用元：https://atcoder.jp/contests/practice2/tasks/practice2_d
D - MaxflowEditorial
Time Limit : 5 sec / Memory Limit : 1024 MB
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
#include <deque>
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
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define fi first
#define se second
#include <atcoder/all>
using namespace atcoder;

/* --------------------   ここまでテンプレ   -------------------- */

int main() {
    int n, m;
    cin >> n >> m;
    mf_graph<int> graph(n * m + 2);
    vs v(n);
    rep(i, n) cin >> v[i];
    rep(i, n) {
        rep(j, m) {
            if (v[i][j] == '#') continue;
            if ((i + j) % 2 == 0)
                graph.add_edge(n * m, i * m + j, 1);
            else
                graph.add_edge(i * m + j, n * m + 1, 1);
            if ((i + j) % 2) continue;
            rep(k, 4) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (nx >= m || ny >= n || nx < 0 || ny < 0) continue;
                if (v[ny][nx] == '#') continue;
                graph.add_edge(i * m + j, ny * m + nx, 1);
            }
        }
    }
    int cap = graph.flow(n * m, n * m + 1);
    fin(cap);
    auto ed = graph.edges();
    rep(i, ed.size()) {
        if (!ed[i].flow) continue;
        if (ed[i].from >= n * m || ed[i].to >= n * m) continue;
        int from_x = ed[i].from % m, from_y = ed[i].from / m;
        int to_x = ed[i].to % m, to_y = ed[i].to / m;

        if (from_y == to_y + 1) {
            v[from_y][from_x] = '^';
            v[to_y][to_x] = 'v';
        } else if (from_x == to_x + 1) {
            v[from_y][from_x] = '<';
            v[to_y][to_x] = '>';
        } else if (from_y == to_y - 1) {
            v[to_y][to_x] = '^';
            v[from_y][from_x] = 'v';
        } else {
            v[to_y][to_x] = '<';
            v[from_y][from_x] = '>';
        }
    }
    rep(i, n) fin(v[i]);
}
