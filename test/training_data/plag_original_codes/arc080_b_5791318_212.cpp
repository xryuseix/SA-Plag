/*
引用元：https://atcoder.jp/contests/arc080/tasks/arc080_b
D - Grid ColoringEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc080/submissions/5791318
// 提出ID : 5791318
// 問題ID : arc080_b
// コンテストID : arc080
// ユーザID : xryuseix
// コード長 : 1759
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
//|\_
// g++ -std=c++1z temp.cpp
//./a.out

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  int h, w, i, j, n;
  cin >> h >> w >> n;
  vector<int> a(n, 0);
  vector<int> num;
  rep(i, n) cin >> a[i];
  rep(i, n) rep(j, a[i]) num.push_back(i + 1);

  vvi ans(h, vi(w, 0));
  int p = 0;
  rep(i, h) {
    if (i % 2 == 0) {
      rep(j, w) {
        ans[i][j] = num[p];
        p++;
      }
    } else {
      for (j = w - 1; j >= 0; j--) {
        ans[i][j] = num[p];
        p++;
      }
    }
  }
  rep(i, h) {
    rep(j, w) {
      if (j != w - 1)
        cout << ans[i][j] << " ";
      else
        cout << ans[i][j] << endl;
    }
  }
  //////////////////////////////////////////////////////
  return 0;
}
