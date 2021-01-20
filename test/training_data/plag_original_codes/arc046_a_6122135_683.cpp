/*
引用元：https://atcoder.jp/contests/arc046/tasks/arc046_a
A - ゾロ目数Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc046/submissions/6122135
// 提出ID : 6122135
// 問題ID : arc046_a
// コンテストID : arc046
// ユーザID : xryuseix
// コード長 : 1719
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
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
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

  int n;
  cin >> n;
  vi v;
  rep(i, 9) v.push_back(i + 1);
  for (int i = 11; i <= 99; i += 11)
    v.push_back(i);
  for (int i = 111; i <= 999; i += 111)
    v.push_back(i);
  for (int i = 1111; i <= 9999; i += 1111)
    v.push_back(i);
  for (int i = 11111; i <= 99999; i += 11111)
    v.push_back(i);
  for (int i = 111111; i <= 999999; i += 111111)
    v.push_back(i);
  cout << v[n - 1] << endl;
  //////////////////////////////////////////////////////
  return 0;
}
