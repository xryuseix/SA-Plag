/*
引用元：https://atcoder.jp/contests/arc042/tasks/arc042_a
A - 掲示板Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc042/submissions/6744541
// 提出ID : 6744541
// 問題ID : arc042_a
// コンテストID : arc042
// ユーザID : xryuseix
// コード長 : 1925
// 実行時間 : 167



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

  int n, m;
  cin >> n >> m;
  vi v(n, 0), w(m);
  int co = 1;
  rep(i, m) cin >> w[i];
  reverse(all(w));
  rep(i, m) if (v[w[i] - 1] == 0) {
    v[w[i] - 1] = co;
    co++;
  }
  rep(i, n) {
    if (v[i] == 0) {
      v[i] = co;
      co++;
    }
  }
  vpii z;
  rep(i, n) z.push_back(mp(v[i], i + 1));
  Sort(z);
  rep(i, n) { cout << z[i].second << endl; }

  //////////////////////////////////////////////////////
  return 0;
}
