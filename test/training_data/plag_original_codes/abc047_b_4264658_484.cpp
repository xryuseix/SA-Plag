/*
引用元：https://atcoder.jp/contests/abc047/tasks/abc047_b
B - Snuke's Coloring 2 (ABC Edit)Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc047/submissions/4264658
// 提出ID : 4264658
// 問題ID : abc047_b
// コンテストID : abc047
// ユーザID : xryuseix
// コード長 : 1506
// 実行時間 : 2



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

  int w, h, n, a, b, c, i, j, k;
  cin >> w >> h >> n;
  int m[h][w];
  for (j = 0; j < h; j++)
    for (k = 0; k < w; k++)
      m[j][k] = 0;
  for (i = 0; i < n; i++) {
    cin >> a >> b >> c;
    //		for(j=0;j<h;j++){
    //			for(k=0;k<w;k++){
    //				cout<<m[j][k]<<" ";
    //			}
    //			cout<<endl;
    //		}
    switch (c) {
    case 1:
      for (j = 0; j < h; j++) {
        for (k = 0; k < w; k++) {
          if (k < a)
            m[j][k] = 1;
        }
      }
      break;
    case 2:
      for (j = 0; j < h; j++) {
        for (k = 0; k < w; k++) {
          if (k >= a)
            m[j][k] = 1;
        }
      }
      break;
    case 3:
      for (j = 0; j < h; j++) {
        for (k = 0; k < w; k++) {
          if (j < b)
            m[j][k] = 1;
        }
      }
      break;
    case 4:
      for (j = 0; j < h; j++) {
        for (k = 0; k < w; k++) {
          if (j >= b)
            m[j][k] = 1;
        }
      }
      break;
    }
    //		for(j=0;j<h;j++){
    //			for(k=0;k<w;k++){
    //				cout<<m[j][k]<<" ";
    //			}
    //			cout<<endl;
    //		}
  }
  int s = 0;
  for (j = 0; j < h; j++) {
    for (k = 0; k < w; k++) {
      //			cout<<m[j][k]<<" ";
      s += m[j][k];
    }
    //		cout<<endl;
  }
  cout << w *h - s << endl;

  return 0;
}
