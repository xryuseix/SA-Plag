/*
引用元：https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_c
C - Camp ReceptionEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cpsco2019-s3/submissions/5407711
// 提出ID : 5407711
// 問題ID : cpsco2019_s3_c
// コンテストID : cpsco2019-s3
// ユーザID : xryuseix
// コード長 : 1580
// 実行時間 : 51



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

  int i, n, s, t;
  cin >> n;
  vpii v;
  rep(i, n) {
    cin >> s >> t;
    v.push_back(make_pair(s, t));
  }
  int ans = 1;
  sort(v.begin(), v.end());
  int f = v[0].first, l = v[0].second;
  for (i = 1; i < n; i++) {
    // cout<<v[i].first<<" "<<f<<" "<<l<<" "<<v[i].second<<endl;
    if (v[i].first >= f && v[i].first <= l) {
      l = max(v[i].second, l);
    } else {
      // cout<<ans<<endl;
      ans++;
      f = v[i].first;
      l = v[i].second;
    }
  }
  cout << ans << endl;

  //////////////////////////////////////////////////////
  return 0;
}
