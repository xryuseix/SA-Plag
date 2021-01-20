/*
引用元：https://atcoder.jp/contests/cpsco2019-s4/tasks/cpsco2019_s4_b
B - MeetingEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cpsco2019-s4/submissions/5491458
// 提出ID : 5491458
// 問題ID : cpsco2019_s4_b
// コンテストID : cpsco2019-s4
// ユーザID : xryuseix
// コード長 : 1428
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

  int i, n, d;
  cin >> n >> d;
  string s[d];
  rep(i, d) cin >> s[i];
  int j, ans = 0, k, t;

  for (i = 0; i < d - 1; i++) {
    for (j = i + 1; j < d; j++) {
      t = 0;
      for (k = 0; k < s[i].length(); k++) {
        if (s[i][k] == 'o' || s[j][k] == 'o')
          t++;
      }

      ans = max(ans, t);
    }
  }

  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
