/*
引用元：https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_h
H - パ研王国を守れ！Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/pakencamp-2019-day3/submissions/9139024
// 提出ID : 9139024
// 問題ID : pakencamp_2019_day3_h
// コンテストID : pakencamp-2019-day3
// ユーザID : xryuseix
// コード長 : 2329
// 実行時間 : 2



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

  int n, m;
  cin >> n >> m;
  vs v(n);
  rep(i, n) cin >> v[i];
  rep(i, n) rep(j, n) {
    if (v[i][j] == 'Q') {
      int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
      int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
      for (int k = 0; k < 8; k++) {
        int X = j + dx[k], Y = i + dy[k];
        while (X >= 0 && X < n && Y >= 0 && Y < n) {
          if (v[Y][X] == '#' || v[Y][X] == 'Q')
            break;
          if (v[Y][X] == 'X' && v[i + dy[k]][j + dx[k]] == '.') {
            v[i + dy[k]][j + dx[k]] = '#';
            break;
          }
          X += dx[k];
          Y += dy[k];
        }
      }
    }
  }
  rep(i, n) { cout << v[i] << endl; }
}
