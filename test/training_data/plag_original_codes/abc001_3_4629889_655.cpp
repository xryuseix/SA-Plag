/*
引用元：https://atcoder.jp/contests/abc001/tasks/abc001_3
C - 風力観測Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc001/submissions/4629889
// 提出ID : 4629889
// 問題ID : abc001_3
// コンテストID : abc001
// ユーザID : xryuseix
// コード長 : 2040
// 実行時間 : 4



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

  vector<pair<string, double>> v;
  double wind[13] = {0.2,  1.5,  3.3,  5.4,  7.9,  10.7,  13.8,
                     17.1, 20.7, 24.4, 28.4, 32.6, 100000};
  v.push_back(make_pair("N", 11.25));
  v.push_back(make_pair("NNE", 33.75));
  v.push_back(make_pair("NE", 56.25));
  v.push_back(make_pair("ENE", 78.75));
  v.push_back(make_pair("E", 101.25));
  v.push_back(make_pair("ESE", 123.75));
  v.push_back(make_pair("SE", 146.25));
  v.push_back(make_pair("SSE", 168.75));
  v.push_back(make_pair("S", 191.25));
  v.push_back(make_pair("SSW", 213.75));
  v.push_back(make_pair("SW", 236.25));
  v.push_back(make_pair("WSW", 258.75));
  v.push_back(make_pair("W", 281.25));
  v.push_back(make_pair("WNW", 303.75));
  v.push_back(make_pair("NW", 326.25));
  v.push_back(make_pair("NNW", 348.75));
  v.push_back(make_pair("N", 361.00));

  double deg, dis;
  cin >> deg >> dis;
  deg /= 10;
  dis /= 60;
  int i, j;
  dis *= 10;
  dis += 0.5;
  dis = floor(dis);
  dis /= 10;
  for (i = 0; i < 13; i++) {
    if (dis <= wind[i])
      break;
  }
  if (i == 0) {
    cout << "C"
         << " " << 0 << endl;
    return 0;
  } else {
    for (j = 0; j < v.size(); j++) {
      //			cout<<deg<<" "<<v[j].second<<endl;
      if (v[j].second > deg) {
        cout << v[j].first << " " << i << endl;
        return 0;
      }
    }
  }

  //////////////////////////////////////////////////////
  return 0;
}
