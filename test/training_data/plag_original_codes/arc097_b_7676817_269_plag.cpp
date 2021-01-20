/*
引用元：https://atcoder.jp/contests/abc097/tasks/arc097_b
D - EqualsEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc097/submissions/7676817
// 提出ID : 7676817
// 問題ID : arc097_b
// コンテストID : abc097
// ユーザID : xryuseix
// コード長 : 3288
// 実行時間 : 28



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
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
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
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

class UnionFind {
public:
  // 親の番号を格納．親だった場合は-(その集合のサイズ)
  vector<int> Parent;
  // 重さの差を格納
  vector<ll> diffWeight;

  UnionFind(const int N) {
    Parent = vector<int>(N, -1);
    diffWeight = vector<ll>(N, 0);
  }

  // Aがどのグループに属しているか調べる
  int root(const int A) {
    if (Parent[A] < 0) return A;
    int Root = root(Parent[A]);
    diffWeight[A] += diffWeight[Parent[A]];
    return Parent[A] = Root;
  }

  // 自分のいるグループの頂点数を調べる
  int size(const int A) {
    return -Parent[root(A)];
  }

  // 自分の重さを調べる
  ll weight(const int A) {
    root(A); // 経路圧縮
    return diffWeight[A];
  }

  // 重さの差を計算する
  ll diff(const int A, const int B) {
    return weight(B) - weight(A);
  }

  // AとBをくっ付ける
  bool connect(int A, int B, ll W = 0) {
    // Wをrootとの重み差分に変更
    W += weight(A);
    W -= weight(B);

    // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
    A = root(A);
    B = root(B);

    if (A == B) {
      //すでにくっついてるからくっ付けない
      return false;
    }

    // 大きい方(A)に小さいほう(B)をくっ付ける
    // 大小が逆だったらひっくり返す
    if (size(A) < size(B)) {
      swap(A, B);
      W = -W;
    }

    // Aのサイズを更新する
    Parent[A] += Parent[B];
    // Bの親をAに変更する
    Parent[B] = A;

    // AはBの親であることが確定しているのでBにWの重みを充てる
    diffWeight[B] = W;

    return true;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int n, m;
  cin >> n >> m;
  vi p(n);
  rep(i, n) cin >> p[i];

  UnionFind Uni(n);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (Uni.root(x) != Uni.root(y)) {
      Uni.connect(x, y);
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (Uni.root(p[i] - 1) == Uni.root(i)) {
      ans++;
    }
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}
