/*
引用元：https://atcoder.jp/contests/abc061/tasks/abc061_c
C - Big ArrayEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc061/submissions/5561361
// 提出ID : 5561361
// 問題ID : abc061_c
// コンテストID : abc061
// ユーザID : xryuseix
// コード長 : 1640
// 実行時間 : 25



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
  ll i, k, n;
  cin >> n >> k;
  vector<pair<ll, ll>> a(n, make_pair(0, 0));
  ll s, t;
  vector<ll> dsum;
  rep(i, n) {
    cin >> s >> t;
    a[i] = make_pair(s, t);
  }
  ll sum = 0;
  sort(a.begin(), a.end());
  rep(i, n) {
    if (i == 0)
      dsum.push_back(a[i].second);
    else
      dsum.push_back(a[i].second + dsum[i - 1]);
  }

  rep(i, n + 1) {

    if (k <= dsum[i]) {
      cout << a[i].first << endl;
      return 0;
    }
  }

  //////////////////////////////////////////////////////
  return 0;
}
