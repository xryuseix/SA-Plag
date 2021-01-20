/*
引用元：https://atcoder.jp/contests/abc037/tasks/abc037_c
C - 総和Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc037/submissions/6420655
// 提出ID : 6420655
// 問題ID : abc037_c
// コンテストID : abc037
// ユーザID : xryuseix
// コード長 : 1857
// 実行時間 : 11



*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <string>
#include <bitset>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
// g++ -std=c++1z temp.cpp
//./a.out

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  ll n, k;
  cin >> n >> k;
  vll v(n), w(n, INF);
  rep(i, n) cin >> v[i];
  ll ans = 0;

  ll l = 1, r = k;
  ll sum = 0;
  for (int i = 0; i < k; i++) {
    sum += v[i];
  }
  ans += sum;
  // fin(ans);
  for (int i = 1; r < n; i++) {
    sum += v[r];
    r++;
    sum -= v[l - 1];
    l++;
    ans += sum;
    // fin(ans);
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
