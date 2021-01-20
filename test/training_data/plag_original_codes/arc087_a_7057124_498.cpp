/*
引用元：https://atcoder.jp/contests/arc087/tasks/arc087_a
C - Good SequenceEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc087/submissions/7057124
// 提出ID : 7057124
// 問題ID : arc087_a
// コンテストID : arc087
// ユーザID : xryuseix
// コード長 : 1457
// 実行時間 : 17



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

  int n;
  cin >> n;
  int i, j;
  int ans = 0, tmp;
  vector<int> v(n, 0);
  rep(i, n) cin >> v[i];
  sort(v.begin(), v.end());
  rep(i, n) {
    tmp = v[i];
    j = 0;
    while (i + j < n && v[i + j] == v[i]) {
      j++;
    }
    if (j > tmp)
      ans += j - tmp;
    else if (j < tmp)
      ans += j;
    i += j - 1;
    //		cout<<ans<<endl;
  }
  cout << ans << endl;

  //////////////////////////////////////////////////////
  return 0;
}
