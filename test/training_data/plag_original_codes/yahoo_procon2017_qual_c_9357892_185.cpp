/*
引用元：https://atcoder.jp/contests/yahoo-procon2017-qual/tasks/yahoo_procon2017_qual_c
C - 検索
Time Limit : 2 sec / Memory Limit : 256 MB
配点 : 400 点
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
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
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
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

string calc(string &s, string &t) {
  string res = "";
  for (int i = 0; i < min(s.size(), t.size()); i++) {
    if (s[i] == t[i]) {
      res += s[i];
    } else
      break;
  }
  return res;
}

int main(void) {

  int n, k;
  cin >> n >> k;

  vi a(k);
  vi b;
  set<int> s;
  rep(i, k) {
    cin >> a[i];
    a[i]--;
    s.insert(a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (!s.count(i))
      b.push_back(i);
  }
  vs v(n);
  rep(i, n) cin >> v[i];
  string str = v[a[0]];
  for (int i = 1; i < k; i++) {
    str = calc(str, v[a[i]]);
  }

  int len = -1;
  for (int i = 0; i < b.size(); i++) {
    string tmp = calc(str, v[b[i]]);
    len = max(len, (int)tmp.size());
  }

  if (len == str.size())
    fin(-1);
  else
    fin(str.substr(0, len + 1));
}
