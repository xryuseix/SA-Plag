/*
引用元：https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_d
D - パ研軍旗Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/pakencamp-2019-day3/submissions/9137291
// 提出ID : 9137291
// 問題ID : pakencamp_2019_day3_d
// コンテストID : pakencamp-2019-day3
// ユーザID : xryuseix
// コード長 : 2547
// 実行時間 : 2



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
  }
};
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {

  int n;
  cin >> n;
  vvc v(5, vc(n));
  rep(i, 5) rep(j, n) cin >> v[i][j];
  vvi dp(3, vi(n, INF));
  int r = 0, b = 0, w = 0;
  for (int i = 0; i < 5; i++) {
    if (v[i][0] == 'W')
      w++;
    else if (v[i][0] == 'B')
      b++;
    else if (v[i][0] == 'R')
      r++;
  }
  dp[0][0] = 5 - r;
  dp[1][0] = 5 - b;
  dp[2][0] = 5 - w;
  r = b = w = 0;
  for (int i = 1; i < n; i++) {
    int color[3] = {0};
    // fin(i);
    for (int j = 0; j < 5; j++) {
      // cout<<"j:";
      // fin(j);
      if (v[j][i] == 'W')
        color[2]++;
      else if (v[j][i] == 'B')
        color[1]++;
      else if (v[j][i] == 'R')
        color[0]++;
    }
    // fin(i);
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (k == j)
          continue;
        chmin(dp[j][i], dp[k][i - 1] + (5 - color[j]));
      }
    }
  }
  int ans = INF;
  rep(i, 3) ans = min(ans, dp[i][n - 1]);
  fin(ans);
}
