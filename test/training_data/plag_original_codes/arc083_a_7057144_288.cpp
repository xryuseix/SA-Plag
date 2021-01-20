/*
引用元：https://atcoder.jp/contests/arc083/tasks/arc083_a
C - Sugar WaterEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc083/submissions/7057144
// 提出ID : 7057144
// 問題ID : arc083_a
// コンテストID : arc083
// ユーザID : xryuseix
// コード長 : 2026
// 実行時間 : 31



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
#include <bits/stdc++.h>
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define P 1000000007
using namespace std;
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
const long long LLINF = 1LL << 60;
// set<int>::iterator it;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  /*
  int n,i,a,b;
  cin>>n;
  vector<int> a(n,0),b(n,0);
  rep(i,n)cin>>a[i]>>b[i];
  */
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<ll> wa;
  vector<ll> su;
  ll answa = 1, anssu = 0;
  double nomax = -1;
  ll i, j;
  for (i = 0; i < f; i++) {
    for (j = 0; j < f; j++) {
      if (c * i + d * j <= f && a * i + d * j > 0) {
        su.push_back(c * i + d * j);
      }
    }
  }

  for (i = 0; i < f; i++) {
    for (j = 0; j < f; j++) {
      if ((a * i + b * j) * 100 <= f && a * i + b * j >= 0) {
        wa.push_back((a * i + b * j) * 100);
      }
    }
  }

  for (i = 0; i < wa.size(); i++) {
    for (j = 0; j < su.size(); j++) {

      //			cout<<t<<endl;
      double m = (wa[i]) * e / 100;
      int s = su[j];
      //			cout<<s<<" "<<m<<endl;
      if (s <= m) {
        double per = (double)s / (wa[i] + s);
        if (nomax <= per && wa[i] + s <= f) {
          answa = wa[i];
          anssu = su[j];
          nomax = per;
        }
      }
    }
  }
  if (answa == 1) {
    answa = min(a, b) * 100;
  }
  cout << answa + anssu << " " << anssu << endl;

  //////////////////////////////////////////////////////
  return 0;
}
