/*
引用元：https://atcoder.jp/contests/abc042/tasks/arc058_b
D - Iroha and a GridEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc042/submissions/7425458
// 提出ID : 7425458
// 問題ID : arc058_b
// コンテストID : abc042
// ユーザID : xryuseix
// コード長 : 2591
// 実行時間 : 67



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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

vll memokai(200010, -1);

ll kai(ll n) {
  if (memokai[n] != -1)
    return memokai[n];
  else
    memokai[n] = kai(n - 1) * n % P;
  return memokai[n];
}

ll modinv(ll a) {
  ll b = P, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= P;
  if (u < 0)
    u += P;
  return u;
}

int root(pair<int, int> s, pair<int, int> g) {
  //圧縮
  int t = min(s.first, g.first);
  s.first -= t;
  g.first -= t;
  t = min(s.second, g.second);
  s.second -= t;
  g.second -= t;
  ll a = kai(g.second + g.first);
  a %= P;
  // cout<<a<<endl;
  ll b = kai(g.first) * kai(g.second) % P;
  ll res = a * modinv(b) % P;
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  ll ans = 0;
  memokai[0] = 1;
  memokai[1] = 1;
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  for (int i = 0; i < w - b; i++) {
    ll up = root(mp(0, 0), mp(h - a - 1, b + i));
    ll down = root(mp(h - a, b + i), mp(h - 1, w - 1));
    ans += up * down % P;
    // cout<<up<<" "<<down<<endl;
    ans %= P;
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
