/*
引用元：https://atcoder.jp/contests/past201912-open/tasks/past201912_h
H - Bulk SellingEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past201912-open/submissions/11745221
// 提出ID : 11745221
// 問題ID : past201912_h
// コンテストID : past201912-open
// ユーザID : xryuseix
// コード長 : 3384
// 実行時間 : 195



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
#define endl '\n';
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

  ll allMin = INF, oddMin = INF;
  ll n, x, a, Q, q;
  ll allSum = 0, oddSum = 0;
  cin >> n;
  vll c(n);
  rep(i, n) cin >> c[i];
  rep(i, n) {
    chmin(allMin, c[i]);
    if (i % 2 == 0)
      chmin(oddMin, c[i]);
  }
  ll ans = 0;
  cin >> Q;
  while (Q--) {
    cin >> q;
    if (q == 1) {
      cin >> x >> a;
      x--;
      if ((x % 2 == 0 && c[x] - oddSum - allSum >= a) ||
          (x % 2 == 1 && c[x] - allSum >= a)) {
        c[x] -= a;
        ans += a;
        if (x % 2 == 0)
          chmin(oddMin, c[x]);
        chmin(allMin, c[x]);
      }
    } else if (q == 2) {
      cin >> a;
      if (oddMin >= a) {
        ll num = ceil(n / 2.0);
        ans += num * a;
        oddMin -= a;
        oddSum += a;
        chmin(allMin, oddMin);
      }
    } else if (q == 3) {
      cin >> a;
      if (allMin >= a) {
        ans += n * a;
        oddMin -= a;
        allMin -= a;
        allSum += a;
        chmin(allMin, oddMin);
      }
    }
    // cout<<ans<<" "<<oddMin<<" "<<allMin<<endl;
  }
  fin(ans);
}
