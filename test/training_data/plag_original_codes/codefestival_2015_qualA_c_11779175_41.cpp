/*
引用元：https://atcoder.jp/contests/code-festival-2015-quala/tasks/codefestival_2015_qualA_c
C - 8月31日Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-festival-2015-quala/submissions/11779175
// 提出ID : 11779175
// 問題ID : codefestival_2015_qualA_c
// コンテストID : code-festival-2015-quala
// ユーザID : xryuseix
// コード長 : 2922
// 実行時間 : 59



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
#include <random>
#include <iomanip>
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
typedef map<int, int> mii;
typedef set<int> si;
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
#define itn int
// #define endl '\n';
#define fi first
#define se second
#define NONVOID [[nodiscard]]
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

  int n, m;
  cin >> n >> m;
  vpii v(n);
  rep(i, n) cin >> v[i].fi >> v[i].se;
  sort(all(v), [](auto const &lhs, auto const &rhs) {
    return lhs.fi - lhs.se >
           rhs.fi - rhs.se; // このbool式が成り立つ時入れ替える
  });
  int sum1 = 0, sum2 = 0;
  rep(i, n) {
    sum1 += v[i].fi;
    sum2 += min(v[i].fi, v[i].se);
  }
  if (sum2 > m) {
    fin(-1);
    return 0;
  }
  if (sum1 <= m) {
    fin(0);
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans++;
    sum1 = sum1 - v[i].fi + v[i].se;
    // cout<<sum1<<" "<<v[i].fi<<" "<<v[i].se<<endl;
    if (sum1 <= m)
      break;
  }
  fin(ans);
}
