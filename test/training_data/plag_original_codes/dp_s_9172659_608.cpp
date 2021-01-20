/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_s
S - Digit SumEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/9172659
// 提出ID : 9172659
// 問題ID : dp_s
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 2497
// 実行時間 : 129



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

  string k;
  int d;
  cin >> k >> d;
  ll dp[k.size() + 10][2][d + 10];
  rep(i, k.size() + 10) rep(j, 2) rep(k, d + 10) dp[i][j][k] = 0;

  dp[0][1][0] = 1;
  for (int i = 0; i < k.size(); i++) {
    // きつい
    for (int j = 0; j < d; j++) {
      for (int m = 0; m <= k[i] - '0' - 1; m++) {
        dp[i + 1][0][(j + m) % d] += dp[i][1][j];
        dp[i + 1][0][(j + m) % d] %= MOD;
      }
      dp[i + 1][1][(j + (k[i] - '0')) % d] += dp[i][1][j];
      dp[i + 1][1][(j + (k[i] - '0')) % d] %= MOD;
    }

    //緩い
    for (int j = 0; j < d; j++) {
      for (int m = 0; m <= 9; m++) {
        dp[i + 1][0][(j + m) % d] += dp[i][0][j];
        dp[i + 1][0][(j + m) % d] %= MOD;
      }
    }
  }

  ll ans = 0;

  ans += dp[k.size()][0][0];
  ans %= MOD;
  ans += dp[k.size()][1][0];
  ans %= MOD;

  fin((ans - 1 + MOD) % MOD);
}
