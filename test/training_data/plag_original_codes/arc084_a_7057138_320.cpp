/*
引用元：https://atcoder.jp/contests/abc077/tasks/arc084_a
C - Snuke FestivalEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc077/submissions/7057138
// 提出ID : 7057138
// 問題ID : arc084_a
// コンテストID : abc077
// ユーザID : xryuseix
// コード長 : 1677
// 実行時間 : 60



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
//_|

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int i, n, an, cn;
  cin >> n;

  vector<int> a(n, 0), b(n, 0), c(n, 0);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  //	rep(i,n)cout<<a[i]<<" ";
  //	cout<<endl;
  //	rep(i,n)cout<<b[i]<<" ";
  //	cout<<endl;
  //	rep(i,n)cout<<c[i]<<" ";
  //	cout<<endl;

  ll ans = 0;
  rep(i, n) {
    an = (lower_bound((a).begin(), (a).end(), b[i]) - a.begin());
    cn = c.end() - upper_bound((c).begin(), (c).end(), b[i]);
    ans += (ll)an * cn;
    //		cout<<an<<" "<<cn<<endl;
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
