/*
引用元：https://atcoder.jp/contests/past202004-open/tasks/past202004_j
J - ParseEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past202004-open/submissions/12804533
// 提出ID : 12804533
// 問題ID : past202004_j
// コンテストID : past202004-open
// ユーザID : xryuseix
// コード長 : 3558
// 実行時間 : 3



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
#define itn int
// #define endl '\n';
#define fi first
#define se second
#define NONVOID [[nodiscard]]
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

template <class T> void lambdaSort(vector<T> &v) {
  sort(all(v), [](auto const &l, auto const &r) {
    return l.se < r.se; // このbool式が成り立つ時入れ替える
  });
}

int main() {

  vpii v;
  string s;
  cin >> s;
  rep(i, s.size()) {
    if (s[i] != '(')
      continue;
    int sum = 0;
    int right = i;
    for (int j = i; j < s.size(); j++) {
      if (s[j] == '(')
        sum++;
      else if (s[j] == ')')
        sum--;
      if (sum == 0) {
        right = j;
        break;
      }
    }
    v.pb(mp(i, right));
  }
  if (v.size() == 0) {
    fin(s);
    return 0;
  }
  lambdaSort(v);
  // rep(i,v.size())cout<<v[i].fi<<" "<<v[i].se<<endl;
  rep(i, v.size()) {
    string L = s.substr(0, v[i].fi);
    string R = s.substr(v[i].se + 1);
    string M = s.substr(v[i].fi + 1, v[i].se - v[i].fi - 1);
    int plus = M.size() - 2;
    for (int j = i + 1; j < v.size(); j++) {
      v[j].se += plus;
      if (v[i].fi < v[j].fi)
        v[j].fi += plus;
    }
    string rM = M;
    reverse(all(rM));
    s = L + M + rM + R;
  }
  cout << s << endl;
}
