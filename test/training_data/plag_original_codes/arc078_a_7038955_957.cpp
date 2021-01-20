/*
引用元：https://atcoder.jp/contests/abc067/tasks/arc078_a
C - Splitting PileEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc067/submissions/7038955
// 提出ID : 7038955
// 問題ID : arc078_a
// コンテストID : abc067
// ユーザID : xryuseix
// コード長 : 1883
// 実行時間 : 22



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

  ll n;
  cin >> n;
  vll a(n);
  rep(i, n) cin >> a[i];
  vll csum(n + 1);
  csum[0] = 0;
  for (ll i = 1; i < n + 1; i++) {
    csum[i] = csum[i - 1] + a[i - 1];
  }
  ll ans = INF;
  ll sum = csum[n];
  for (ll i = 1; i < n; i++) {
    ll left = csum[i] - csum[0];
    ll right = sum - (csum[i] - csum[0]);
    ans = min(ans, abs(right - left));
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
