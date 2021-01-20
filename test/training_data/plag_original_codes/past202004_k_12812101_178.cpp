/*
引用元：https://atcoder.jp/contests/past202004-open/tasks/past202004_k
K - ParenthesesEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past202004-open/submissions/12812101
// 提出ID : 12812101
// 問題ID : past202004_k
// コンテストID : past202004-open
// ユーザID : xryuseix
// コード長 : 3583
// 実行時間 : 119



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
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <random>
#include <iomanip>
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
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define arep(i, v) for (auto i : v)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
// #define endl '\n';
#define fi first
#define se second
#define NONVOID [[nodiscard]]
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
template <class T> inline void dump(T &v) {
  irep(i, v) { cout << *i << ((i == --v.end()) ? '\n' : ' '); }
}
inline string getline() {
  string s;
  getline(cin, s);
  return s;
}
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  }
};
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr double EPS = 1e-9;

int main() {

  int n, MX = 3010;
  string s;
  cin >> n >> s;
  vvll dp(s.size() + 1, vll(2 * MX, LLINF));
  vll c(n), d(n);
  rep(i, n) cin >> c[i];
  rep(i, n) cin >> d[i];

  int sum = 0;
  rep(i, n) {
    if (s[i] == ')')
      sum--;
    else
      sum++;
  }
  dp[0][MX] = 0;
  for (int i = 0; i < s.size(); i++) {
    rep(j, dp[i].size()) {
      if (dp[i][j] != LLINF) {
        if (s[i] == '(') {
          chmin(dp[i + 1][j + 1], dp[i][j]);
          if (j - 1 >= MX)
            chmin(dp[i + 1][j - 1], dp[i][j] + c[i]);
          if (j >= MX)
            chmin(dp[i + 1][j], dp[i][j] + d[i]);
        } else {
          if (j - 1 >= MX)
            chmin(dp[i + 1][j - 1], dp[i][j]);
          chmin(dp[i + 1][j + 1], dp[i][j] + c[i]);
          chmin(dp[i + 1][j], dp[i][j] + d[i]);
        }
      }
    }
  }
  // ll ans=LLINF;
  // for(int i=0;i<s.size()+1;i++){
  //     chmin(ans,dp[i][MX]);
  // }
  fin(dp[n][MX]);
  // rep(i,n+1){
  //     for(int j=MX-5; j<=MX+5; j++){
  //         if(dp[i][j]==LLINF)cout<<"INF ";
  //         else cout<<dp[i][j]<<" ";
  //     }
  //     cout<<endl;
  // }
}
