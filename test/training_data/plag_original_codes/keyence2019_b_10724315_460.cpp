/*
引用元：https://atcoder.jp/contests/keyence2019/tasks/keyence2019_b
B - KEYENCE StringEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/keyence2019/submissions/10724315
// 提出ID : 10724315
// 問題ID : keyence2019_b
// コンテストID : keyence2019
// ユーザID : xryuseix
// コード長 : 2573
// 実行時間 : 1



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
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#pragma GCC optimize("Ofast")
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
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

#include <regex>

int main() {

  string s;
  cin >> s;
  bool ch = 0;
  if (regex_match(s, regex(".*keyence"))) {
    ch = 1;
  }
  if (std::regex_match(s, regex("k.*eyence$"))) {
    ch = 1;
  }
  if (std::regex_match(s, regex("ke.*yence"))) {
    ch = 1;
  }
  if (std::regex_match(s, regex("key.*ence"))) {
    ch = 1;
  }
  if (std::regex_match(s, regex("keye.*nce"))) {
    ch = 1;
  }
  if (std::regex_match(s, regex("keyen.*ce"))) {
    ch = 1;
  }
  if (std::regex_match(s, regex("keyenc.*e"))) {
    ch = 1;
  }
  if (std::regex_match(s, regex("keyence.*"))) {
    ch = 1;
  }
  if (std::regex_match(s, regex("keyence"))) {
    ch = 1;
  }
  if (ch)
    fin("YES");
  else
    fin("NO");
}
