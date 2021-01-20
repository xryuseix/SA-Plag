/*
引用元：https://atcoder.jp/contests/code-festival-2018-qualb/tasks/code_festival_2018_qualb_b
B - TensaiEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-festival-2018-qualb/submissions/6256895
// 提出ID : 6256895
// 問題ID : code_festival_2018_qualb_b
// コンテストID : code-festival-2018-qualb
// ユーザID : xryuseix
// コード長 : 1979
// 実行時間 : 1



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
#define P 1000000007
#define STI(s) atoi(s.c_str()) // string to int
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define Sort(a) sort(a.begin(), a.end())
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
const int INF = INT_MAX;
const long long LLINF = 1LL << 60;
// g++ -std=c++1z temp.cpp
//./a.out

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  int n, x;
  cin >> n >> x;
  vvi v(n, vi(3, 0));
  rep(i, n) cin >> v[i][0] >> v[i][1];
  for (int j = 0; j < x; j++) {
    for (int i = 0; i < n; i++) {
      v[i][2] = (v[i][0] + 1) * v[i][1] - v[i][0] * v[i][1];
    }
    int maxs = 0, maxp = 0;
    for (int i = 0; i < n; i++) {
      if (v[i][2] >= maxs) {
        maxs = v[i][2];
        maxp = i;
      }
    }
    v[maxp][0]++;
  }
  int ans = 0;
  rep(i, n) { ans += v[i][0] * v[i][1]; }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}

// 4 25 増分
