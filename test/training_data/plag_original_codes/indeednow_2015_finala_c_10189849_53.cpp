/*
引用元：https://atcoder.jp/contests/indeednow-finala-open/tasks/indeednow_2015_finala_c
C - Optimal Recommendations
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
  }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main(void) {

  int dp[110][110][110];
  rep(i, 110) rep(j, 110) rep(k, 110) dp[i][j][k] = 0;
  int n, m;
  cin >> n >> m;
  rep(i, n) {
    int a, b, c, w;
    cin >> a >> b >> c >> w;
    chmax(dp[a][b][c], w);
  }
  rep(i, 101) rep(j, 101) rep(k, 101) {
    chmax(dp[i + 1][j][k], dp[i][j][k]);
    chmax(dp[i][j + 1][k], dp[i][j][k]);
    chmax(dp[i][j][k + 1], dp[i][j][k]);
  }
  rep(q, m) {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = dp[x][y][z];
    if (x > 0)
      chmax(ans, dp[x - 1][y][z]);
    if (y > 0)
      chmax(ans, dp[x][y - 1][z]);
    if (z > 0)
      chmax(ans, dp[x][y][z - 1]);
    fin(ans);
  }
}
