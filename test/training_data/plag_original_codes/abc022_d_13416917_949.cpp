/*
引用元：https://atcoder.jp/contests/abc022/tasks/abc022_d
D - Big Bang
Time Limit : 2 sec / Memory Limit : 256 MB
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
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define arep(i, v) for (auto i : v)
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
#define fi first
#define se second
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
template <class T> inline void dump(T &v) {
  irep(i, v) { cout << *i << ((i == --v.end()) ? '\n' : ' '); }
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
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr double EPS = 1e-9;

int main() {

  double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  int n;
  cin >> n;
  vpii v(n), w(n);
  rep(i, n) {
    double a, b;
    cin >> a >> b;
    v[i] = mp(a, b);
    x1 += a;
    y1 += b;
  }
  rep(i, n) {
    double a, b;
    cin >> a >> b;
    w[i] = mp(a, b);
    x2 += a;
    y2 += b;
  }

  x1 /= n;
  x2 /= n;
  y1 /= n;
  y2 /= n;
  double disA = 0;
  double disB = 0;
  rep(i, n) {
    chmax(disA, sqrt((v[i].fi - x1) * (v[i].fi - x1) +
                     (v[i].se - y1) * (v[i].se - y1)));
    chmax(disB, sqrt((w[i].fi - x2) * (w[i].fi - x2) +
                     (w[i].se - y2) * (w[i].se - y2)));
  }
  if (disA == 0) {
    double ans = (w[0].se * w[0].se + w[0].fi * w[0].fi) /
                 (v[0].se * v[0].se + v[0].fi * v[0].fi);
    printf("%.6f\n", ans);
  } else {
    printf("%.6f\n", disB / disA);
  }
}
