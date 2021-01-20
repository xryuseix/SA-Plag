/*
引用元：https://atcoder.jp/contests/abc022/tasks/abc022_c
C - Blue BirdEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc022/submissions/7995414
// 提出ID : 7995414
// 問題ID : abc022_c
// コンテストID : abc022
// ユーザID : xryuseix
// コード長 : 3342
// 実行時間 : 71



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
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  };
};
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

class WAR_FLY {
public:
  vvi d; //辺の数
  int V; //頂点の数

  WAR_FLY(int n) {
    V = n;
    d = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (i == j) {
          d[i][j] = 0;
        } else {
          d[i][j] = INF;
        }
      }
    }
  }

  void warshall_floyd() {
    for (int k = 0; k < V; k++) {
      for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
          d[i][j] = min((ll)d[i][j], (ll)d[i][k] + (ll)d[k][j]);
        }
      }
    }
  }

  void add(int from, int to, int cost) { d[from][to] = cost; }

  bool is_negative_loop() {
    for (int i = 0; i < V; i++) {
      if (d[i][i] < 0)
        return true;
    }
    return false;
  }

  void show() {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        cout << d[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main(void) {

  int n, m;
  cin >> n >> m;
  WAR_FLY wa(n);
  vi connect;
  map<pair<int, int>, int> M;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    if (a > b) {
      swap(a, b);
    }
    if (a == 0) {
      connect.push_back(b);
      M[mp(a, b)] = c;
    } else {
      wa.add(a, b, c);
      wa.add(b, a, c);
    }
  }
  wa.warshall_floyd();
  ll ans = LLINF;
  for (int i = 0; i < connect.size() - 1; i++) {
    for (int j = i + 1; j < connect.size(); j++) {
      ll sum = 0;
      sum += M[mp(0, connect[i])];
      sum += wa.d[connect[i]][connect[j]];
      sum += M[mp(0, connect[j])];
      ans = min(ans, sum);
    }
  }
  if (ans > INF / 2) {
    fin(-1);
  } else
    fin(ans);
}
