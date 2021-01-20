/*
引用元：https://atcoder.jp/contests/judge-update-202004/tasks/judge_update_202004_d
D - Calculating GCDEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/judge-update-202004/submissions/11782247
// 提出ID : 11782247
// 問題ID : judge_update_202004_d
// コンテストID : judge-update-202004
// ユーザID : xryuseix
// コード長 : 3036
// 実行時間 : 106



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

template <class T> void print_vector(vector<T> &v) {
  rep(i, v.size()) {
    if (!i)
      cout << v[i];
    else
      cout << " " << v[i];
  }
  cout << endl;
}

int main() {

  int n, q;
  cin >> n >> q;
  vi a(n), s(q);
  rep(i, n) cin >> a[i];
  rep(i, q) cin >> s[i];
  vi cgcd(1, a[0]);
  rep(i, n - 1) cgcd.pb(gcd(cgcd[cgcd.size() - 1], a[i + 1]));
  for (int i = 0; i < q; i++) {
    int ng = -1; //これがx以下
    int ok = cgcd.size(); // x以上
    // 問題によってokとngを入れ替える
    while (abs(ok - ng) > 1) {
      // cout<<ok<<" "<<ng<<endl;
      int mid = (ok + ng) / 2;
      if (gcd(cgcd[mid], s[i]) > 1)
        ng = mid;
      else
        ok = mid;
    }
    if (ok != n)
      fin(ok + 1);
    else
      fin(gcd(s[i], cgcd[n - 1]));
  }
}
