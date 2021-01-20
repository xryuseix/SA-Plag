/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_f
F - LCSEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6144033
// 提出ID : 6144033
// 問題ID : dp_f
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 2461
// 実行時間 : 88



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
  string s, t;
  cin >> s >> t;
  vector<vector<int>> dp(s.length() + 10, vector<int>(t.length() + 10));
  rep(i, s.length() + 10) rep(j, t.length() + 10) dp[i][j] = 0;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < t.length(); j++) {
      if (s[i] == t[j])
        chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      chmax(dp[i + 1][j + 1], dp[i + 1][j]);
      chmax(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  string res = "";
  int i = s.length(), j = t.length();
  while (i > 0 && j > 0) {
    // (i-1, j) -> (i, j) と更新されていた場合
    if (dp[i][j] == dp[i - 1][j]) {
      --i; // DP の遷移を遡る
    }

    // (i, j-1) -> (i, j) と更新されていた場合
    else if (dp[i][j] == dp[i][j - 1]) {
      --j; // DP の遷移を遡る
    }

    // (i-1, j-1) -> (i, j) と更新されていた場合
    else {
      res = s[i - 1] +
            res; // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
      --i, --j; // DP の遷移を遡る
    }
  }
  cout << res << endl;
  //////////////////////////////////////////////////////
  return 0;
}
