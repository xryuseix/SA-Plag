/*
引用元：https://atcoder.jp/contests/abc038/tasks/abc038_c
C - 単調増加Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc038/submissions/6760130
// 提出ID : 6760130
// 問題ID : abc038_c
// コンテストID : abc038
// ユーザID : xryuseix
// コード長 : 2116
// 実行時間 : 10



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

ll nCk(ll n) { return (ll)n * (ll)(n - 1) / 2; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int n;
  cin >> n;
  vi a(n);
  ll ans = n;
  rep(i, n) cin >> a[i];
  ll f = 0, l = 0;
  vector<ll> num;
  for (int i = 0; i < n; i++) {
    f = i;
    l = f;
    while ((l < n) && (l == f || a[f] < a[l])) {
      if (l != f)
        f++;
      l++;

      // cout<<f<<" "<<l<<endl;
    }
    // cout<<"---------"<<endl;
    num.push_back(l - i);
    i += l - i - 1;
  }
  rep(i, num.size()) {
    if (num[i] == 1)
      continue;
    else {
      ans += nCk(num[i]);
    }
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
