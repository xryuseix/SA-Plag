/*
引用元：https://atcoder.jp/contests/arc048/tasks/arc048_b
B - AtCoderでじゃんけんをEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/arc048/submissions/13361371
// 提出ID : 13361371
// 問題ID : arc048_b
// コンテストID : arc048
// ユーザID : xryuseix
// コード長 : 3232
// 実行時間 : 297



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
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
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
  vvi v(1010101, vi(3));
  vi csum(1010101);
  int n;
  cin >> n;
  vi r(n), t(n);
  rep(i, n) {
    cin >> r[i] >> t[i];
    v[r[i]][t[i] - 1]++;
  }
  for (int i = v.size() - 2; i >= 0; i--) {
    int sum = v[i][0] + v[i][1] + v[i][2];
    csum[i] = csum[i + 1] + sum;
  }
  rep(i, n) {
    int w = 0, l = 0, d = 0;
    int sum = v[r[i]][0] + v[r[i]][1] + v[r[i]][2];
    w += n - csum[r[i] + 1] - (sum - 1) - 1;
    l += csum[r[i] + 1];
    if (t[i] == 1) {
      // グー
      w += v[r[i]][1];
      l += v[r[i]][2];
      d += v[r[i]][0] - 1;
    } else if (t[i] == 2) {
      // チョキ
      w += v[r[i]][2];
      l += v[r[i]][0];
      d += v[r[i]][1] - 1;
    } else {
      // パー
      w += v[r[i]][0];
      l += v[r[i]][1];
      d += v[r[i]][2] - 1;
    }
    cout << w << " " << l << " " << d << endl;
  }
}
