/*
引用元：https://atcoder.jp/contests/abc059/tasks/arc072_a
C - SequenceEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc059/submissions/5782194
// 提出ID : 5782194
// 問題ID : arc072_a
// コンテストID : abc059
// ユーザID : xryuseix
// コード長 : 1609
// 実行時間 : 14



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
  ll i, n;
  ll sum = 0, ans = 0, minans;
  cin >> n;
  vector<ll> v(n + 10, 0), w(n, 0);
  rep(i, n) { cin >> v[i]; }

  int s;
  for (i = 0, s = 1; i < n; i++, s *= -1) {
    sum += v[i];
    if (sum * s <= 0)
      ans += abs(sum - s), sum = s;
  }

  minans = ans;
  ans = 0;
  sum = 0;
  for (i = 0, s = -1; i < n; i++, s *= -1) {
    sum += v[i];
    if (sum * s <= 0)
      ans += abs(sum - s), sum = s;
  }

  minans = min(ans, minans);
  cout << minans << endl;

  //////////////////////////////////////////////////////
  return 0;
}
