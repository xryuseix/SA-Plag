/*
引用元：https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_c
C - Infinite GridEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/s8pc-6/submissions/5027744
// 提出ID : 5027744
// 問題ID : s8pc_6_c
// コンテストID : s8pc-6
// ユーザID : xryuseix
// コード長 : 2015
// 実行時間 : 75



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
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
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
const long long LLINF = 1LL << 60;
// set<int>::iterator it;

bool up = false, down = false;
int ddfs(vector<vector<char>> v, int x, int y, int border) {
  //	cout<<x<<" "<<v[x][y]<<endl;
  if (v[x][y] == '%' || v[x][y] == '#' || down)
    return 0;
  if (x == border) {
    down = true;
    return 0;
  }
  ddfs(v, x + 1, y, border);
  ddfs(v, x, y + 1, border);
}
int udfs(vector<vector<char>> v, int x, int y, int border) {
  if (v[x][y] == '%' || v[x][y] == '#' || up)
    return 0;
  if (x == border) {
    up = true;
    return 0;
  }
  udfs(v, x - 1, y, border);
  udfs(v, x, y - 1, border);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int h, w, i, j, border;
  cin >> h >> w;
  bool yoko = false, ch = false;
  string t, s = "";
  vector<vector<char>> v(h + 2, vector<char>(w + 2, '%'));
  rep(i, w) s += '.';
  rep(i, h) {
    cin >> t;
    if (s == t) {
      ch = true;
      border = i + 1;
    }
    rep(j, w) v[i + 1][j + 1] = t[j];
  }

  //	rep(i,h+2){
  //		rep(j,w+2){
  //			cout<<v[i][j];
  //		}
  //		cout<<endl;
  //	}
  //	cout<<"border"<<border<<endl;
  //横一列に並んだ.まで、右上から、さらに右下からたどり着けるか
  if (!ch) {
    cout << ":(" << endl;
    return 0;
  }
  //	cout<<"aaa"<<endl;
  ddfs(v, 1, 1, border);

  //	cout<<"aaa"<<endl;
  udfs(v, h, w, border);

  if (up && down)
    cout << "Yay!" << endl;
  else
    cout << ":(" << endl;

  //////////////////////////////////////////////////////
  return 0;
}
