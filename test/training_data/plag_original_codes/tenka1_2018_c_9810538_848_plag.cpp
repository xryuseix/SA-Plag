/*
引用元：https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c
C - Align
Time Limit : 2 sec / Memory Limit : 1024 MB
配点 : 400 点
*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
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
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

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
    int n;
    cin >> n;
    if (n < 8) {
        vi v(n), res;
        int m = 0;
        rep(i, n) cin >> v[i];
        Sort(v);
        do {
            int diff = 0;
            rep(i, n - 1) { diff += abs(v[i] - v[i + 1]); }
            if (diff > m) {
                m = diff;
                res.clear();
                rep(i, n) { res.pb(v[i]); }
            }
        } while (next_permutation(all(v)));
        fin(m);
    } else {
        ll p1 = 0, p2 = 0;
        vi v(n);
        rep(i, n) cin >> v[i];
        Sort(v);
        if (n % 2 == 1) {
            rep(i, n / 2) p1 -= 2 * v[i];
            for (int i = n / 2; i < n / 2 + 2; i++) p1 += v[i];
            for (int i = n / 2 + 2; i < n; i++) p1 += 2 * v[i];

            rep(i, n / 2 - 1) p2 -= 2 * v[i];
            for (int i = n / 2 - 1; i < n / 2 + 1; i++) p2 -= v[i];
            for (int i = n / 2 + 1; i < n; i++) p2 += 2 * v[i];
        } else {
            p1 += v[n / 2] - v[n / 2 - 1];
            rep(i, n / 2 - 1) p1 -= 2 * v[i];
            for (int i = n / 2 + 1; i < n; i++) p1 += 2 * v[i];
        }
        fin(max(p1, p2));
    }
}
