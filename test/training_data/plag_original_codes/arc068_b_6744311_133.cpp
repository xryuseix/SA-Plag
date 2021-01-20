/*
引用元：https://atcoder.jp/contests/abc053/tasks/arc068_b
D - Card EaterEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc053/submissions/6744311
// 提出ID : 6744311
// 問題ID : arc068_b
// コンテストID : abc053
// ユーザID : xryuseix
// コード長 : 1872
// 実行時間 : 48



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

  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  map<int, int> m;
  rep(i, n) {
    if (m.find(a[i]) != m.end()) {
      m[a[i]]++;
    } else
      m[a[i]] = 1;
  }
  int sum = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    sum += it->second - 1;
  }
  if (sum % 2 == 1)
    sum++;
  cout << max(0, n - sum) << endl;

  //////////////////////////////////////////////////////
  return 0;
}
