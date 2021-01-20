/*
引用元：https://atcoder.jp/contests/past201912-open/tasks/past201912_j
J - LevelingEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past201912-open/submissions/11742516
// 提出ID : 11742516
// 問題ID : past201912_j
// コンテストID : past201912-open
// ユーザID : xryuseix
// コード長 : 4770
// 実行時間 : 943



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
#define rep(j, n) for (int j = 0; j < (n); ++j)
#define rrep(j, n) for (int j = 1; j <= (n); ++j)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(j, n) for (int j = (n)-1; j >= 0; --j)
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
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

class DIJKSTRA {
   public:
    int V;

    struct dk_edge {
        int to;
        int cost;
    };

    typedef pair<int, int> PI;  // firstは最短距離、secondは頂点の番号
    vector<vector<dk_edge>> G;
    vector<int> d;     //これ答え。d[j]:=V[j]までの最短距離
    vector<int> prev;  //経路復元

    DIJKSTRA(int size) {
        V = size;
        G = vector<vector<dk_edge>>(V);
        prev = vector<int>(V, -1);
    }

    void add(int from, int to, int cost) {
        dk_edge e = {to, cost};
        G[from].push_back(e);
    }

    void dijkstra(int s) {
        // greater<P>を指定することでfirstが小さい順に取り出せるようにする
        priority_queue<PI, vector<PI>, greater<PI>> que;
        d = vector<int>(V, INF);
        d[s] = 0;
        que.push(PI(0, s));

        while (!que.empty()) {
            PI p = que.top();
            que.pop();
            int v = p.second;
            if (d[v] < p.first) continue;
            for (int j = 0; j < G[v].size(); j++) {
                dk_edge e = G[v][j];
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    prev[e.to] = v;
                    que.push(PI(d[e.to], e.to));
                }
            }
        }
    }
};

int main() {
    int h, w;
    cin >> h >> w;
    vvi v(h, vi(w));
    rep(j, h) rep(i, w) cin >> v[j][i];
    ll ans = LLINF;

    DIJKSTRA wa(h * w);
    rep(i, w) {
        rep(j, h - 1) {
            wa.add((j + 1) * w + i, j * w + i, v[j][i]);
            wa.add(j * w + i, (j + 1) * w + i, v[j + 1][i]);
        }
    }
    rep(j, h) {
        rep(i, w - 1) {
            wa.add(j * w + i + 1, j * w + i, v[j][i]);
            wa.add(j * w + i, j * w + i + 1, v[j][i + 1]);
        }
    }
    rep(j, h) {
        rep(i, w) {
            wa.dijkstra(j * w + i);
            ans = min(ans, (ll)wa.d[(h - 1) * w] + wa.d[h * w - 1] +
                               wa.d[w - 1] + v[j][i]);
        }
    }
    fin(ans);
}
