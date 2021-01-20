// 引用元 : https://atcoder.jp/contests/abc087/submissions/11158327
// 得点 : 400
// コード長 : 1641
// 実行時間 : 203


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MAX = 1e5;

struct Edge {
  ll to, cost;
};

vector<Edge> G[MAX];

void add_edge(ll l, ll r, ll d) {
  G[l].push_back({r, d});
  G[r].push_back({l, -d});
}

vector<ll> x(MAX, 0);
vector<bool> visited(MAX, false);
bool f = true;
ll xmin = 0, xmax = 0;

void dfs(ll from) {
  for (Edge e: G[from]) {
    if (!visited[e.to]) {
      x[e.to] = x[from] + e.cost;
      xmin = min(xmin, x[e.to]);
      xmax = max(xmax, x[e.to]);
      visited[e.to] = true;
      dfs(e.to);
    }
    else if (x[e.to] != x[from] + e.cost) {
      f = false;
      return;
    }
  }
  if (xmax - xmin > inf) {
    f = false;
  }
}



int main() {
  ll n, m;
  cin >> n >> m;
  rep(i, m) {
    ll l, r, d;
    cin >> l >> r >> d;
    l--, r--;
    add_edge(l, r, d);
  }

  rep(i, n) {
    if (visited[i]) continue;
    xmin = 0, xmax = 0;
    visited[i] = true;
    dfs(i);
    if (!f) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;



  
  return 0;
}
