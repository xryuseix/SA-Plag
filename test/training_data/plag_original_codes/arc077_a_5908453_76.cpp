/*
引用元：https://atcoder.jp/contests/arc077/tasks/arc077_a
C - pushpushEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc077/submissions/5908453
// 提出ID : 5908453
// 問題ID : arc077_a
// コンテストID : arc077
// ユーザID : xryuseix
// コード長 : 1659
// 実行時間 : 48



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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////
  int n;
  cin >> n;
  int front = 0;
  if (n % 2 == 1)
    front = 1;
  int d;
  list<int> li;
  for (int i = 0; i < n; i++) {
    cin >> d;
    if (front == 1)
      li.push_front(d);
    else
      li.push_back(d);
    front = 1 - front;
  }
  int i = 0;
  for (auto it = li.begin(); it != li.end(); it++) {
    cout << *it;
    if (i != n - 1)
      cout << " ";
    else
      cout << endl;
    i++;
  }

  //////////////////////////////////////////////////////
  return 0;
}
