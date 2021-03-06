/*
引用元：https://atcoder.jp/contests/arc036/tasks/arc036_a
A - ぐっすりEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc036/submissions/6122352
// 提出ID : 6122352
// 問題ID : arc036_a
// コンテストID : arc036
// ユーザID : xryuseix
// コード長 : 1756
// 実行時間 : 9



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
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
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


int main(void) {

  int n, k;
  bool lost = false;
  cin >> n >> k;
  vi v(n);
  rep(i, n) cin >> v[i];
  int sum = v[0] + v[1] + v[2];
  if (sum < k) {
    cout << 3 << endl;
    return 0;
  }
  for (int i = 3; i < n; i++) {
    sum -= v[i - 3];
    sum += v[i];
    if (sum < k) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;

  //////////////////////////////////////////////////////
  return 0;
}
