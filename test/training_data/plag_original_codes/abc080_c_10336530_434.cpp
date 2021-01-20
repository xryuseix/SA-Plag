/*
引用元：https://atcoder.jp/contests/abc080/tasks/abc080_c
C - Shopping StreetEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/abc080/submissions/10336530
// 提出ID : 10336530
// 問題ID : abc080_c
// コンテストID : abc080
// ユーザID : xryuseix
// コード長 : 2422
// 実行時間 : 4



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

int main(void) {

  ll n;
  cin >> n;
  vvll v(n, vll(10));
  rep(i, n) rep(j, 10) cin >> v[i][j];
  vvll p(n, vll(11));
  rep(i, n) rep(j, 11) cin >> p[i][j];
  ll ans = -LLINF;
  for (ll i = 1; i < (1 << 10); i++) {
    vll open(10, 0);
    ll t = i;
    ll pos = 0;
    while (t > 0) {
      open[pos] = t % 2;
      t /= 2;
      pos++;
    }
    ll tmp = 0;
    for (ll j = 0; j < n; j++) {
      ll itti = 0;
      rep(k, 10) {
        if (v[j][k] == open[k] && open[k] == 1) {
          itti++;
        }
      }
      tmp += p[j][itti];
    }
    chmax(ans, tmp);
  }
  fin(ans);
}
