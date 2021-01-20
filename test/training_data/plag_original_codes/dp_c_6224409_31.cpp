/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_c
C - VacationEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6224409
// 提出ID : 6224409
// 問題ID : dp_c
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 1815
// 実行時間 : 31



*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <bitset>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define P 1000000007
#define STI(s) atoi(s.c_str()) // string to int
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define Sort(a) sort(a.begin(), a.end())
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
const int INF = INT_MAX;
const long long LLINF = 1LL << 60;
// g++ -std=c++1z temp.cpp
//./a.out

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  int n;
  cin >> n;
  vi a(n), b(n), c(n);
  rep(i, n) cin >> a[i] >> b[i] >> c[i];
  vvi dp(n, vi(3, 0));
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];
  for (int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
    dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + c[i];
  }
  cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;

  //////////////////////////////////////////////////////
  return 0;
}
