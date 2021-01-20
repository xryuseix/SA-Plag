/*
引用元：https://atcoder.jp/contests/abc045/tasks/arc061_b
D - すぬけ君の塗り絵 / Snuke's Coloring
Time Limit : 3 sec / Memory Limit : 256 MB
配点 : 400 点
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
  }
};
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {

  ll ans[10] = {0};

  int h, w, n;
  cin >> h >> w >> n;

  map<pair<int, int>, int> m;

  int dx[] = {-2, -1, 0, -2, -1, 0, -2, -1, 0};
  int dy[] = {-2, -2, -2, -1, -1, -1, 0, 0, 0};
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    rep(j, 9) {
      if (b + dx[j] < 0 || b + dx[j] + 2 >= w || a + dy[j] < 0 ||
          a + dy[j] + 2 >= h)
        continue;
      m[mp(b + dx[j], a + dy[j])]++;
    }
  }

  for (auto it = m.begin(); it != m.end(); it++) {
    ans[it->second]++;
  }
  ans[0] = (h - 2) * (ll)(w - 2);
  rep(i, 9) { ans[0] -= ans[i + 1]; }
  rep(i, 10) { cout << ans[i] << endl; }
}
