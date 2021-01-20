/*
引用元：https://atcoder.jp/contests/abc039/tasks/abc039_d
D - 画像処理高橋君Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/abc039/submissions/12503069
// 提出ID : 12503069
// 問題ID : abc039_d
// コンテストID : abc039
// ユーザID : xryuseix
// コード長 : 3300
// 実行時間 : 3



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
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {

  int h, w;
  cin >> h >> w;
  vs v(h);
  vs ans(h), ans2;
  rep(i, h) cin >> v[i];
  rep(i, h) {
    rep(j, w) {
      int ch = 1;
      rep(k, 8) {
        int nx = dx[k] + j;
        int ny = dy[k] + i;
        if (nx < 0 || ny < 0 || nx >= v[0].size() || ny >= v.size())
          continue;
        if (v[ny][nx] == '.')
          ch = 0;
      }
      if (ch && v[i][j] == '#')
        ans[i] += '#';
      else
        ans[i] += '.';
    }
  }
  ans2 = ans;
  rep(i, h) {
    rep(j, w) {
      if (ans[i][j] == '.')
        continue;
      rep(k, 8) {
        int nx = dx[k] + j;
        int ny = dy[k] + i;
        if (nx < 0 || ny < 0 || nx >= v[0].size() || ny >= v.size())
          continue;
        ans2[ny][nx] = '#';
      }
    }
  }
  if (v == ans2) {
    fin("possible");
    rep(i, h) fin(ans[i]);
  } else {
    fin("impossible");
  }
}
