/*
引用元：https://atcoder.jp/contests/past202004-open/tasks/past202004_h
H - 1-9 GridEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past202004-open/submissions/12803026
// 提出ID : 12803026
// 問題ID : past202004_h
// コンテストID : past202004-open
// ユーザID : xryuseix
// コード長 : 5181
// 実行時間 : 22



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
#include <random>
#include <iomanip>
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
#define MATHPI acos(-1)
#define itn int
// #define endl '\n';
#define fi first
#define se second
#define NONVOID [[nodiscard]]
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline void dump(T &v) {
  irep(i, v) { cout << *i << ((i == --v.end()) ? '\n' : ' '); }
}
inline string getline() {
  string s;
  getline(cin, s);
  return s;
}
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  }
};
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr double EPS = 1e-9;

class DIJKSTRA {
public:
  int V;

  struct dk_edge {
    int to;
    int cost;
  };

  typedef pair<int, int> PI; // firstは最短距離、secondは頂点の番号
  vector<vector<dk_edge>> G;
  vector<int> d;    //これ答え。d[i]:=V[i]までの最短距離
  vector<int> prev; //経路復元

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
      if (d[v] < p.first)
        continue;
      for (int i = 0; i < G[v].size(); i++) {
        dk_edge e = G[v][i];
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          prev[e.to] = v;
          que.push(PI(d[e.to], e.to));
        }
      }
    }
  }
  vector<int> get_path(int t) {
    vector<int> path;
    for (; t != -1; t = prev[t]) {
      // tがsになるまでprev[t]をたどっていく
      path.push_back(t);
    }
    //このままだとt->sの順になっているので逆順にする
    reverse(path.begin(), path.end());
    return path;
  }
  void show(void) {
    for (int i = 0; i < d.size() - 1; i++) {
      cout << d[i] << " ";
    }
    cout << d[d.size() - 1] << endl;
  }
};

int main() {

  int n, m;
  cin >> n >> m;
  DIJKSTRA dj(n * m);
  vs v(n);
  int start = 0;
  int goal = 0;
  rep(i, n) cin >> v[i];
  rep(i, n) {
    rep(j, m) {
      char next;
      if (v[i][j] == 'S') {
        start = i * m + j;
        next = '1';
      } else if (v[i][j] == 'G') {
        goal = i * m + j;
        continue;
      } else if (v[i][j] == '9')
        next = 'G';
      else
        next = v[i][j] + 1;
      rep(h, n) {
        rep(w, m) {
          if (v[h][w] == next) {
            int dist = abs(h - i) + abs(w - j);
            int A = i * m + j;
            int B = h * m + w;
            dj.add(A, B, dist);
          }
        }
      }
    }
  }
  dj.dijkstra(start);
  if (dj.d[goal] != INF)
    cout << dj.d[goal] << endl;
  else
    fin(-1);
}
