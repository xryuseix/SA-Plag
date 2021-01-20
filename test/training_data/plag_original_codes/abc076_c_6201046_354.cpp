/*
引用元：https://atcoder.jp/contests/abc076/tasks/abc076_c
C - Dubious Document 2Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc076/submissions/6201046
// 提出ID : 6201046
// 問題ID : abc076_c
// コンテストID : abc076
// ユーザID : xryuseix
// コード長 : 2033
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
#define pb(n) push_back(n)
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

bool ok = true;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  string s, t;
  cin >> s >> t;

  if (s.size() < t.size()) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  for (int i = s.length() - t.length(); i >= 0; i--) {
    ok = true;
    for (int j = 0; j < t.length(); j++) {
      if (s[i + j] == t[j] || s[i + j] == '?')
        continue;
      else
        ok = false;
    }
    if (ok) {
      for (int j = 0; j < t.length(); j++) {
        s[i + j] = t[j];
      }
      break;
    }
  }
  if (!ok) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  rep(i, s.size()) {
    if (s[i] == '?')
      s[i] = 'a';
  }
  cout << s << endl;
  //////////////////////////////////////////////////////
  return 0;
}
