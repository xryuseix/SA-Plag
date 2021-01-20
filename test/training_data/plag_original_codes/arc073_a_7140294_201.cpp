/*
引用元：https://atcoder.jp/contests/abc060/tasks/arc073_a
C - SentouEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc060/submissions/7140294
// 提出ID : 7140294
// 問題ID : arc073_a
// コンテストID : abc060
// ユーザID : xryuseix
// コード長 : 2078
// 実行時間 : 21



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
// #define all(a) a.begin(),a.end()
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

  ll n, t;
  cin >> n >> t;
  vll v(n);
  rep(i, n) cin >> v[i];
  ll ans = 0;
  ll first = 0, second = 0;
  if (n == 1) {
    ans += t;
    fin(ans);
    return 0;
  }
  v.push_back(LLINF);
  for (int i = 0; i < n; i++) {
    // cout<<i<<endl;
    ll tmp = 0;
    first = i;
    // cout<<v[first+tmp+1]<<" "<<v[first+tmp]+t<<endl;
    while (v[first + tmp + 1] <= v[first + tmp] + t) {
      tmp++;
    }
    ans += v[first + tmp] + t - v[first];
    i += tmp;
    // cout<<tmp<<" "<<ans<<endl;
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
