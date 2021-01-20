/*
引用元：https://atcoder.jp/contests/arc039/tasks/arc039_a
A - A - B problemEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc039/submissions/7188308
// 提出ID : 7188308
// 問題ID : arc039_a
// コンテストID : arc039
// ユーザID : xryuseix
// コード長 : 1944
// 実行時間 : 1



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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  string a, b;
  cin >> a >> b;
  int ans = -INF;
  string s;
  s = a;
  s[0] = '9';
  ans = max(ans, STI(s) - STI(b));
  s = a;
  s[1] = '9';
  ans = max(ans, STI(s) - STI(b));
  s = a;
  s[2] = '9';
  ans = max(ans, STI(s) - STI(b));
  s = b;
  s[0] = '1';
  ans = max(ans, STI(a) - STI(s));
  s = b;
  s[1] = '0';
  ans = max(ans, STI(a) - STI(s));
  s = b;
  s[2] = '0';
  ans = max(ans, STI(a) - STI(s));
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
