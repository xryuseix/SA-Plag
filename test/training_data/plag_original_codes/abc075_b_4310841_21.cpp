/*
引用元：https://atcoder.jp/contests/abc075/tasks/abc075_b
B - MinesweeperEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc075/submissions/4310841
// 提出ID : 4310841
// 問題ID : abc075_b
// コンテストID : abc075
// ユーザID : xryuseix
// コード長 : 1654
// 実行時間 : 1



*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <cctype>
#define ld long double
#define ll long long int
#define ull unsigned long long int
using namespace std;
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
const long long INF = 1LL << 60;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int i, j, h, w;
  cin >> h >> w;
  char m[h + 2][w + 2];
  for (i = 0; i < h + 2; i++)
    for (j = 0; j < w + 2; j++)
      m[i][j] = '.';
  for (i = 1; i < h + 1; i++)
    for (j = 1; j < w + 1; j++)
      cin >> m[i][j];
  for (i = 1; i < h + 1; i++)
    for (j = 1; j < w + 1; j++) {
      if (m[i][j] == '#') {
        if (m[i - 1][j - 1] != '#') {
          if (m[i - 1][j - 1] == '.')
            m[i - 1][j - 1] = '1';
          else
            m[i - 1][j - 1]++;
        }
        if (m[i - 1][j + 1] != '#') {
          if (m[i - 1][j + 1] == '.')
            m[i - 1][j + 1] = '1';
          else
            m[i - 1][j + 1]++;
        }
        if (m[i - 1][j] != '#') {
          if (m[i - 1][j] == '.')
            m[i - 1][j] = '1';
          else
            m[i - 1][j]++;
        }
        if (m[i][j + 1] != '#') {
          if (m[i][j + 1] == '.')
            m[i][j + 1] = '1';
          else
            m[i][j + 1]++;
        }
        if (m[i][j - 1] != '#') {
          if (m[i][j - 1] == '.')
            m[i][j - 1] = '1';
          else
            m[i][j - 1]++;
        }
        if (m[i + 1][j - 1] != '#') {
          if (m[i + 1][j - 1] == '.')
            m[i + 1][j - 1] = '1';
          else
            m[i + 1][j - 1]++;
        }
        if (m[i + 1][j] != '#') {
          if (m[i + 1][j] == '.')
            m[i + 1][j] = '1';
          else
            m[i + 1][j]++;
        }
        if (m[i + 1][j + 1] != '#') {
          if (m[i + 1][j + 1] == '.')
            m[i + 1][j + 1] = '1';
          else
            m[i + 1][j + 1]++;
        }
      }
    }
  for (i = 1; i < h + 1; i++) {
    for (j = 1; j < w + 1; j++) {
      if (m[i][j] == '.')
        cout << 0;
      else
        cout << m[i][j];
    }
    cout << endl;
  }

  return 0;
}
