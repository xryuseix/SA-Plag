/*
引用元：https://atcoder.jp/contests/arc074/tasks/arc074_b
D - 3N NumbersEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/arc074/submissions/10499950
// 提出ID : 10499950
// 問題ID : arc074_b
// コンテストID : arc074
// ユーザID : xryuseix
// コード長 : 2639
// 実行時間 : 170



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
#define MATHPI acos(-1)
#define itn int;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
  }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {

  int n;
  cin >> n;
  vll v(3 * n);
  rep(i, 3 * n) cin >> v[i];
  priority_queue<ll, vector<ll>, greater<ll>> q1;
  priority_queue<ll> q2;
  ll sum1 = 0, sum2 = 0;
  vll l(3 * n), r(3 * n);
  rep(i, 3 * n) {
    q1.push(v[i]);
    sum1 += v[i];
    if (q1.size() > n) {
      sum1 -= q1.top();
      q1.pop();
    }
    l[i] = sum1;
  }
  drep(i, 3 * n) {
    q2.push(v[i]);
    sum2 += v[i];
    if (q2.size() > n) {
      sum2 -= q2.top();
      q2.pop();
    }
    r[i] = sum2;
  }
  ll ans = -LLINF;
  for (int i = n; i <= 2 * n; i++) {
    chmax(ans, l[i - 1] - r[i]);
  }
  fin(ans);
  // rep(i,3*n){
  //     cout<<l[i]<<" ";
  // }
  // cout<<endl;
  // rep(i,3*n){
  //     cout<<r[i]<<" ";
  // }
  // cout<<endl;
}
