/*
引用元：https://atcoder.jp/contests/diverta2019/tasks/diverta2019_c
C - AB SubstringsEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/diverta2019/submissions/5355469
// 提出ID : 5355469
// 問題ID : diverta2019_c
// コンテストID : diverta2019
// ユーザID : xryuseix
// コード長 : 1584
// 実行時間 : 3



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

  int i, n;
  string s;
  int ans = 0;
  cin >> n;
  int lasta = 0, firstb = 0, doubleab = 0;
  rep(i, n) {
    cin >> s;
    while (s.find("AB") != string::npos) {
      s.replace(s.find("AB"), 2, "a");
      ans++;
    }
    // cout<<s<<endl;
    if (s[0] == 'B' && s[s.length() - 1] == 'A')
      doubleab++;
    else if (s[s.length() - 1] == 'A')
      lasta++;
    else if (s[0] == 'B')
      firstb++;
  }
  if (doubleab > 1) {
    ans += doubleab - 1;
    doubleab = 1;
  }
  if (lasta > 0 && doubleab == 1) {
    ans++;
    lasta--;
  }
  if (firstb > 0 && doubleab == 1) {
    ans++;
    firstb--;
  }
  cout << ans + min(lasta, firstb) << endl;

  //////////////////////////////////////////////////////
  return 0;
}
