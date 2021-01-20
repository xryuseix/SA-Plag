/*
引用元：https://atcoder.jp/contests/m-solutions2019/tasks/m_solutions2019_d
D - Maximum Sum of MinimumEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/m-solutions2019/submissions/8388371
// 提出ID : 8388371
// 問題ID : m_solutions2019_d
// コンテストID : m-solutions2019
// ユーザID : xryuseix
// コード長 : 2377
// 実行時間 : 12



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
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
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
  };
};
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int num = 0;

void dfs(vi &score, vi &c, vvi &G, int pos) {
  score[pos] = c[num];
  for (int i = 0; i < G[pos].size(); i++) {
    if (score[G[pos][i]] == -1) {
      num++;
      dfs(score, c, G, G[pos][i]);
    }
  }
  return;
}

int main(void) {

  int n;
  cin >> n;
  vvi G(n);
  vi l(n - 1), r(n - 1);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
    l[i] = a - 1;
    r[i] = b - 1;
  }
  vi c(n);
  rep(i, n) cin >> c[i];
  Rort(c);
  vi score(n, -1);

  dfs(score, c, G, 0);
  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += min(score[l[i]], score[r[i]]);
  }
  fin(ans);
  for (int i = 0; i < n; i++) {
    if (i == 0)
      cout << score[i];
    else
      cout << " " << score[i];
  }
  cout << endl;
}
