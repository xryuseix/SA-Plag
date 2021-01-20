/*
引用元：https://atcoder.jp/contests/tenka1-2012-qualC/tasks/tenka1_2012_10
B - ロイヤルストレートフラッシュEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/tenka1-2012-qualC/submissions/12502723
// 提出ID : 12502723
// 問題ID : tenka1_2012_10
// コンテストID : tenka1-2012-qualC
// ユーザID : xryuseix
// コード長 : 4398
// 実行時間 : 1



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
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {

  string s;
  cin >> s;
  vpii v;
  map<char, int> so;
  so['S'] = 0;
  so['H'] = 1;
  so['D'] = 2;
  so['C'] = 3;
  map<int, char> revso;
  revso[0] = 'S';
  revso[1] = 'H';
  revso[2] = 'D';
  revso[3] = 'C';
  rep(i, s.size()) {
    int j = i + 1;
    while (j < s.size() && s[j] != 'S' && s[j] != 'H' && s[j] != 'D' &&
           s[j] != 'C') {
      j++;
    }
    string t = s.substr(i, j - i);
    i = j - 1;
    int num;
    switch (t[1]) {
    case 'A':
      num = 1;
      break;
    case 'J':
      num = 11;
      break;
    case 'Q':
      num = 12;
      break;
    case 'K':
      num = 13;
      break;
    default:
      num = STLL(t.substr(1));
    }
    v.pb(mp(so[t[0]], num));
  }
  int finmark = -1;
  vvi w(4, vi(5, -1));
  rep(i, v.size()) {
    int H = -1, W = -1;
    if (v[i].se == 1) {
      H = v[i].fi;
      W = 4;
    } else if (v[i].se >= 10) {
      H = v[i].fi;
      W = v[i].se - 10;
    } else {
      continue;
    }
    if (w[H][W] == -1) {
      w[H][W] = i;
    }
    bool ch = 1;
    rep(j, 5) {
      if (w[H][j] == -1)
        ch = 0;
    }
    if (ch) {
      finmark = H;
      break;
    }
  }
  vi huda(1, -1);
  rep(i, 5) huda.pb(w[finmark][i]);
  Sort(huda);
  bool sute = 0;
  for (int i = 0; i < huda.size() - 1; i++) {
    for (int j = huda[i] + 1; j < huda[i + 1]; j++) {
      sute = 1;
      cout << revso[v[j].fi];
      if (v[j].se == 1)
        cout << "A";
      else if (v[j].se > 10) {
        if (v[j].se == 11) {
          cout << "J";
        } else if (v[j].se == 12) {
          cout << "Q";
        } else if (v[j].se == 13) {
          cout << "K";
        }
      } else {
        cout << v[j].se;
      }
    }
  }
  if (!sute)
    cout << "0";
  cout << endl;
}
