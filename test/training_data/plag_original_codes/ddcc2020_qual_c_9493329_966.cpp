/*
引用元：https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_c
C - Strawberry Cakes
Time Limit : 2 sec / Memory Limit : 1024 MB
配点: 400 点
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

  int h, w, k;
  cin >> h >> w >> k;

  vector<string> s(h);
  vvi v(h, vi(w, 0));
  rep(i, h) cin >> s[i];
  int num = 1;
  for (int i = 0; i < h; i++) {
    rep(j, w) {
      if (s[i][j] == '#') {
        v[i][j] = num;
        num++;
      }
    }
  }

  for (int i = 1; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!v[i][j]) {
        v[i][j] = v[i - 1][j];
      }
    }
  }
  for (int i = h - 2; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      if (!v[i][j]) {
        v[i][j] = v[i + 1][j];
      }
    }
  }

  for (int i = 1; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (!v[j][i]) {
        v[j][i] = v[j][i - 1];
      }
    }
  }
  for (int i = w - 2; i >= 0; i--) {
    for (int j = 0; j < h; j++) {
      if (!v[j][i]) {
        v[j][i] = v[j][i + 1];
      }
    }
  }

  rep(i, h) {
    rep(j, w) {
      if (j == 0)
        cout << v[i][0];
      else
        cout << " " << v[i][j];
    }
    cout << endl;
  }
}
