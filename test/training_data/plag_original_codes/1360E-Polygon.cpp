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
#define fi first
#define se second
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr double EPS = 1e-9;

// 各座標に格納したい情報を構造体にする
// 今回はX座標,Y座標,深さ(距離)を記述している
struct Corr {
  int x;
  int y;
};
queue<Corr> q;
void bfs(vector<string> &grid) {
  // このような記述をしておくと，この後のfor文が綺麗にかける
  int dx[8] = {-1, 0};
  int dy[8] = {0, -1};
  while (!q.empty()) {
    Corr now = q.front();
    q.pop();

    for (int i = 0; i < 2; i++) {
      int nextx = now.x + dx[i];
      int nexty = now.y + dy[i];

      // 次に探索する場所のX座標がはみ出した時
      if (nextx < 0)
        continue;

      // 次に探索する場所のY座標がはみ出した時
      if (nexty < 0)
        continue;

      // 次に探索する場所が既に探索済みの場合
      if (grid[nexty][nextx] == '0')
        continue;

      grid[nexty][nextx] = '0';
      Corr next = {nextx, nexty};
      q.push(next);
    }
  }
  // rep(i,grid.size()){
  //     dump(grid[i]);
  // }
}

int main() {

  int Q;
  cin >> Q;
  while (Q--) {
    int n;
    cin >> n;
    vs v(n);
    rep(i, n) cin >> v[i];
    rep(i, n) {
      if (v[n - 1][n - 1 - i] == '1') {
        Corr c = {n - i - 1, n - 1};
        v[c.y][c.x] = '0';
        q.push(c);
        bfs(v);
      }
    }
    rep(i, n) {
      if (v[n - 1 - i][n - 1] == '1') {
        Corr c = {n - 1, n - 1 - i};
        v[c.y][c.x] = '0';
        q.push(c);
        bfs(v);
      }
    }
    bool ch = 1;
    rep(i, n) {
      // dump(v[i]);
      rep(j, n) {
        if (v[i][j] == '1')
          ch = 0;
      }
    }
    YN(ch);
  }
}
