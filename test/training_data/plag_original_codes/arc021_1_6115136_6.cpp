/*
引用元：https://atcoder.jp/contests/arc021/tasks/arc021_1
A - DEAD ENDEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc021/submissions/6115136
// 提出ID : 6115136
// 問題ID : arc021_1
// コンテストID : arc021
// ユーザID : xryuseix
// コード長 : 1654
// 実行時間 : 1



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
#define fin(ans) cout << (ans) << endl
#define P 1000000007
#define STI(s) atoi(s.c_str()) // string to int
#define mp(p, q) make_pair(p, q)
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

  vvi v(4, vector<int>(4));
  rep(i, 4) rep(j, 4) cin >> v[i][j];
  bool ch = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (v[i][j] == v[i][j + 1])
        ch = true;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      if (v[i][j] == v[i + 1][j])
        ch = true;
    }
  }

  if (ch)
    fin("CONTINUE");
  else
    fin("GAMEOVER");
  //////////////////////////////////////////////////////
  return 0;
}
