/*
引用元：https://atcoder.jp/contests/jsc2019-final-open/tasks/jsc2019_final_a
A - Equal WeightEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/jsc2019-final-open/submissions/7800599
// 提出ID : 7800599
// 問題ID : jsc2019_final_a
// コンテストID : jsc2019-final-open
// ユーザID : xryuseix
// コード長 : 2229
// 実行時間 : 40



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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int n, m;
  cin >> n >> m;
  vi a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  vpii v(2000100, mp(-1, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[a[i] + b[j]].first != -1) {
        cout << i << " " << j << " " << v[a[i] + b[j]].first << " "
             << v[a[i] + b[j]].second << endl;
        return 0;
      } else {
        v[a[i] + b[j]].first = i;
        v[a[i] + b[j]].second = j;
      }
      // for(int k=0;k<19;k++){
      //     cout<<v[k].first<<","<<v[k].second<<" ";
      // }
      // cout<<endl<<endl;;
    }
  }
  cout << -1 << endl;

  //////////////////////////////////////////////////////
  return 0;
}
