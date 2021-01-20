/*
引用元：https://atcoder.jp/contests/abc068/tasks/arc079_a
C - Cat Snuke and a VoyageEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc068/submissions/5547130
// 提出ID : 5547130
// 問題ID : arc079_a
// コンテストID : abc068
// ユーザID : xryuseix
// コード長 : 1499
// 実行時間 : 111



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
#include <bits/stdc++.h>
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define P 1000000007
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

  set<int> s, t;
  int i, n, m, a, b;
  cin >> n >> m;
  rep(i, m) {
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    if (a == 1)
      s.insert(b);
    if (b == n)
      t.insert(a);
  }
  bool ch = false;

  set<int>::iterator it;
  for (it = t.begin(); it != t.end(); it++) {
    if (s.find(*it) != s.end()) {
      ch = true;
      break;
    }
  }

  if (ch)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;

  //////////////////////////////////////////////////////
  return 0;
}
