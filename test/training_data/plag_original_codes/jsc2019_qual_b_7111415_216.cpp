/*
引用元：https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_b
B - Kleene InversionEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/jsc2019-qual/submissions/7111415
// 提出ID : 7111415
// 問題ID : jsc2019_qual_b
// コンテストID : jsc2019-qual
// ユーザID : xryuseix
// コード長 : 2140
// 実行時間 : 14



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

  ll n, k;
  ll ans = 0;
  cin >> n >> k;
  vi a(n);
  rep(i, n) cin >> a[i];
  vi all(n, 0), right(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] > a[j]) {
        all[i]++;
        if (i < j)
          right[i]++;
      }
    }
  }
  // for(int i=0;i<n;i++){
  //     cout<<all[i]<<" ";
  // }
  // cout<<endl;
  // for(int i=0;i<n;i++){
  //     cout<<right[i]<<" ";
  // }
  // cout<<endl;
  ll K = (k * k - k * (k + 1) / 2) % P;
  for (int i = 0; i < n; i++) {
    ans += ((all[i] * K) % P + (right[i] * k) % P) % P;
    ans %= P;
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
