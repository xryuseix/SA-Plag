/*
引用元：https://atcoder.jp/contests/arc060/tasks/arc060_a
C - Tak and CardsEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc060/submissions/8103461
// 提出ID : 8103461
// 問題ID : arc060_a
// コンテストID : arc060
// ユーザID : xryuseix
// コード長 : 2273
// 実行時間 : 68



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
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int main(void) {
  int n, a;
  cin >> n >> a;
  int x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  vector<vector<vector<ll>>> dp(n + 1,
                                vector<vector<ll>>(n + 1, vector<ll>(5000, 0)));

  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 5000; k++) {
        dp[i + 1][j][k] += dp[i][j][k];
        if (k + x[i] < 5000) {
          dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
        }
      }
    }
  }
  // for(int i=0;i<=n;i++){
  //     for(int j=0;j<5000;j++){
  //         cout<<dp[n][i][j]<<" ";
  //     }
  //     cout<<endl;
  // }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[n][i][a * i];
  }
  fin(ans);
}
