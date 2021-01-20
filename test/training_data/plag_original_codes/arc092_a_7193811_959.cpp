/*
引用元：https://atcoder.jp/contests/arc092/tasks/arc092_a
C - 2D Plane 2N PointsEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc092/submissions/7193811
// 提出ID : 7193811
// 問題ID : arc092_a
// コンテストID : arc092
// ユーザID : xryuseix
// コード長 : 2256
// 実行時間 : 1



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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int n;
  cin >> n;
  vector<pair<int, int>> r(n), b(n);
  int c, d;
  rep(i, n) {
    cin >> c >> d;
    r[i] = mp(c, d);
  }
  rep(i, n) {
    cin >> c >> d;
    b[i] = mp(c, d);
  }
  int ans = 0;
  Rort(r);
  Sort(b);
  for (int i = 0; i < n; i++) {
    ll ymax = -1, chpos = -1;
    for (int j = 0; j < n; j++) {
      if (r[j].first < b[i].first && r[j].second < b[i].second) {
        if (ymax < r[j].second) {
          ymax = r[j].second;
          chpos = j;
        }
      }
    }
    if (ymax == -1)
      continue;
    else {
      r[chpos].first = INF;
      r[chpos].second = INF;
      ans++;
    }
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
