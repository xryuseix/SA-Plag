/*
引用元：https://atcoder.jp/contests/abc031/tasks/abc031_c
C - 数列ゲームEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc031/submissions/6659917
// 提出ID : 6659917
// 問題ID : abc031_c
// コンテストID : abc031
// ユーザID : xryuseix
// コード長 : 2666
// 実行時間 : 1



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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int n;
  cin >> n;
  vi v(n);
  rep(i, n) cin >> v[i];
  int t, a;
  int ans = 10 - INF;
  for (t = 0; t < n; t++) {
    int amax = 10 - INF;
    int tmax = 10 - INF;

    for (a = 0; a < n; a++) {
      if (t == a)
        continue;
      int tpoint = 0, apoint = 0;

      if (t < a) {
        for (int i = t; i <= a; i += 2) {
          tpoint += v[i];
        }
        for (int i = t + 1; i <= a; i += 2) {
          apoint += v[i];
        }
      } else {
        for (int i = a; i <= t; i += 2) {
          tpoint += v[i];
          // if(a==0&&t==2){
          //     cout<<v[i]<<":";
          // }
        }
        for (int i = a + 1; i <= t; i += 2) {
          apoint += v[i];
        }
        // cout<<endl;
      }

      // cout<<amax<<"apoint:"<<apoint<<" "<<tpoint<<endl;
      if (amax < apoint) {
        tmax = tpoint;
        amax = apoint;
      }
    }
    // cout<<"----------------"<<endl;

    ans = max(ans, tmax);
  }
  cout << ans << endl;

  //////////////////////////////////////////////////////
  return 0;
}
