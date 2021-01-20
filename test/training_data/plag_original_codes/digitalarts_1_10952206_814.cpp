/*
引用元：https://atcoder.jp/contests/digitalarts2012/tasks/digitalarts_1
A - C-FilterEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/digitalarts2012/submissions/10952206
// 提出ID : 10952206
// 問題ID : digitalarts_1
// コンテストID : digitalarts2012
// ユーザID : xryuseix
// コード長 : 2919
// 実行時間 : 2



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
#define endl '\n';
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

bool isnum(string s) {
  bool res = 1;
  rep(i, s.size()) {
    if (s[i] < '0' || s[i] > '9')
      res = 0;
  }
  return res;
}

bool ch(string &t, string &v) {
  // cout<<t<<" "<<v<<endl;
  if (t.size() != v.size())
    return false;
  bool res = 1;
  rep(i, t.size()) {
    if (t[i] == v[i])
      continue;
    else {
      if (t[i] == '*')
        continue;
      else
        res = 0;
    }
  }
  // cout<<res<<endl;
  return res;
}

int main() {
  vs v;
  int n;
  while (1) {
    string s;
    cin >> s;
    if (isnum(s)) {
      n = STLL(s);
      break;
    } else {
      v.pb(s);
    }
  }
  vs t(n);
  rep(i, n) cin >> t[i];
  vb b(v.size(), false);
  rep(i, n) {
    rep(j, v.size()) {
      if (b[j])
        continue;
      b[j] = ch(t[i], v[j]);
    }
  }
  rep(i, v.size()) {
    if (b[i]) {
      rep(j, v[i].size()) cout << '*';
      if (i != v.size() - 1)
        cout << ' ';
    } else {
      cout << v[i];
      if (i != v.size() - 1)
        cout << ' ';
    }
  }
  cout << endl;
}
