#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
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
// #include <atcoder/all>
// using namespace atcoder;
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
  irep(i, v) { cout << (*i) << ((i == --v.end()) ? '\n' : ' '); }
}
template <class T, class U> inline void dump(map<T, U> &v) {
  irep(i, v) { cout << i->first << " " << i->second << '\n'; }
}
inline string getline() {
  string s;
  fflush(stdin);
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
template <typename Head, typename Value>
auto vectors(const Head &head, const Value &v) {
  return vector<Value>(head, v);
}
template <typename Head, typename... Tail> auto vectors(Head x, Tail... tail) {
  auto inner = vectors(tail...);
  return vector<decltype(inner)>(x, inner);
}
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 61;
constexpr ll MOD = 1000000007; // 998244353;
constexpr ld EPS = 1e-11;

/* --------------------   ここまでテンプレ   -------------------- */

int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    int n;
    cin >> n;
    vi v(n);
    rep(i, n) cin >> v[i];
    int odd = 0;
    int even = 0;
    rep(i, n) {
      if (v[i] % 2 == 1)
        odd++;
      else
        even++;
    }
    if (n % 2 == 0) {
      if (odd != even) {
        fin(-1);
        continue;
      }
    } else {
      // cout<<odd<<" "<<even<<endl;
      if (odd + 1 != even) {
        fin(-1);
        continue;
      }
    }
    int ans = 0;
    rep(i, n) {
      if (v[i] % 2 == i % 2)
        continue;
      for (int j = i + 1; j < n; j++) {
        if (v[j] % 2 == i % 2 && v[j] % 2 != j % 2) {
          ans++;
          swap(v[i], v[j]);
          break;
        }
      }
    }
    fin(ans);
  }
}
