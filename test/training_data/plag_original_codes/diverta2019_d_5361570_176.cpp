/*
引用元：https://atcoder.jp/contests/diverta2019/tasks/diverta2019_d
D - DivRem NumberEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/diverta2019/submissions/5361570
// 提出ID : 5361570
// 問題ID : diverta2019_d
// コンテストID : diverta2019
// ユーザID : xryuseix
// コード長 : 1537
// 実行時間 : 12



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

std::vector<ll> enum_div(ll n) // nの約数を列挙
{
  std::vector<ll> ret;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i != 1 && i * i != n) {
        ret.push_back(n / i);
      }
    }
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  ll n, ans = 0, i;
  cin >> n;
  vector<ll> r = enum_div(n);
  // for(auto i : r) std::cout << i << std::endl;
  // cout<<"aaa"<<endl;
  for (i = 1; i < r.size(); i++) {
    if (n / (r[i] - 1) == n % (r[i] - 1)) {
      ans += r[i] - 1;
    }
  }
  if (n > 1 && n / (n - 1) == n % (n - 1)) {
    ans += n - 1;
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
