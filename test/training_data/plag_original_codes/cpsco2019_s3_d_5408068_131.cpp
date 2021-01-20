/*
引用元：https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_d
D - Decode RGB SequenceEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cpsco2019-s3/submissions/5408068
// 提出ID : 5408068
// 問題ID : cpsco2019_s3_d
// コンテストID : cpsco2019-s3
// ユーザID : xryuseix
// コード長 : 1792
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

  int n, i;
  cin >> n;
  string s;
  cin >> s;
  if (s.find("GG") != std::string::npos) {
    cout << "No" << endl;
    return 0;
  }
  if (s.find("RB") != std::string::npos) {
    cout << "No" << endl;
    return 0;
  }
  if (s.find('R') == std::string::npos) {
    cout << "No" << endl;
    return 0;
  }
  if (s.find('G') == std::string::npos) {
    cout << "No" << endl;
    return 0;
  }
  if (s.find('B') == std::string::npos) {
    cout << "No" << endl;
    return 0;
  }
  if (s[0] != 'R') {
    cout << "No" << endl;
    return 0;
  }
  if (s[s.length() - 1] != 'B') {
    cout << "No" << endl;
    return 0;
  }
  if (s.find("RGB") != std::string::npos) {

    cout << "Yes" << endl;
  } else
    cout << "No" << endl;

  //////////////////////////////////////////////////////
  return 0;
}
