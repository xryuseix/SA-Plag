/*
引用元：https://atcoder.jp/contests/arc105/tasks/arc105_c
C - Camels and BridgeEditorial
Time Limit : 2 sec / Memory Limit : 1024 MB
配点 : 500 点
*/
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
#include <atcoder/all>
using namespace atcoder;
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline void dump(T& v) {
    irep(i, v) { cout << (*i) << ((i == --v.end()) ? '\n' : ' '); }
}
template <class T, class U>
inline void dump(map<T, U>& v) {
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
template <typename Head, typename Value>
auto vectors(const Head& head, const Value& v) {
    return vector<Value>(head, v);
}
template <typename Head, typename... Tail>
auto vectors(Head x, Tail... tail) {
    auto inner = vectors(tail...);
    return vector<decltype(inner)>(x, inner);
}
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 61;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;
 
/* --------------------   ここまでテンプレ   -------------------- */
template <typename T> class Sum {
public:
  // 単位元
  T unit;

  Sum(void) {
    // 単位元
    unit = 0;
  }

  // 演算関数
  T calc(T a, T b) { return a + b; }
};

template <typename T> struct Max {
public:
  // 単位元
  T unit;

  Max(void) {
    // 単位元
    unit = 0;
  }

  // 演算関数
  T calc(T a, T b) { return max(a, b); }
};

template <typename T, class MONOID> class SegmentTree {
public:
  // セグメント木の葉の要素数
  int n;

  // セグメント木
  vector<T> tree;

  // モノイド
  MONOID mono;

  SegmentTree(vector<T> &v)
      : n(1 << (int)ceil(log2(v.size()))), tree(vector<T>(n << 1, mono.unit)) {
    for (int i = 0; i < v.size(); ++i) {
      tree[i + n] = v[i];
    }
    for (int i = n - 1; i > 0; --i) {
      tree[i] = mono.calc(tree[i << 1 | 0], tree[i << 1 | 1]);
    }
  }

  SegmentTree(int _n)
      : n(1 << (int)ceil(log2(_n))), tree(vector<T>(n << 1, mono.unit)) {}

  // k番目の値(0-indexed)をxに変更
  void update(int k, T x) {
    k += n;
    tree[k] = x;
    for (k = k >> 1; k > 0; k >>= 1) {
      tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
    }
  }

  // k番目の値(0-indexed)をxを加算
  void add(int k, T x) {
    k += n;
    tree[k] += x;
    for (k = k >> 1; k > 0; k >>= 1) {
      tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
    }
  }

  // [l, r)の最小値(0-indexed)を求める．
  T query(int l, int r) {
    T res = mono.unit;
    l += n;
    r += n;
    while (l < r) {
      if (l & 1) {
        res = mono.calc(res, tree[l++]);
      }
      if (r & 1) {
        res = mono.calc(res, tree[--r]);
      }
      l >>= 1;
      r >>= 1;
    }
    return res;
  }

  T operator[](int k) {
    // st[i]で添字iの要素の値を返す
    if (k - n >= 0 || k < 0) {
      return -INF;
    }
    return tree[tree.size() - n + k];
  }

  void show(int elements = 31) {
    int ret = 2;
    for (int i = 1; i < max(2 * n, elements); ++i) {
      if (tree[i] == mono.unit)
        cout << "UNIT ";
      else
        cout << tree[i] << " ";
      if (i == ret - 1) {
        cout << endl;
        ret <<= 1;
      }
    }
    cout << endl;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vi w(n);
  rep(i, n) cin >> w[i];
  vector<pair<int, int>> lv(m);
  rep(i, m) { cin >> lv[i].se >> lv[i].fi; }
  Sort(lv);
  rep(i, n) if (w[i] > lv[0].fi) {
    fin(-1);
    return 0;
  }
  rep(i, lv.size() - 1) chmax(lv[i + 1].se, lv[i].se);

  vi p(n);
  rep(i, n) p[i] = i;
  ll ans = LLINF;
  do {
    vi dp(n, 0);
    for (int i = 0; i < n; i++) {
      int ws = 0;
      for (int j = i; j < n; j++) {
        // cout<<i<<" " <<j<<endl;
        ws += w[p[j]];
        int ei = lower_bound(all(lv), mp(ws, 0)) - lv.begin();
        if (ei) {
          chmax(dp[j], dp[i] + lv[ei - 1].se);
        }
      }
    }
    chmin(ans, (ll)dp[n - 1]);
    // dump(p);
    // dump(dp);
    // fin("");
  } while (next_permutation(all(p)));
  fin(ans);
}
