/*
引用元：https://atcoder.jp/contests/abc058/tasks/arc071_b
D - ###Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc058/submissions/8502862
// 提出ID : 8502862
// 問題ID : arc071_b
// コンテストID : abc058
// ユーザID : xryuseix
// コード長 : 2107
// 実行時間 : 89



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
const ll MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int main(void) {

  ll n, m;
  cin >> n >> m;
  vll x(n), y(m);
  rep(i, n) cin >> x[i];
  rep(i, m) cin >> y[i];
  ll xans = 0;

  for (int i = 1; i <= n; i++) {
    ll a = (i - 1) * x[i - 1] % MOD;
    ll b = (n - i) * x[i - 1] % MOD;
    xans += (a - b + MOD) % MOD;
    xans %= MOD;
    //        cout<<i<<" "<<xans<<endl;
  }
  ll yans = 0;

  for (int i = 1; i <= m; i++) {
    ll a = (i - 1) * y[i - 1] % MOD;
    ll b = (m - i) * y[i - 1] % MOD;
    yans += (a - b + MOD) % MOD;
    yans %= MOD;
  }
  // cout<<xans<<" "<<yans<<endl;
  cout << xans *yans % MOD << endl;
}
