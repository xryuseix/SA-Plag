/*
引用元：https://atcoder.jp/contests/abc058/tasks/arc071_a
C - Dubious DocumentEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc058/submissions/5539072
// 提出ID : 5539072
// 問題ID : arc071_a
// コンテストID : abc058
// ユーザID : xryuseix
// コード長 : 1491
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

  int n;
  cin >> n;

  int alpha[n][26] = {0};
  int i, j;
  string s;
  rep(i, n) {
    cin >> s;
    rep(j, s.length()) { alpha[i][s[j] - 'a']++; }
  }
  int ans = 0, tmp;
  string anss = "";
  for (i = 0; i < 26; i++) {
    tmp = INF;
    for (j = 0; j < n; j++) {
      tmp = min(tmp, alpha[j][i]);
    }
    rep(j, tmp) anss += 'a' + i;
  }
  fin(anss);

  //////////////////////////////////////////////////////
  return 0;
}
