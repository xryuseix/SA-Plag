/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_e
E - Knapsack 2Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6140799
// 提出ID : 6140799
// 問題ID : dp_e
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 2108
// 実行時間 : 36



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

  ll n, W;
  cin >> n >> W;
  vector<ll> w(n), v(n);
  ll vmax = 0;
  rep(i, n) { cin >> w[i] >> v[i]; }
  vmax = 100010;

  ll dp[n + 1][vmax];

  rep(i, n + 1) rep(j, vmax) dp[i][j] = LLINF;
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < vmax; j++) {
      if (j - v[i] >= 0) {
        chmin(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
      }

      chmin(dp[i + 1][j], dp[i][j]);
    }
  } /*
   for(int i=0;i<n;i++){
       for(int j=0;j<vmax;j++){
           cout<<dp[i][j]<<" ";
       }
       cout<<endl<<endl;
   }/*/
  ll ans = 0;
  for (int i = 0; i < vmax; i++) {
    if (dp[n][i] <= W)
      ans = i;
  }

  cout << ans << endl;

  //////////////////////////////////////////////////////
  return 0;
}
