/*
引用元：https://atcoder.jp/contests/indeednow-finalb-open/tasks/indeednow_2015_finalb_d
D - Game on a Grid
Time Limit : 2 sec / Memory Limit : 256 MB
*/
#include <algorithm>
#include <bitset>
#include <cassert>
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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
    }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

class UnionFind {
   public:
    // 親の番号を格納．親だった場合は-(その集合のサイズ)
    vector<int> Parent;
    // 重さの差を格納
    vector<ll> diffWeight;

    UnionFind(const int N) {
        Parent = vector<int>(N, -1);
        diffWeight = vector<ll>(N, 0);
    }

    // Aがどのグループに属しているか調べる
    int root(const int A) {
        if (Parent[A] < 0) return A;
        int Root = root(Parent[A]);
        diffWeight[A] += diffWeight[Parent[A]];
        return Parent[A] = Root;
    }

    // 自分のいるグループの頂点数を調べる
    int size(const int A) { return -Parent[root(A)]; }

    // 自分の重さを調べる
    ll weight(const int A) {
        root(A);  // 経路圧縮
        return diffWeight[A];
    }

    // 重さの差を計算する
    ll diff(const int A, const int B) { return weight(B) - weight(A); }

    // AとBをくっ付ける
    bool connect(int A, int B, ll W = 0) {
        // Wをrootとの重み差分に変更
        W += weight(A);
        W -= weight(B);

        // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);

        if (A == B) {
            //すでにくっついてるからくっ付けない
            return false;
        }

        // 大きい方(A)に小さいほう(B)をくっ付ける
        // 大小が逆だったらひっくり返す
        if (size(A) < size(B)) {
            swap(A, B);
            W = -W;
        }

        // Aのサイズを更新する
        Parent[A] += Parent[B];
        // Bの親をAに変更する
        Parent[B] = A;

        // AはBの親であることが確定しているのでBにWの重みを充てる
        diffWeight[B] = W;

        return true;
    }
};
UnionFind uni(100);
// Union-Findも呼んで！！そして上の書き換えて！！！
struct kr_edge {
    int u;  // 辺の片方，fromではないので二回辺を張る必要はない
    int v;  // 辺のもう片方
    int cost;

    // コストの大小で順序定義
    bool operator<(const kr_edge &e) const { return cost < e.cost; }
};
class Kruskal {
   public:
    bool comp(const kr_edge &e1, const kr_edge &e2) {  // sort関数の比較関数
        return e1.cost < e2.cost;
    }

    vector<kr_edge> es;     // 辺の集合
    vector<kr_edge> minst;  // 最小全域木に用いられる辺の集合
    int V, E;               // 頂点数と辺数

    Kruskal(int v) { V = v; }

    void add(int v, int u, int cost) {
        kr_edge e = {v, u, cost};
        es.push_back(e);
        kr_edge f = {u, v, cost};
        es.push_back(f);
    }

    int kruskal() {
        sort(es.rbegin(), es.rend());  // kr_edge.costが小さい順にソートされる
        UnionFind uni(V);              // union-findの初期化
        int res = 0;
        for (int i = 0; i < es.size(); i++) {
            kr_edge e = es[i];
            if (uni.root(e.u) != uni.root(e.v)) {
                uni.connect(e.u, e.v);
                res += e.cost;
                minst.push_back(e);
            }
        }
        return res;
    }

    void show() {
        vvi v(V, vi(V, -1));
        for (int i = 0; i < minst.size(); i++) {
            v[minst[i].u][minst[i].v] = minst[i].cost;
            v[minst[i].v][minst[i].u] = minst[i].cost;
        }
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (v[i][j] == -1) {
                    printf("  __ ");
                } else {
                    printf("%4d ", v[i][j]);
                }
            }
            cout << endl;
        }
    }
};

int main(void) {
    int h, w;
    cin >> h >> w;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--;
    sy--;
    gx--;
    gy--;
    vvi v(h, vi(w));
    rep(i, h) rep(j, w) { cin >> v[i][j]; }
    Kruskal ks(h * w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w - 1; j++) {
            ks.add(i * w + j, i * w + (j + 1), v[i][j] * v[i][j + 1]);
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h - 1; i++) {
            ks.add(i * w + j, (i + 1) * w + j, v[i][j] * v[i + 1][j]);
        }
    }
    int edgesum = ks.kruskal();
    int sum = 0;
    rep(i, h) rep(j, w) sum += v[i][j];
    fin(sum + edgesum);
}
