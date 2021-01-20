/*
引用元：https://atcoder.jp/contests/abc005/tasks/abc005_3
C - おいしいたこ焼きの売り方Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc005/submissions/4643428
// 提出ID : 4643428
// 問題ID : abc005_3
// コンテストID : abc005
// ユーザID : xryuseix
// コード長 : 1436
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
#define ld long double
//#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX;
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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int i, j, t, m, n, tmp, per = -1;
  cin >> t >> n;
  queue<int> a, b;
  rep(i, n) {
    cin >> tmp;
    a.push(tmp);
  }
  cin >> m;
  rep(i, m) {
    cin >> tmp;
    b.push(tmp);
  }
  bool ch = true;
  for (i = 0; i < m; i++) {
    per = b.front();
    b.pop();
    if (a.size() == 0)
      ch = false;
    //		cout<<endl<<"per:"<<per<<endl;
    while (a.size() > 0) {
      tmp = a.front();
      a.pop();
      //			cout<<"tmp:"<<tmp<<endl;
      if (per - tmp <= t && per - tmp >= 0)
        break;
      else if (a.size() == 0) {
        ch = false;
      }
    }
  }
  if (ch)
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  //////////////////////////////////////////////////////
  return 0;
}
