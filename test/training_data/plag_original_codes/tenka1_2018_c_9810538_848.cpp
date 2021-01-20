/*
引用元：https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c
C - Align
Time Limit : 2 sec / Memory Limit : 1024 MB
配点 : 400 点
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

  int n;
  cin >> n;
  if (n < 8) {
    vi v(n), res;
    int m = 0;
    rep(i, n) cin >> v[i];
    Sort(v);
    do {
      int diff = 0;
      rep(i, n - 1) { diff += abs(v[i] - v[i + 1]); }
      if (diff > m) {
        m = diff;
        res.clear();
        rep(i, n) { res.pb(v[i]); }
      }
    } while (next_permutation(all(v)));
    fin(m);
  } else {
    ll p1 = 0, p2 = 0;
    vi v(n);
    rep(i, n) cin >> v[i];
    Sort(v);
    if (n % 2 == 1) {
      rep(i, n / 2) p1 -= 2 * v[i];
      for (int i = n / 2; i < n / 2 + 2; i++)
        p1 += v[i];
      for (int i = n / 2 + 2; i < n; i++)
        p1 += 2 * v[i];

      rep(i, n / 2 - 1) p2 -= 2 * v[i];
      for (int i = n / 2 - 1; i < n / 2 + 1; i++)
        p2 -= v[i];
      for (int i = n / 2 + 1; i < n; i++)
        p2 += 2 * v[i];
    } else {
      p1 += v[n / 2] - v[n / 2 - 1];
      rep(i, n / 2 - 1) p1 -= 2 * v[i];
      for (int i = n / 2 + 1; i < n; i++)
        p1 += 2 * v[i];
    }
    fin(max(p1, p2));
  }
}
