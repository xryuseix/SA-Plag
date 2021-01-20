/*
引用元：https://atcoder.jp/contests/abc075/tasks/abc075_b
B - MinesweeperEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/abc075/submissions/10336111
// 提出ID : 10336111
// 問題ID : abc075_b
// コンテストID : abc075
// ユーザID : xryuseix
// コード長 : 2323
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

  int h, w;
  cin >> h >> w;
  vvi ans(h, vi(w, 0));
  vs s(h);
  rep(i, h) cin >> s[i];
  rep(i, h) rep(j, w) {
    // cout<<i<<" "<<j<<endl;
    if (s[i][j] != '#')
      continue;
    rep(k, 8) {
      if (j + dx[k] < 0 || j + dx[k] >= w || i + dy[k] < 0 || i + dy[k] >= h)
        continue;
      else {
        ans[i + dy[k]][j + dx[k]]++;
      }
    }
  }
  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#')
        cout << '#';
      else
        cout << ans[i][j];
    }
    cout << endl;
  }
}
