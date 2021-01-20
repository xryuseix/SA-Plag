/*
引用元：https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_c
C - 100 to 105Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/sumitrust2019/submissions/8753358
// 提出ID : 8753358
// 問題ID : sumitb2019_c
// コンテストID : sumitrust2019
// ユーザID : xryuseix
// コード長 : 2214
// 実行時間 : 609



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
#include <unordered_set>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)


int main(void) {

  int x;
  set<int> s;
  vi a{100, 101, 102, 103, 104, 105};
  cin >> x;
  s.insert(0);
  rep(i,1001) {
    set<int> tmp;
    for (auto it = s.begin(); it != s.end(); it++) {
      rep(j, 6) {
        if (a[j] + (*it) <= x)
          tmp.insert(a[j] + (*it));
      }
    }
    if (s.find(x) != s.end()) {
      fin(1);
      return 0;
    }
    s.clear();
    s = tmp;
  }
  fin(s.find(x) != s.end());
}
