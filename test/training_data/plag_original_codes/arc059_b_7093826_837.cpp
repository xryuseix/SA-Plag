/*
引用元：https://atcoder.jp/contests/arc059/tasks/arc059_b
D - UnbalancedEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc059/submissions/7093826
// 提出ID : 7093826
// 問題ID : arc059_b
// コンテストID : arc059
// ユーザID : xryuseix
// コード長 : 1877
// 実行時間 : 2



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

  string s;
  cin >> s;
  if (s.length() == 2) {
    if (s[0] == s[1])
      cout << "1 2" << endl;
    else
      cout << "-1 -1" << endl;
    return 0;
  }
  for (int i = 0; i < s.length() - 2; i++) {
    if (s[i + 0] == s[i + 1] || s[i + 1] == s[i + 2] || s[i + 0] == s[i + 2]) {
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
  }
  cout << "-1 -1" << endl;

  //////////////////////////////////////////////////////
  return 0;
}
