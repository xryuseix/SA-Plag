/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_a
A - Frog 1Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6223190
// 提出ID : 6223190
// 問題ID : dp_a
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 1764
// 実行時間 : 9



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
  vector<ll> h(n + 1), dp(n + 1, INF);
  rep(i, n) cin >> h[i + 1];
  dp[0] = 1000000;
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    // cout<<dp[i]<<" "<<abs(h[i]-h[i-1])<<endl;
    chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    // cout<<dp[i]<<endl;
  }
  cout << dp[n] << endl;

  //////////////////////////////////////////////////////
  return 0;
}
