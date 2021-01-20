/*
引用元：https://atcoder.jp/contests/arc036/tasks/arc036_b
B - 山のデータEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc036/submissions/8918115
// 提出ID : 8918115
// 問題ID : arc036_b
// コンテストID : arc036
// ユーザID : xryuseix
// コード長 : 2548
// 実行時間 : 122



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
#include <unordered_set>
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
#define itn int
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
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int main(void) {

  ll n;
  cin >> n;
  vll h(n);
  rep(i, n) cin >> h[i];

  ll pos = 0;
  bool ch = 1;
  if (n == 1) {
    fin(1);
    return 0;
  }
  if (h[0] > h[1])
    ch = 0;
  vll v, w;
  while (pos < n) {
    // cout<<h[pos]<<" ";
    ll len = 1;
    ll tmp = pos;
    if (ch) {
      while (tmp + 1 < n && h[tmp] < h[tmp + 1]) {
        tmp++;
        len++;
      }
    } else {
      while (tmp + 1 < n && h[tmp] > h[tmp + 1]) {
        tmp++;
        len++;
      }
    }
    // cout<<len<<endl;
    pos += max(len - 1, 1LL);
    v.push_back(len);
    w.push_back(ch);
    ch = 1 - ch;
  }
  ll ans = 0;
  rep(i, v.size()) {
    if (w[i] == 0) {
      ans = max(ans, v[i]);
    } else if (w[i] && i < v.size() - 1) {
      ans = max(ans, v[i] + v[i + 1] - 1);
      i++;
    } else {
      ans = max(ans, v[i]);
    }
  }

  fin(ans);
}
