/*
引用元：https://atcoder.jp/contests/arc034/tasks/arc034_1
A - 首席Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc034/submissions/5909884
// 提出ID : 5909884
// 問題ID : arc034_1
// コンテストID : arc034
// ユーザID : xryuseix
// コード長 : 1618
// 実行時間 : 2



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
  int i, n;
  cin >> n;
  vvi g(n, vector<int>(5, 0));
  rep(i, n) cin >> g[i][0] >> g[i][1] >> g[i][2] >> g[i][3] >> g[i][4];
  double ans[n];
  rep(i, n) {
    int j;
    ans[i] = 0;
    rep(j, 4) ans[i] += g[i][j];
    // cout<<ans[i]<<endl;
    ans[i] += (double)g[i][4] * 110.0 / 900;
  }
  sort(ans, ans + n);
  printf("%.7f\n", ans[n - 1]);
  //////////////////////////////////////////////////////
  return 0;
}
