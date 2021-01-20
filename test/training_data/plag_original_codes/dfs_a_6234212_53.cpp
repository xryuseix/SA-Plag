/*
引用元：https://atcoder.jp/contests/atc001/tasks/dfs_a
A - 深さ優先探索Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/atc001/submissions/6234212
// 提出ID : 6234212
// 問題ID : dfs_a
// コンテストID : atc001
// ユーザID : xryuseix
// コード長 : 2499
// 実行時間 : 11



*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <bitset>
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
#define P 1000000007
#define STI(s) atoi(s.c_str()) // string to int
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define Sort(a) sort(a.begin(), a.end())
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
const int INF = INT_MAX;
const long long LLINF = 1LL << 60;
// g++ -std=c++1z temp.cpp
//./a.out
int h, w;
int s_x, s_y, g_x, g_y;
vvi v(510, vi(510, INF));
vs grid(510);
bool goal = false;
int ans = 0;
int dfs(int x, int y, int depth) {
  if (goal)
    return 0;
  if (x == g_x && y == g_y) {
    goal = true;
    ans = depth;
    return 0;
  }
  grid[y][x] = '&';

  // cout<<x<<" "<<y<<endl;

  if (x + 1 < w && (grid[y][x + 1] == 'g' || grid[y][x + 1] == '.'))
    dfs(x + 1, y, depth + 1);
  if (x - 1 >= 0 && (grid[y][x - 1] == 'g' || grid[y][x - 1] == '.'))
    dfs(x - 1, y, depth + 1);
  if (y + 1 < h && (grid[y + 1][x] == 'g' || grid[y + 1][x] == '.'))
    dfs(x, y + 1, depth + 1);
  if (y - 1 >= 0 && (grid[y - 1][x] == 'g' || grid[y - 1][x] == '.'))
    dfs(x, y - 1, depth + 1);
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  cin >> h >> w;
  rep(i, h) cin >> grid[i];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == 's') {
        s_x = j;
        s_y = i;
      }
      if (grid[i][j] == 'g') {
        g_x = j;
        g_y = i;
      }
    }
  }
  int d = dfs(s_x, s_y, 0);

  if (ans > 0) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;

  //////////////////////////////////////////////////////
  return 0;
}
