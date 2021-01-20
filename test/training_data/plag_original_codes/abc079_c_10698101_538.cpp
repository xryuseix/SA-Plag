/*
引用元：https://atcoder.jp/contests/abc079/tasks/abc079_c
C - Train TicketEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/abc079/submissions/10698101
// 提出ID : 10698101
// 問題ID : abc079_c
// コンテストID : abc079
// ユーザID : xryuseix
// コード長 : 2474
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

int calc(string s, vi v) {
  int ans = 0;
  ans += v[0];
  rep(i, 3) {
    if (s[i] == '+')
      ans += v[i + 1];
    else
      ans -= v[i + 1];
  }
  return ans;
}

int main() {

  vi v(4);
  string S;
  cin >> S;
  rep(i, 4) v[i] = S[i] - '0';
  for (int op = 0; op < (1 << 3); op++) {
    string s = "";
    int t = op;
    while (t > 0) {
      if (t % 2 == 0)
        s += '-';
      else
        s += '+';
      t /= 2;
    }
    while (s.size() != 3)
      s += '-';
    reverse(all(s));
    // cout<<s<<endl;
    if (calc(s, v) == 7) {
      cout << v[0] << s[0] << v[1] << s[1] << v[2] << s[2] << v[3] << "=7"
           << endl;
      return 0;
    }
  }
}
