/*
引用元：https://atcoder.jp/contests/cf17-final/tasks/cf17_final_a
A - AKIBAEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cf17-final/submissions/5868399
// 提出ID : 5868399
// 問題ID : cf17_final_a
// コンテストID : cf17-final
// ユーザID : xryuseix
// コード長 : 1767
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
#define STI(s) atoi(s.c_str()) // string to int
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
//|\_
// g++ -std=c++1z temp.cpp
//./a.out

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  string s, kib = "";
  int i, j;
  cin >> s;
  rep(i, s.length()) if (s[i] != 'A') kib += s[i];
  if (kib != "KIHBR") {
    fin("NO");
    return 0;
  } else {
    rep(i, s.length() - 1) if (s[i] == s[i + 1] && s[i] == 'A') {
      fin("NO");
      return 0;
    }
    rep(i, s.length()) {
      if (s[i] == 'K' && s[i + 1] != 'I') {
        fin("NO");
        return 0;
      }
      if (s[i] == 'I' && s[i + 1] != 'H') {
        fin("NO");
        return 0;
      }
    }
    fin("YES");
  }
  //////////////////////////////////////////////////////
  return 0;
}
