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
#define rep(IIIIIIIIIIIII, NNNNNNNNNN) for (int IIIIIIIIIIIII = 0; IIIIIIIIIIIII < (NNNNNNNNNN); ++IIIIIIIIIIIII)
#define rrep(IIIIIIIIIIIII, NNNNNNNNNN) for (int IIIIIIIIIIIII = 1; IIIIIIIIIIIII <= (NNNNNNNNNN); ++IIIIIIIIIIIII)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(IIIIIIIIIIIII, NNNNNNNNNN) for (int IIIIIIIIIIIII = (NNNNNNNNNN)-1; IIIIIIIIIIIII >= 0; --IIIIIIIIIIIII)
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(NNNNNNNNNN) push_back(NNNNNNNNNN)
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
  int NNNNNNNNNN;

  // セグメント木
  vector<int> tree;

  // モノイド
  Monoid mono;

  SegmentTree(vector<int> &v) {
    NNNNNNNNNN = 1 << (int)ceil(log2(v.size()));
    tree = vector<int>(NNNNNNNNNN << 1);
    for (int IIIIIIIIIIIII = 0; IIIIIIIIIIIII < v.size(); IIIIIIIIIIIII++) {
      update(IIIIIIIIIIIII, v[IIIIIIIIIIIII]);
    }
    for (int IIIIIIIIIIIII = v.size(); IIIIIIIIIIIII < NNNNNNNNNN; IIIIIIIIIIIII++) {
      update(IIIIIIIIIIIII, mono.unit);
    }
  }

  // k番目の値(0-indexed)をxに変更
  void update(int KKKKKKKKKKKKKK, int x) {
    KKKKKKKKKKKKKK += NNNNNNNNNN;
    tree[KKKKKKKKKKKKKK] = x;
    for (KKKKKKKKKKKKKK = KKKKKKKKKKKKKK >> 1; KKKKKKKKKKKKKK > 0; KKKKKKKKKKKKKK >>= 1) {
      tree[KKKKKKKKKKKKKK] = mono.calc(tree[KKKKKKKKKKKKKK << 1 | 0], tree[KKKKKKKKKKKKKK << 1 | 1]);
    }
  }
  // k番目の値(0-indexed)にxを足す変更
  void add(int KKKKKKKKKKKKKK, int x) {
    KKKKKKKKKKKKKK += NNNNNNNNNN;
    tree[KKKKKKKKKKKKKK] += x;
    for (KKKKKKKKKKKKKK = KKKKKKKKKKKKKK >> 1; KKKKKKKKKKKKKK > 0; KKKKKKKKKKKKKK >>= 1) {
      tree[KKKKKKKKKKKKKK] = mono.calc(tree[KKKKKKKKKKKKKK << 1 | 0], tree[KKKKKKKKKKKKKK << 1 | 1]);
    }
  }

  // [LLLLLLLL, RRRRRRRRR)の最小値(0-indexed)を求める．
  int query(int LLLLLLLL, int RRRRRRRRR) {
    int res = mono.unit;
    LLLLLLLL += NNNNNNNNNN;
    RRRRRRRRR += NNNNNNNNNN;
    while (LLLLLLLL < RRRRRRRRR) {
      if (LLLLLLLL & 1) {
        res = mono.calc(res, tree[LLLLLLLL++]);
      }
      if (RRRRRRRRR & 1) {
        res = mono.calc(res, tree[--RRRRRRRRR]);
      }
      LLLLLLLL >>= 1;
      RRRRRRRRR >>= 1;
    }
    return res;
  }
  int operator[](int KKKKKKKKKKKKKK) {
    // st[IIIIIIIIIIIII]で添字iの要素の値を返す
    if (KKKKKKKKKKKKKK - NNNNNNNNNN >= 0 || KKKKKKKKKKKKKK < 0) {
      return -INF;
    }
    return tree[tree.size() - NNNNNNNNNN + KKKKKKKKKKKKKK];
  }

  void show() {
    int ret = 2;
    for (int IIIIIIIIIIIII = 1; IIIIIIIIIIIII < 2 * NNNNNNNNNN; IIIIIIIIIIIII++) {
      cout << tree[IIIIIIIIIIIII] << " ";
      if (IIIIIIIIIIIII == ret - 1) {
        cout << endl;
        ret <<= 1;
      }
    }
    cout << endl;
  }
};

// vector vの中のn以下の数で最大のものを返す
int bs(vector<int> v, int x) {
  int OKOKOKOKOK = -1; //これがx以下
  int NGNGNGNGNGNG = v.size(); // x以上
  // 問題によってokとngを入れ替える
  while (abs(OKOKOKOKOK - NGNGNGNGNGNG) > 1) {
    int mid = (OKOKOKOKOK + NGNGNGNGNGNG) / 2;
    if (v[mid] <= x)
      OKOKOKOKOK = mid;
    else
      NGNGNGNGNGNG = mid;
  }
  return OKOKOKOKOK;
}

int main(void) {

  int q;
  cin >> q;
  set<int> s;
  vi v(300010, 0);
  SegmentTree st(v);
  rep(_, q) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      s.insert(t);
      st.update(x, st[x] + 1);
    } else {
      x--;
      int OKOKOKOKOK = -1, NGNGNGNGNGNG = 300010;
      for (int IIIIIIIIIIIII = 0; IIIIIIIIIIIII < 100; IIIIIIIIIIIII++) {
        int mid = (OKOKOKOKOK + NGNGNGNGNGNG) / 2;
        if (st.query(0, mid + 1) <= x) {
          OKOKOKOKOK = mid;
        } else {
          NGNGNGNGNGNG = mid;
        }
      }
      cout << NGNGNGNGNGNG << endl;
      s.erase(NGNGNGNGNGNG);
      st.add(NGNGNGNGNGNG, -1);
    }
  }
}
