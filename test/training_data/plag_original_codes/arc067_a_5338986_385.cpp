/*
引用元：https://atcoder.jp/contests/arc067/tasks/arc067_a
C - Factors of FactorialEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc067/submissions/5338986
// 提出ID : 5338986
// 問題ID : arc067_a
// コンテストID : arc067
// ユーザID : xryuseix
// コード長 : 1542
// 実行時間 : 3



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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  map<int, int> m;
  ll ans = 1, j, i, tp, n;
  cin >> n;
  if (i == 1) {
    cout << i << endl;
    return 0;
  }
  for (i = 2; i <= n; i++) {
    tp = i;
    j = 2;
    while (tp != 1) {
      //			cout<<"tp"<<" "<<tp<<" "<<j<<endl;
      if (tp % j == 0) {
        while (tp % j == 0) {
          if (m.find(j) == m.end()) {
            m[j] = 1;
          } else {
            m[j]++;
          }
          tp /= j;
        }
      }
      j++;
    }
  }
  map<int, int>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    ans *= (it->second) + 1;
    ans %= P;
    //		cout<< (it->second) <<endl;
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
