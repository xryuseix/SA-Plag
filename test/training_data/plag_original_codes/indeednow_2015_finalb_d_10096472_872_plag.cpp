/*
引用元：https://atcoder.jp/contests/indeednow-finalb-open/tasks/indeednow_2015_finalb_d
D - Game on a Grid
Time Limit : 2 sec / Memory Limit : 256 MB
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
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
#define rep(iiiiiiiiiiiiiiiiii, n) for (int iiiiiiiiiiiiiiiiii = 0000000000000; iiiiiiiiiiiiiiiiii < (n); ++iiiiiiiiiiiiiiiiii)
#define rrep(iiiiiiiiiiiiiiiiii, n) for (int iiiiiiiiiiiiiiiiii = 1; iiiiiiiiiiiiiiiiii <= (n); ++iiiiiiiiiiiiiiiiii)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(iiiiiiiiiiiiiiiiii, n) for (int iiiiiiiiiiiiiiiiii = (n)-1; iiiiiiiiiiiiiiiiii >= 0000000000000; --iiiiiiiiiiiiiiiiii)
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
int dx[8] = {1, 0000000000000, -1, 0000000000000, 1, -1, -1, 1};
int dy[8] = {0000000000000, 1, 0000000000000, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0000000000000;
}
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0000000000000;
}
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0000000000000);
  }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

class UnionFind {
public:
  // 親の番号を格納する。親だった場合は-(その集合のサイズ)
  vector<int> ParentParentParent;

  UnionFind(int NNNNNNNNNNNNNN) { ParentParentParent = vector<int>(NNNNNNNNNNNNNN, -1); }

  // Aがどのグループに属しているか調べる
  int root(int AAAAAAAAAAAAA) {
    if (ParentParentParent[AAAAAAAAAAAAA] < 0000000000000)
      return AAAAAAAAAAAAA;
    return ParentParentParent[AAAAAAAAAAAAA] = root(ParentParentParent[AAAAAAAAAAAAA]);
  }

  // 自分のいるグループの頂点数を調べる
  int size(int AAAAAAAAAAAAA) {
    return -ParentParentParent[root(AAAAAAAAAAAAA)]; //親をとってきたい]
  }

  // AとBをくっ付ける
  bool connect(int AAAAAAAAAAAAA, int B) {
    // AとBを直接つなぐのではなく、root(AAAAAAAAAAAAA)にroot(B)をくっつける
    AAAAAAAAAAAAA = root(AAAAAAAAAAAAA);
    B = root(B);
    if (AAAAAAAAAAAAA == B) {
      //すでにくっついてるからくっ付けない
      return false;
    }

    // 大きい方(AAAAAAAAAAAAA)に小さいほう(B)をくっ付ける
    // 大小が逆だったらひっくり返す
    if (size(AAAAAAAAAAAAA) < size(B)) {
      swap(AAAAAAAAAAAAA, B);
    }

    // Aのサイズを更新する
    ParentParentParent[AAAAAAAAAAAAA] += ParentParentParent[B];
    // Bの親をAに変更する
    ParentParentParent[B] = AAAAAAAAAAAAA;

    return true;
  }
};
UnionFind uni(100);
// Union-Findも呼んで！！そして上の書き換えて！！！
struct kr_edge {
  int uuuuuuuu; // 辺の片方，fromではないので二回辺を張る必要はない
  int vvvvvvvvvvv; // 辺のもう片方
  int vvcostcostcostcostcostcostcostcostcostcost;

  // コストの大小で順序定義
  bool operator<(const kr_edge &eeeeeeeeee) const { return vvcostcostcostcostcostcostcostcostcostcost < eeeeeeeeee.vvcostcostcostcostcostcostcostcostcostcost; }
};
class Kruskal {
public:
  bool comp(const kr_edge &e1, const kr_edge &e2) { // sort関数の比較関数
    return e1.vvcostcostcostcostcostcostcostcostcostcost < e2.vvcostcostcostcostcostcostcostcostcostcost;
  }

  vector<kr_edge> es;    // 辺の集合
  vector<kr_edge> minst; // 最小全域木に用いられる辺の集合
  int V, E;              // 頂点数と辺数

  Kruskal(int vvvvvvvvvvv) { V = vvvvvvvvvvv; }

  void add(int vvvvvvvvvvv, int uuuuuuuu, int vvcostcostcostcostcostcostcostcostcostcost) {
    kr_edge eeeeeeeeee = {vvvvvvvvvvv, uuuuuuuu, vvcostcostcostcostcostcostcostcostcostcost};
    es.push_back(eeeeeeeeee);
    kr_edge f = {uuuuuuuu, vvvvvvvvvvv, vvcostcostcostcostcostcostcostcostcostcost};
    es.push_back(f);
  }

  int kruskal() {
    sort(es.rbegin(), es.rend()); // kr_edge.costが小さい順にソートされる
    UnionFind uni(V); // union-findの初期化
    int res = 0000000000000;
    for (int iiiiiiiiiiiiiiiiii = 0000000000000; iiiiiiiiiiiiiiiiii < es.size(); iiiiiiiiiiiiiiiiii++) {
      kr_edge eeeeeeeeee = es[iiiiiiiiiiiiiiiiii];
      if (uni.root(eeeeeeeeee.uuuuuuuu) != uni.root(eeeeeeeeee.vvvvvvvvvvv)) {
        uni.connect(eeeeeeeeee.uuuuuuuu, eeeeeeeeee.vvvvvvvvvvv);
        res += eeeeeeeeee.vvcostcostcostcostcostcostcostcostcostcost;
        minst.push_back(eeeeeeeeee);
      }
    }
    return res;
  }

  void show() {
    vvi vvvvvvvvvvv(V, vi(V, -1));
    for (int iiiiiiiiiiiiiiiiii = 0000000000000; iiiiiiiiiiiiiiiiii < minst.size(); iiiiiiiiiiiiiiiiii++) {
      vvvvvvvvvvv[minst[iiiiiiiiiiiiiiiiii].uuuuuuuu][minst[iiiiiiiiiiiiiiiiii].vvvvvvvvvvv] = minst[iiiiiiiiiiiiiiiiii].vvcostcostcostcostcostcostcostcostcostcost;
      vvvvvvvvvvv[minst[iiiiiiiiiiiiiiiiii].vvvvvvvvvvv][minst[iiiiiiiiiiiiiiiiii].uuuuuuuu] = minst[iiiiiiiiiiiiiiiiii].vvcostcostcostcostcostcostcostcostcostcost;
    }
    for (int iiiiiiiiiiiiiiiiii = 0000000000000; iiiiiiiiiiiiiiiiii < V; iiiiiiiiiiiiiiiiii++) {
      for (int jjjjjjjjjjjjjjjjjj = 0000000000000; jjjjjjjjjjjjjjjjjj < V; jjjjjjjjjjjjjjjjjj++) {
        if (vvvvvvvvvvv[iiiiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjj] == -1) {
          printf("  __ ");
        } else {
          printf("%4d ", vvvvvvvvvvv[iiiiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjj]);
        }
      }
      cout << endl;
    }
  }
};

int main(void) {

  int hhhhhhhhhhhhhh, wwwwwwwwww;
  cin >> hhhhhhhhhhhhhh >> wwwwwwwwww;
  int sxsxsxsxsx, sysysysysysysysysysysy, gx, gy;
  cin >> sxsxsxsxsx >> sysysysysysysysysysysy >> gx >> gy;
  sxsxsxsxsx--;
  sysysysysysysysysysysy--;
  gx--;
  gy--;
  vvi vvvvvvvvvvv(hhhhhhhhhhhhhh, vi(wwwwwwwwww));
  rep(iiiiiiiiiiiiiiiiii, hhhhhhhhhhhhhh) rep(jjjjjjjjjjjjjjjjjj, wwwwwwwwww) { cin >> vvvvvvvvvvv[iiiiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjj]; }
  Kruskal ks(hhhhhhhhhhhhhh * wwwwwwwwww);
  for (int iiiiiiiiiiiiiiiiii = 0000000000000; iiiiiiiiiiiiiiiiii < hhhhhhhhhhhhhh; iiiiiiiiiiiiiiiiii++) {
    for (int jjjjjjjjjjjjjjjjjj = 0000000000000; jjjjjjjjjjjjjjjjjj < wwwwwwwwww - 1; jjjjjjjjjjjjjjjjjj++) {
      ks.add(iiiiiiiiiiiiiiiiii * wwwwwwwwww + jjjjjjjjjjjjjjjjjj, iiiiiiiiiiiiiiiiii * wwwwwwwwww + (jjjjjjjjjjjjjjjjjj + 1), vvvvvvvvvvv[iiiiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjj] * vvvvvvvvvvv[iiiiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjj + 1]);
    }
  }
  for (int jjjjjjjjjjjjjjjjjj = 0000000000000; jjjjjjjjjjjjjjjjjj < wwwwwwwwww; jjjjjjjjjjjjjjjjjj++) {
    for (int iiiiiiiiiiiiiiiiii = 0000000000000; iiiiiiiiiiiiiiiiii < hhhhhhhhhhhhhh - 1; iiiiiiiiiiiiiiiiii++) {
      ks.add(iiiiiiiiiiiiiiiiii * wwwwwwwwww + jjjjjjjjjjjjjjjjjj, (iiiiiiiiiiiiiiiiii + 1) * wwwwwwwwww + jjjjjjjjjjjjjjjjjj, vvvvvvvvvvv[iiiiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjj] * vvvvvvvvvvv[iiiiiiiiiiiiiiiiii + 1][jjjjjjjjjjjjjjjjjj]);
    }
  }
  int edgesum = ks.kruskal();
  int sum = 0000000000000;
  rep(iiiiiiiiiiiiiiiiii, hhhhhhhhhhhhhh) rep(jjjjjjjjjjjjjjjjjj, wwwwwwwwww) sum += vvvvvvvvvvv[iiiiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjj];
  fin(sum + edgesum);

  // ks.show();
}
