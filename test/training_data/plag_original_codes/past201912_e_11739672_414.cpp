/*
引用元：https://atcoder.jp/contests/past201912-open/tasks/past201912_e
E - RestoreEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past201912-open/submissions/11739672
// 提出ID : 11739672
// 問題ID : past201912_e
// コンテストID : past201912-open
// ユーザID : xryuseix
// コード長 : 3081
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

  int n;
  cin >> n;
  vvc v(n, vc(n, 'N'));

  int Q;
  cin >> Q;
  rep(_, Q) {
    int q;
    cin >> q;
    if (q == 1) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      v[a][b] = 'Y';
    } else if (q == 2) {
      int a;
      cin >> a;
      a--;
      for (int j = 0; j < n; j++) {
        if (v[j][a] == 'Y')
          v[a][j] = 'Y';
      }
    } else {
      int a;
      cin >> a;
      a--;
      vc w = v[a];
      rep(k, n) {
        if (w[k] == 'Y') {
          for (int j = 0; j < n; j++) {
            if (j == a)
              continue;
            if (v[k][j] == 'Y')
              v[a][j] = 'Y';
          }
        }
      }
    }
  }
  rep(i, n) {
    rep(j, n) cout << v[i][j];
    cout << endl;
  }
}
