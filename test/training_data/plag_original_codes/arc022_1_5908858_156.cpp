/*
引用元：https://atcoder.jp/contests/arc022/tasks/arc022_1
A - スーパーICT高校生Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc022/submissions/5908858
// 提出ID : 5908858
// 問題ID : arc022_1
// コンテストID : arc022
// ユーザID : xryuseix
// コード長 : 1698
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
#define mp(p, q) make_pair(p, q)
#define Sort(a) sort(a.begin(), a.end())
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
  string s, t = "";
  int i;
  cin >> s;
  rep(i, s.length()) {
    s[i] = tolower(s[i]);
    if (s[i] == 'i' || s[i] == 'c' || s[i] == 't')
      t += s[i];
  }
  char ict[4] = {'i', 'c', 't', '#'};
  int phase = 0;
  bool ch = false;
  rep(i, t.size()) {
    if (t[i] == ict[phase]) {
      phase++;
      if (phase == 3)
        ch = true;
    }
    if (ch)
      break;
  }
  if (ch)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  //////////////////////////////////////////////////////
  return 0;
}
