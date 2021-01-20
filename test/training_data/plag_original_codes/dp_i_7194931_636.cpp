/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_i
I - CoinsEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/7194931
// 提出ID : 7194931
// 問題ID : dp_i
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 2127
// 実行時間 : 48



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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int n;
  cin >> n;
  vd p(n);
  rep(i, n) cin >> p[i];
  vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));

  dp[0][0] = 1.0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
    }
  }
  double ans = 0;
  for (int i = (n + 1) / 2; i <= n; i++)
    ans += dp[n][i];

  printf("%.10f\n", ans);

  // for(int i=0;i<=n;i++){
  //     for(int j=0;j<=n;j++){
  //         printf("%3.3f ",dp[i][j]);
  //     }
  //     printf("\n");
  // }

  //////////////////////////////////////////////////////
  return 0;
}
