/*
引用元：https://atcoder.jp/contests/abc081/tasks/arc086_a
C - Not so DiverseEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc081/submissions/5795849
// 提出ID : 5795849
// 問題ID : arc086_a
// コンテストID : abc081
// ユーザID : xryuseix
// コード長 : 1766
// 実行時間 : 129



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

  int n, k, i, j = 0, t;
  cin >> n >> k;
  set<int> s;
  vector<pair<int, int>> v, x;
  vector<int> w(n, 0);
  rep(i, n) cin >> w[i];
  sort(w.begin(), w.end());
  rep(i, n) {
    t = w[i];
    if (s.find(t) != s.end()) {
      v[v.size() - 1].second++;
    } else {
      v.push_back(make_pair(t, 1));
      s.insert(t);
    }
  }
  rep(i, v.size()) { x.push_back(make_pair(v[i].second, v[i].first)); }
  sort(x.begin(), x.end());
  int ans = 0;
  t = max((int)x.size() - k, 0);
  rep(i, t) { ans += x[i].first; }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
