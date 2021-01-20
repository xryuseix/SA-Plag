/*
引用元：https://atcoder.jp/contests/abc080/tasks/abc080_d
D - RecordingEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc080/submissions/5796398
// 提出ID : 5796398
// 問題ID : abc080_d
// コンテストID : abc080
// ユーザID : xryuseix
// コード長 : 1481
// 実行時間 : 30



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
  int i, n, C;
  cin >> n >> C;
  int s, t, c;
  vector<int> v(1000000, 0), w(1000000, 0);
  rep(i, n) {
    cin >> s >> t >> c;
    v[s]++;
    v[t + 1]--;
  }
  for (i = 1; i < w.size(); i++) {
    w[i] = w[i - 1] + v[i];
  }
  int ans = 0;
  for (i = 0; i < w.size(); i++) {
    ans = max(ans, w[i]);
  }
  fin(min(ans, C));
  //////////////////////////////////////////////////////
  return 0;
}
