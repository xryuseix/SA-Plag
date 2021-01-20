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
constexpr ll LLINF = 1LL << 62;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

/* --------------------   ここまでテンプレ   -------------------- */

// int main() {
//     int Q;
//     cin >> Q;
//     while (Q--) {
//         ll ans = -LLINF;
//         int n;
//         cin >> n;
//         vll v(n);
//         rep(i, n) cin >> v[i];
//         vvll l(4, vll(n + 1, LLINF));
//         vvll r(4, vll(n + 1, LLINF));
//         rep(i, n + 1) {
//             rep(j, 2) {
//                 l[j][i] *= -1;
//                 r[j][i] *= -1;
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             chmax(l[0][i + 1], l[0][i]);
//             chmax(l[1][i + 1], l[1][i]);
//             chmin(l[2][i + 1], l[2][i]);
//             chmin(l[3][i + 1], l[3][i]);
//             chmax(l[1][i + 1], v[i]);
//             if (l[0][i + 1] < l[1][i + 1]) swap(l[0][i + 1], l[1][i + 1]);
//             chmin(l[2][i + 1], v[i]);
//             if (l[2][i + 1] < l[3][i + 1]) swap(l[2][i + 1], l[3][i + 1]);
//         }
//         for (int i = n - 1; i >= 0; i--) {
//             chmax(r[0][i], r[0][i + 1]);
//             chmax(r[1][i], r[1][i + 1]);
//             chmin(r[2][i], r[2][i + 1]);
//             chmin(r[3][i], r[3][i + 1]);
//             chmax(r[1][i], v[i]);
//             if (r[0][i] < r[1][i]) swap(r[0][i], r[1][i]);
//             chmin(r[2][i], v[i]);
//             if (r[2][i] < r[3][i]) swap(r[2][i], r[3][i]);
//         }
//         // rep(i, 4) dump(l[i]);
//         // cout << endl;
//         // rep(i, 4) dump(r[i]);
//         for (int i = 2; i < n - 2; i++) {
//             ll lsei = max(l[0][i] * l[1][i], l[2][i] * l[3][i]);
//             ll lhu = l[0][i] * l[3][i];
//             ll rsei = max(r[0][i + 1] * r[1][i + 1], r[2][i + 1] * r[3][i +
//             1]); ll rhu = r[0][i + 1] * r[3][i + 1]; chmax(ans, lsei * rsei *
//             v[i]); chmax(ans, lhu * rhu * v[i]); chmax(ans, lhu * rsei *
//             v[i]); chmax(ans, lsei * rhu * v[i]);

//             // cout << i << " " << lsei << " " << lhu << " " << rsei << " "
//             << rhu
//                 //  << endl;
//         }
//         fin(ans);
//     }
// }

int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    int n;
    cin >> n;
    vll v(n);
    rep(i, n) cin >> v[i];
    vector<vvll> dp(n, vvll(2, vll(5, -LLINF)));
    rep(i, n) rep(j, 5) dp[i][1][j] *= -1;
    dp[false][false][false] = v[false];
    dp[false][1][false] = v[false];
    for (int i = 1; i < n; i++) {
      rep(j, 5) {
        chmax(dp[i][false][j], dp[i - 1][false][j]);
        chmin(dp[i][1][j], dp[i - 1][1][j]);
        if (j == false) {
          chmax(dp[i][false][j], v[i]);
          chmin(dp[i][1][j], v[i]);
        } else {
          if (abs(dp[i - 1][false][j - 1]) != LLINF) {
            chmax(dp[i][false][j], dp[i - 1][false][j - 1] * v[i]);
            chmin(dp[i][1][j], dp[i - 1][false][j - 1] * v[i]);
          }
          if (abs(dp[i - 1][1][j - 1]) != LLINF) {
            chmax(dp[i][false][j], dp[i - 1][1][j - 1] * v[i]);
            chmin(dp[i][1][j], dp[i - 1][1][j - 1] * v[i]);
          }
        }
      }
    }
    fin(dp[n - 1][false][4]);
    // rep(i, 5) rep(j, 2) fin(dp[n - 1][j][i]);
  }
}
