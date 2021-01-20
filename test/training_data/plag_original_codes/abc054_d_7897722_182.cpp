/*
引用元：https://atcoder.jp/contests/abc054/tasks/abc054_d
D - Mixing ExperimentEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc054/submissions/7897722
// 提出ID : 7897722
// 問題ID : abc054_d
// コンテストID : abc054
// ユーザID : xryuseix
// コード長 : 3338
// 実行時間 : 33



/*
                                   _ooOoo_
                                  o8888888o
                                  88" . "88
                                  (| -_- |)
                                  O\  =  /O
                           ____/`---'\____
                         .'  \\|     |//  `.
                        /  \\|||  :  |||//  \
                   /  _||||| -:- |||||-  \
                   |   | \\\  -  /// |   |
                   | \_|  ''\---/''  |   |
                   \  .-\__  `-`  ___/-. /
                 ___`. .'  /--.--\  `. . __
          ."" '<  `.___\_<|>_/___.'  >'"".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                fozubaoyou    pass System Test!
                quoted from
"https://codeforces.com/contest/472/submission/7996840"
*/

* /
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
#define PI acos(-1)
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
const ll LLINF = 1LL << 60;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main(void) {

  int n, ma, mb;
  cin >> n >> ma >> mb;
  vi a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(500, vector<int>(500, 0)));

  for (int i = 0; i <= n; i++)
    dp[i][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 500; j++) {
      for (int k = 0; k < 500; k++) {
        if (dp[i - 1][j][k] == 0)
          continue;
        if (dp[i][j + a[i]][k + b[i]] != 0) {
          dp[i][j + a[i]][k + b[i]] =
              min(dp[i][j + a[i]][k + b[i]], dp[i - 1][j][k] + c[i]);
        } else {
          dp[i][j + a[i]][k + b[i]] = dp[i - 1][j][k] + c[i];
        }
        if (dp[i][j][k] != 0) {
          dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
        } else
          dp[i][j][k] = dp[i - 1][j][k];
      }
    }
  }

  // int pos=n;
  // for(int k=1;k<n*10+1;k++){
  // 	for(int j=1;j<n*10+1;j++){
  // 		if(dp[pos][k][j]==INF)cout<<"+ ";
  // 		else cout<<dp[pos][k][j]<<" ";
  // 	}
  // 	cout<<endl;
  // }
  int ans = INF;
  for (int j = 1; j < 500; j++) {
    for (int k = 1; k < 500; k++) {
      if (dp[n][j][k] != 0 && j / gcd(j, k) == ma && k / gcd(j, k) == mb) {
        ans = min(ans, dp[n][j][k] - 1);
      }
    }
  }
  if (ans == INF)
    fin(-1);
  else
    fin(ans);
}
