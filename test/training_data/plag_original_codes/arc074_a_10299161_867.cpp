/*
引用元：https://atcoder.jp/contests/arc074/tasks/arc074_a
C - Chocolate Bar
Time Limit : 2 sec / Memory Limit : 256 MB
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

  ll h, w;
  cin >> h >> w;
  ll ans = LLINF;
  for (int i = 0; i < w - 1; i++) {
    ll Sa = (i + 1) * h;
    ll hb = h / 2;
    ll hc = h - hb;
    ll Sb = hb * (w - (i + 1));
    ll Sc = hc * (w - (i + 1));
    ans = min(ans, max({Sa, Sb, Sc}) - min({Sa, Sb, Sc}));
    hb = (w - i - 1) / 2;
    hc = w - hb - (i + 1);
    Sb = hb * h;
    Sc = hc * h;
    ans = min(ans, max({Sa, Sb, Sc}) - min({Sa, Sb, Sc}));
    // cout<<i<<" "<<Sa<<" "<<Sb<<" "<<Sc<<endl;
  }
  for (int i = 0; i < h - 1; i++) {
    ll Sa = (i + 1) * w;
    ll hb = w / 2;
    ll hc = w - hb;
    ll Sb = hb * (h - (i + 1));
    ll Sc = hc * (h - (i + 1));
    ans = min(ans, max({Sa, Sb, Sc}) - min({Sa, Sb, Sc}));
    hb = (h - i - 1) / 2;
    hc = h - hb - (i + 1);
    Sb = hb * w;
    Sc = hc * w;
    ans = min(ans, max({Sa, Sb, Sc}) - min({Sa, Sb, Sc}));
    // cout<<i<<" "<<Sa<<" "<<Sb<<" "<<Sc<< " " <<hb<<" "<<hc<<endl;
  }
  fin(ans);
}
