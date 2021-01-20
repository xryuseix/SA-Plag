/*
引用元：https://atcoder.jp/contests/arc033/tasks/arc033_3
C - データ構造
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
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
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
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  }
};
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

class Monoid {
public:
  // 単位元
  int unit;

  Monoid() {
    // 単位元
    unit = 0;
  }

  // 演算関数
  int calc(int a, int b) { return a + b; }
};

class SegmentTree {
public:
  // セグメント木の葉の要素数
  int n;

  // セグメント木
  vector<int> tree;

  // モノイド
  Monoid mono;

  SegmentTree(vector<int> &v) {
    n = 1 << (int)ceil(log2(v.size()));
    tree = vector<int>(n << 1);
    for (int i = 0; i < v.size(); i++) {
      update(i, v[i]);
    }
    for (int i = v.size(); i < n; i++) {
      update(i, mono.unit);
    }
  }

  // k番目の値(0-indexed)をxに変更
  void update(int k, int x) {
    k += n;
    tree[k] = x;
    for (k = k >> 1; k > 0; k >>= 1) {
      tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
    }
  }
  // k番目の値(0-indexed)にxを足す変更
  void add(int k, int x) {
    k += n;
    tree[k] += x;
    for (k = k >> 1; k > 0; k >>= 1) {
      tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
    }
  }

  // [l, r)の最小値(0-indexed)を求める．
  int query(int l, int r) {
    int res = mono.unit;
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
  int operator[](int k) {
    // st[i]で添字iの要素の値を返す
    if (k - n >= 0 || k < 0) {
      return -INF;
    }
    return tree[tree.size() - n + k];
  }

  void show() {
    int ret = 2;
    for (int i = 1; i < 2 * n; i++) {
      cout << tree[i] << " ";
      if (i == ret - 1) {
        cout << endl;
        ret <<= 1;
      }
    }
    cout << endl;
  }
};

// vector vの中のn以下の数で最大のものを返す
int bs(vector<int> v, int x) {
  int ok = -1; //これがx以下
  int ng = v.size(); // x以上
  // 問題によってokとngを入れ替える
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (v[mid] <= x)
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

int main(void) {

  int q;
  cin >> q;
  set<int> s;
  vi v(200010, 0);
  SegmentTree st(v);
  rep(_, q) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      s.insert(t);
      st.update(x, st[x] + 1);
    } else {
      x--;
      int ok = -1, ng = 200010;
      for (int i = 0; i < 100; i++) {
        int mid = (ok + ng) / 2;
        if (st.query(0, mid + 1) <= x) {
          ok = mid;
        } else {
          ng = mid;
        }
      }
      cout << ng << endl;
      s.erase(ng);
      st.add(ng, -1);
    }
  }
}
