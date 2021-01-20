/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_h
H - Grid 1Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6221550
// 提出ID : 6221550
// 問題ID : dp_h
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 2238
// 実行時間 : 19



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
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  int h, w;
  cin >> h >> w;
  char grid[h][w];
  int path[h][w];
  rep(i, h) rep(j, w) cin >> grid[i][j];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      path[i][j] = 0;
    }
  }
  for (int i = 0; i < w; i++) {
    if (grid[0][i] == '.')
      path[0][i] = 1;
    else
      break;
  }
  for (int i = 0; i < h; i++) {
    if (grid[i][0] == '.')
      path[i][0] = 1;
    else
      break;
  }
  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      if (grid[i][j] == '#')
        path[i][j] = 0;
      else {
        path[i][j] = max(path[i][j], path[i - 1][j] + path[i][j - 1]);
        path[i][j] %= P;
      }
    }
  }
  cout << path[h - 1][w - 1] << endl;
  /*
  for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
          cout<<path[i][j]<<" ";
      }
      cout<<endl;
  }*/

  //////////////////////////////////////////////////////
  return 0;
}
