/*
引用元：https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_d
D - テンキー (Tenkey)Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/joi2020yo2/submissions/9013363
// 提出ID : 9013363
// 問題ID : joi2020_yo2_d
// コンテストID : joi2020yo2
// ユーザID : xryuseix
// コード長 : 4023
// 実行時間 : 515



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
#include <unordered_set>
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
#define itn int
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
const ll MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

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

  void add(int from, int to) {
    d[from][to] = 1;
    d[to][from] = 1;
  }

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
int TURN = 40;
bool dp[60][10][101010];

int main(void) {

  int m, r;
  cin >> m >> r;

  WAR_FLY wa(10);
  wa.add(0, 1);
  wa.add(1, 4);
  wa.add(4, 7);
  wa.add(2, 5);
  wa.add(5, 8);
  wa.add(3, 6);
  wa.add(6, 9);
  wa.add(1, 2);
  wa.add(2, 3);
  wa.add(4, 5);
  wa.add(5, 6);
  wa.add(7, 8);
  wa.add(8, 9);

  wa.warshall_floyd();

  rep(i, m + 10) rep(j, 10) rep(k, TURN + 1) dp[k][j][i] = false;
  dp[1][0][0] = true;
  dp[1][1][0] = true;

  for (int a = 1; a < TURN; a++) {
    for (int b = 0; b < 10; b++) {
      for (int c = 0; c < m + 10; c++) {
        if (dp[a][b][c]) {
          for (int i = 0; i < 10; i++) {
            int dist = wa.d[b][i];
            if (b == i) {
              dp[a + 1][b][(10 * c + i) % m] = true;
              // dp[a+1][i][c] = true;
              // if((10*c+i)%m==r)push[a+1][b]=true;
            } else {
              dp[a + dist][i][c] = true;
            }
          }
        }
      }
    }
  }

  int ans = INF;
  rep(i, TURN) {
    rep(j, 10) {
      if (dp[i][j][r]) {
        ans = min(ans, i);
      }
    }
  }
  fin(ans);
}
