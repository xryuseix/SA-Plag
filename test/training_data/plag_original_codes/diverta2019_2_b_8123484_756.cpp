/*
引用元：https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_b
B - Picking UpEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/diverta2019-2/submissions/8123484
// 提出ID : 8123484
// 問題ID : diverta2019_2_b
// コンテストID : diverta2019-2
// ユーザID : xryuseix
// コード長 : 2168
// 実行時間 : 15



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
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
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
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  };
};
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int main(void) {

  int n;
  cin >> n;
  vi x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  int ans = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      int p = x[i] - x[j];
      int q = y[i] - y[j];
      vi group;
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          if (k == l)
            continue;

          if (x[k] - x[l] == p && y[k] - y[l] == q) {
            group.push_back(k);
          }
        }
      }
      ans = min(ans, n - (int)group.size());
    }
  }
  if (n == 1)
    ans = 1;
  fin(ans);
}
