/*
引用元：https://atcoder.jp/contests/abc029/tasks/abc029_d
D - 1
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

// int dp[12][2];

int main(void) {

  // dp[0][0]=0;
  // string s;
  // cin>>s;
  // int n=s.size();
  // rep(i,n)rep(k,2){
  //     rep(j,10){
  //         int ni=i + 1, nk=k;
  //         int t=0;
  //         if(k==0){
  //             if(j > s[i] - '0') continue;
  //             if(j < s[i] - '0') {
  //                 nk=1;
  //             }
  //         }
  //         if(j==1)t++;
  //         dp[ni][nk] += dp[i][k]+t;
  //     }
  // }
  // ll ans=dp[n][0]+dp[n][1];
  // fin(ans);
  // int D=1;
  // fin(dp[D][0]+dp[D][1]);
  // D=2;
  // fin(dp[D][0]+dp[D][1]);
  int n;
  scanf("%d", &n);
  int ans = 0, t, tans;
  for (int i = 0; i <= n; ++i) {
    if (i + 100 <= n) {
      t = i / 100;
      tans = 0;
      while (t > 0) {
        if (t % 10 == 1)
          tans++;
        t /= 10;
      }
      ans += 100 * tans + 20;
      i += 99;
    } else if (i + 10 <= n) {
      t = i / 10;
      tans = 0;
      while (t > 0) {
        if (t % 10 == 1)
          tans++;
        t /= 10;
      }
      ans += 10 * tans + 1;
      i += 9;
    } else {
      t = i / 10;
      tans = 0;
      while (t > 0) {
        if (t % 10 == 1)
          tans++;
        t /= 10;
      }
      ans += tans + ((i % 10 == 1) ? 1 : 0);
    }
    // cout<<i<<" "<<ans<<endl;
  }
  fin(ans);
}
