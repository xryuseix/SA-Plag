/*
引用元：https://atcoder.jp/contests/arc044/tasks/arc044_a
A - 素数判定Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc044/submissions/5908577
// 提出ID : 5908577
// 問題ID : arc044_a
// コンテストID : arc044
// ユーザID : xryuseix
// コード長 : 1829
// 実行時間 : 1



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
#define STI(s) atoi(s.c_str()) // string to int
#define mp(p, q) make_pair(p, q)
#define Sort(a) sort(a.begin(), a.end())
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
bool isPrime(int x) {
  int i;
  if (x < 2)
    return 0;
  else if (x == 2)
    return 1;
  if (x % 2 == 0)
    return 0;
  for (i = 3; i * i <= x; i += 2)
    if (x % i == 0)
      return 0;
  return 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  int n;
  cin >> n;
  if (n == 1) {
    fin("Not Prime");
    return 0;
  }
  if (isPrime(n) == true) {
    fin("Prime");
    return 0;
  }
  if (n % 10 % 2 == 0 || n % 10 == 5) {
    fin("Not Prime");
    return 0;
  }
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  if (sum % 3 != 0)
    cout << "Prime" << endl;
  else
    cout << "Not Prime" << endl;

  //////////////////////////////////////////////////////
  return 0;
}
