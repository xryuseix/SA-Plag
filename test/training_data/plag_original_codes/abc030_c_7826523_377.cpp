/*
引用元：https://atcoder.jp/contests/abc030/tasks/abc030_c
C - 飛行機乗りEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc030/submissions/7826523
// 提出ID : 7826523
// 問題ID : abc030_c
// コンテストID : abc030
// ユーザID : xryuseix
// コード長 : 2873
// 実行時間 : 75


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
const ll LLINF = 1LL << 60;

int main(void) {

  int n, m;
  int x, y;
  cin >> n >> m >> x >> y;
  vi a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  ll ans = 0;

  a.push_back(INF);
  b.push_back(INF);

  ll turn = 0;
  ll time = a[0];

  while (1) {
    if (turn == 0) {
      auto it = lower_bound(b.begin(), b.end(), time + x);
      if (*it == INF) {
        ans++;
        break;
      }
      time = *it;
      turn = 1 - turn;
      ans++;
      // cout<<"time:"<<time<<endl;
    } else {
      auto it = lower_bound(a.begin(), a.end(), time + y);
      if (*it == INF) {
        ans++;
        break;
      }
      time = *it;
      turn = 1 - turn;
      ans++;
      // cout<<"time:"<<time<<endl;
    }
  }
  fin(ans / 2);
}
