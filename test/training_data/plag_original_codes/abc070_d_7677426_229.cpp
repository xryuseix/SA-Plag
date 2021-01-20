/*
引用元：https://atcoder.jp/contests/abc070/tasks/abc070_d
D - Transit Tree PathEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc070/submissions/7677426
// 提出ID : 7677426
// 問題ID : abc070_d
// コンテストID : abc070
// ユーザID : xryuseix
// コード長 : 3404
// 実行時間 : 232



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
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

class DIJKSTRA {
public:
  ll V;

  struct edge {
    ll to;
    ll cost;
  };

  typedef pair<ll, ll> PI; // firstは最短距離、secondは頂点の番号
  vector<vector<edge>> G;
  vector<ll> d;    //これ答え。d[i]:=V[i]までの最短距離
  vector<ll> prev; //経路復元

  DIJKSTRA(ll size) {
    V = size;
    G = vector<vector<edge>>(V);
    prev = vector<ll>(V, -1);
  }

  void add(ll from, ll to, ll cost) {
    edge e = {to, cost};
    G[from].push_back(e);
  }

  void dijkstra(ll s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<PI, vector<PI>, greater<PI>> que;
    d = vector<ll>(V, LLINF);
    d[s] = 0;
    que.push(PI(0, s));

    while (!que.empty()) {
      PI p = que.top();
      que.pop();
      ll v = p.second;
      if (d[v] < p.first)
        continue;
      for (ll i = 0; i < G[v].size(); i++) {
        edge e = G[v][i];
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          prev[e.to] = v;
          que.push(PI(d[e.to], e.to));
        }
      }
    }
  }

  void show() {
    for (ll i = 0; i < d.size() - 1; i++) {
      cout << d[i] << " ";
    }
    cout << d[d.size() - 1] << endl;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  ll n;
  cin >> n;
  ll a, b, c;
  DIJKSTRA wa(n);
  rep(i, n - 1) {
    cin >> a >> b >> c;
    a--;
    b--;
    wa.add(a, b, c);
    wa.add(b, a, c);
  }
  ll q, k;
  cin >> q >> k;
  ll x, y;
  k--;
  wa.dijkstra(k);

  // wa.show();
  rep(i, q) {
    cin >> x >> y;
    x--;
    y--;
    fin((ll)wa.d[x] + (ll)wa.d[y]);
  }

  //////////////////////////////////////////////////////
  return 0;
}
