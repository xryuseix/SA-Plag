/*
引用元：https://atcoder.jp/contests/abc035/tasks/abc035_c
C - オセロEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc035/submissions/7709387
// 提出ID : 7709387
// 問題ID : abc035_c
// コンテストID : abc035
// ユーザID : xryuseix
// コード長 : 1881
// 実行時間 : 43



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
#include <cfloat>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
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
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int n, q;
  cin >> n >> q;
  vi v(n + 1, 0), csum(n);
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    v[l]++;
    v[r + 1]--;
  }
  for (int i = 0; i < n; i++) {
    if (i == 0)
      csum[i] = v[i];
    else {
      csum[i] = v[i] + csum[i - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    csum[i] %= 2;
  }
  rep(i, n) cout << csum[i];
  cout << endl;

  //////////////////////////////////////////////////////
  return 0;
}
