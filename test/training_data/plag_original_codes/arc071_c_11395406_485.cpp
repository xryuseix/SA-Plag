/*
引用元：https://atcoder.jp/contests/arc071/tasks/arc071_c
E - TrBBnsformBBtionEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/arc071/submissions/11395406
// 提出ID : 11395406
// 問題ID : arc071_c
// コンテストID : arc071
// ユーザID : xryuseix
// コード長 : 2587
// 実行時間 : 290



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
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
inline string getline() {
  string s;
  getline(cin, s);
  return s;
}
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
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

int main() {

  string s, t;
  cin >> s >> t;
  vi Scsum(1, 0), Tcsum(1, 0);
  rep(i, s.size()) {
    if (s[i] == 'A')
      Scsum.pb(*Scsum.rbegin() + 1);
    else
      Scsum.pb(*Scsum.rbegin() + 2);
  }
  rep(i, t.size()) {
    if (t[i] == 'A')
      Tcsum.pb(*Tcsum.rbegin() + 1);
    else
      Tcsum.pb(*Tcsum.rbegin() + 2);
  }
  int q;
  cin >> q;
  rep(i, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sA = Scsum[b] - Scsum[a - 1];
    int tA = Tcsum[d] - Tcsum[c - 1];
    YN(sA % 3 == tA % 3);
  }
}
