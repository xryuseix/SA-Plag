/*
引用元：https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b
B - Counting of TreesEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/nikkei2019-2-qual/submissions/8355222
// 提出ID : 8355222
// 問題ID : nikkei2019_2_qual_b
// コンテストID : nikkei2019-2-qual
// ユーザID : xryuseix
// コード長 : 2312
// 実行時間 : 32



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
  };
};
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

int main(void) {

  int n;
  cin >> n;
  int mod = 998244353;
  vll d(n);
  rep(i, n) cin >> d[i];
  ll maxd = 0;
  for (int i = 0; i < n; i++)
    maxd = max(maxd, d[i]);
  vll distance(maxd + 1, 0);
  for (int i = 0; i < n; i++) {
    distance[d[i]]++;
  }

  ll ans = 1;
  if (d[0] != 0 || distance[0] != 1) {
    fin(0);
    return 0;
  }
  for (int i = 1; i < maxd; i++) {
    ans *= mod_pow(distance[i], distance[i + 1], mod);
    ans %= mod;
  }
  fin(ans);
  // rep(i,distance.size()){
  //     cout<<distance[i]<<endl;
  // }
}
