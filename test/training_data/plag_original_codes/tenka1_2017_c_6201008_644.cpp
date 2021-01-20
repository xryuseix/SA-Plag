/*
引用元：https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_c
C - 4/NEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/tenka1-2017/submissions/6201008
// 提出ID : 6201008
// 問題ID : tenka1_2017_c
// コンテストID : tenka1-2017
// ユーザID : xryuseix
// コード長 : 1697
// 実行時間 : 5



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
  ll N;
  cin >> N;
  for (ll h = 1; h <= 3500; h++) {
    for (ll n = 1; n <= 3500; n++) {
      if ((4 * h * n - N * n - N * h) <= 0)
        continue;
      if (N * h * n % (4 * h * n - N * n - N * h) == 0) {
        cout << h << " " << n << " " << N *h *n / (4 * h * n - N * n - N * h)
             << endl;
        return 0;
      }
    }
  }
  //////////////////////////////////////////////////////
  return 0;
}
