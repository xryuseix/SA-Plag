/*
引用元：https://atcoder.jp/contests/abc010/tasks/abc010_3
C - 浮気調査Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc010/submissions/7811880
// 提出ID : 7811880
// 問題ID : abc010_3
// コンテストID : abc010
// ユーザID : xryuseix
// コード長 : 2001
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

double dis(int xa, int ya, int xb, int yb) {
  return sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int txa, tya, txb, tyb, t, v, n;
  cin >> txa >> tya >> txb >> tyb >> t >> v >> n;
  int move = t * v;
  bool ch = false;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    double yoru = dis(x, y, txa, tya) + dis(x, y, txb, tyb);
    if (yoru <= move) {
      ch = true;
    }
  }
  if (ch)
    fin("YES");
  else
    fin("NO");

  //////////////////////////////////////////////////////
  return 0;
}
