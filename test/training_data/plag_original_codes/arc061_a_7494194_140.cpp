/*
引用元：https://atcoder.jp/contests/abc045/tasks/arc061_a
C - Many FormulasEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc045/submissions/7494194
// 提出ID : 7494194
// 問題ID : arc061_a
// コンテストID : abc045
// ユーザID : xryuseix
// コード長 : 2527
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
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
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
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

ll ans = 0;

ll sum(vector<ll> v) {
  ll res = 0;
  rep(i, v.size()) res += v[i];
  return res;
}

vector<ll> StI(string &s) {
  vector<ll> res;
  for (int i = 0; i < s.length(); i++) {
    ll tmp = 0;
    ll j = 0;
    while (i + j < s.length() && s[i + j] != '+') {
      tmp *= 10;
      tmp += s[i + j] - '0';
      j++;
    }
    i += j;
    res.push_back(tmp);
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  string s;
  cin >> s;

  for (int bit = 0; bit < pow(2, s.length() - 1); bit++) {
    string t = "";
    ll tmp = bit;
    while (tmp > 0) {
      t += tmp % 2 + '0';
      tmp /= 2;
    }
    while (s.size() > t.size()) {
      t = t + '0';
    }
    reverse(t.begin(), t.end());

    string sti = "";
    for (int i = 0; i < s.length(); i++) {
      if (t[i] == '1' && i != 0)
        sti += '+';
      sti += s[i];
    }
    vector<ll> v = StI(sti);
    ans += sum(v);
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
