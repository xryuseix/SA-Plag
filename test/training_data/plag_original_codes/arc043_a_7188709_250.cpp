/*
引用元：https://atcoder.jp/contests/arc043/tasks/arc043_a
A - 点数変換Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc043/submissions/7188709
// 提出ID : 7188709
// 問題ID : arc043_a
// コンテストID : arc043
// ユーザID : xryuseix
// コード長 : 1895
// 実行時間 : 19



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

  double n, a, b;
  cin >> n >> a >> b;
  double p, q;
  vi v(n);
  rep(i, n) cin >> v[i];
  Sort(v);
  double sum = 0;
  rep(i, n) sum += v[i];
  if (v[n - 1] == v[0]) {
    cout << -1 << endl;
    return 0;
  }
  p = b / (v[n - 1] - v[0]);
  double ave = 0;
  rep(i, n) ave += v[i];
  ave /= n;
  q = a - ave * p;

  printf("%.10f %.10f\n", p, q);

  //////////////////////////////////////////////////////
  return 0;
}
