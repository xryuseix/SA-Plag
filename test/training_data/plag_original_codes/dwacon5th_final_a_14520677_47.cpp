/*
引用元：https://atcoder.jp/contests/dwacon5th-final/tasks/dwacon5th_final_a
A - Taro vs. Jiro
Time Limit : 2.525 sec / Memory Limit : 1024 MB
配点 : 500 点
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
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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
constexpr ld EPS = 1e-11;

vb f(101010, 0), s(101010, 0);

int main() {

  ll n, m, k;
  cin >> n >> m >> k;
  string S;
  cin >> S;
  vvi v(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].pb(b);
    v[b].pb(a);
  }
  rep(i, n) {
    if (S[i] == 'B') {
      for (auto j : v[i]) {
        f[j] = 1;
      }
    } else {
      for (auto j : v[i]) {
        s[j] = 1;
      }
    }
  }
  // cout<<"F; "<<f[0]<<" "<<f[1]<<endl;
  // cout<<"S; "<<s[0]<<" "<<s[1]<<endl;
  k %= 2;
  string ans[] = {"First", "Second"};
  for (int i = 0; i < n; i++) {
    if (k == 1) {
      if (f[i])
        fin(ans[0]);
      else
        fin(ans[1]);
    } else {
      bool ch = 0;
      for (auto j : v[i]) {
        if (!s[j]) {
          fin(ans[0]);
          ch = 1;
          break;
        }
      }
      if (!ch) {
        fin(ans[1]);
      }
    }
  }
}
