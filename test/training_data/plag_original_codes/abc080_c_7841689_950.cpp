/*
引用元：https://atcoder.jp/contests/abc080/tasks/abc080_c
C - Shopping StreetEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc080/submissions/7841689
// 提出ID : 7841689
// 問題ID : abc080_c
// コンテストID : abc080
// ユーザID : xryuseix
// コード長 : 2665
// 実行時間 : 9


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
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  };
};
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {

  int n;
  cin >> n;
  vvi f(n, vi(10));
  vvi p(n, vi(11));
  rep(i, n) rep(j, 10) cin >> f[i][j];
  rep(i, n) rep(j, 11) cin >> p[i][j];

  int bit = 1;
  ll ans = -INF;
  while (bit < pow(2, 10)) {
    ll tmpans = 0;
    int t = bit;
    vi open(10, 0);
    int pos = 0;
    while (t > 0) {
      open[pos] = t % 2;
      t /= 2;
      pos++;
    }
    for (int i = 0; i < n; i++) { //全ての店を舐める
      int match = 0;
      for (int j = 0; j < 10; j++) {
        if (f[i][j] == open[j] && f[i][j] == 1) {
          match++;
        }
      }
      tmpans += p[i][match];
    }

    ans = max(ans, tmpans);
    bit++;
  }

  fin(ans);
}
