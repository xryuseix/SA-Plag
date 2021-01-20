/*
引用元：https://atcoder.jp/contests/abc040/tasks/abc040_d
D - 道路の老朽化対策について
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
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
const ll MOD = 1000000007;
const double EPS = 1e-9;
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

  ll n, m;
  cin >> n >> m;
  vector<pair<ll, pair<ll, ll>>> v;
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    v.pb(mp(c, mp(a, b)));
  }
  ll q;
  cin >> q;
  vector<pair<ll, pair<ll, ll>>> qe;
  rep(i, q) {
    ll a, b;
    cin >> a >> b;
    a--;
    qe.pb(mp(b, mp(a, i)));
  }
  Rort(qe);
  Rort(v);

  UnionFind uni(n);
  ll pos = 0;
  vector<pair<ll, ll>> ans;
  for (int i = 0; i < q; i++) {
    // cout<<v[pos].first<<" "<<qe[i].first<<endl;
    while (pos < m && v[pos].first > qe[i].first) {
      uni.connect(v[pos].second.first, v[pos].second.second);
      pos++;
    }
    // cout<<pos<<endl;
    ans.pb(mp(qe[i].second.second, uni.size(qe[i].second.first)));
  }
  Sort(ans);
  rep(i, ans.size()) { cout << ans[i].second << endl; }
}
