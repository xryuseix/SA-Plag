/*
引用元：https://atcoder.jp/contests/arc024/tasks/arc024_1
A - くつがくっつくEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc024/submissions/6114533
// 提出ID : 6114533
// 問題ID : arc024_1
// コンテストID : arc024
// ユーザID : xryuseix
// コード長 : 1713
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
#define fin(ans) cout << (ans) << endl
#define P 1000000007
#define STI(s) atoi(s.c_str()) // string to int
#define mp(p, q) make_pair(p, q)
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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  int i, l, r, ans = 0;
  cin >> l >> r;
  vector<int> L(l), R(r);
  rep(i, l) cin >> L[i];
  rep(i, r) cin >> R[i];
  Sort(L);
  Sort(R);
  int j = 0;
  i = 0;
  while (i < l && j < r) {
    // cout<<L[i]<<" "<<
    if (L[i] == R[j]) {
      ans++;
      i++;
      j++;
    } else if (L[i] < R[j]) {
      i++;
    } else if (L[i] > R[j]) {
      j++;
    }
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
