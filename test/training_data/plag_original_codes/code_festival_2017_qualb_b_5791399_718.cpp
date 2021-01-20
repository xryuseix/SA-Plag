/*
引用元：https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_b
B - Problem SetEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-festival-2017-qualb/submissions/5791399
// 提出ID : 5791399
// 問題ID : code_festival_2017_qualb_b
// コンテストID : code-festival-2017-qualb
// ユーザID : xryuseix
// コード長 : 1684
// 実行時間 : 67



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
  int n, i, m, j;
  cin >> n;
  vector<int> d(n, 0);
  rep(i, n) cin >> d[i];
  cin >> m;
  vi t(m, 0);
  rep(i, m) cin >> t[i];
  sort(d.begin(), d.end());
  sort(t.begin(), t.end());

  bool ch = false;
  for (i = 0, j = 0; i < n && j < m;) {
    if (d[i] == t[j]) {
      if (j == m - 1)
        ch = true;
      i++;
      j++;
    } else if (d[i] > t[j]) {
      cout << "NO" << endl;
      return 0;
    } else {
      i++;
    }
  }
  if (ch)
    fin("YES");
  else
    fin("NO");

  //////////////////////////////////////////////////////
  return 0;
}
