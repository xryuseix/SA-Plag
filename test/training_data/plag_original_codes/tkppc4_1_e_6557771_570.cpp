/*
引用元：https://atcoder.jp/contests/tkppc4-1/tasks/tkppc4_1_e
E - Osmium_1008と課題Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/tkppc4-1/submissions/6557771
// 提出ID : 6557771
// 問題ID : tkppc4_1_e
// コンテストID : tkppc4-1
// ユーザID : xryuseix
// コード長 : 2234
// 実行時間 : 61



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
// g++ -std=c++1z temp.cpp
//./a.out

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  ll n, m, k, e;
  cin >> n >> m >> k >> e;
  vi a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  sort(rall(b));
  Sort(a);
  vi v(k);
  rep(i, k) { v[i] = b[i]; }
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (e >= a[i]) {
      e -= a[i];
    } else {
      while (e < a[i] && pos < k) {
        e += v[pos];
        pos++;
      }
      if (e >= a[i]) {
        e -= a[i];
      } else {
        cout << "No" << endl;
        cout << i << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  cout << pos << endl;

  //////////////////////////////////////////////////////
  return 0;
}
