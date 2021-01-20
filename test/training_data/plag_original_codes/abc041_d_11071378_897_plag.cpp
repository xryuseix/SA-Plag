/*
引用元：https://atcoder.jp/contests/abc041/tasks/abc041_d
D - 徒競走Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/abc041/submissions/11071378
// 提出ID : 11071378
// 問題ID : abc041_d
// コンテストID : abc041
// ユーザID : xryuseix
// コード長 : 2766
// 実行時間 : 64



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
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
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
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())

int main() {

  int n, m;
  cin >> n >> m;
  set<pair<int, int>> s;
  rep(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    s.insert(mp(b - 1, a - 1));
  }
  vll dp(1 << 16, 0);
  dp[0] = 1;
  bool ch;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j))
        continue;
      ch = 1;
      rep(k, n) {
        if ((1 << k) & i && s.count(mp(k, j))) {
          ch &= 0;
          break;
        }
      }
      if (ch) {
        dp[i | (1 << j)] += dp[i];
      }
    }
  }
  printf("%lld\n", dp[(1 << n) - 1]);
}
