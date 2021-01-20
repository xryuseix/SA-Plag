/*
引用元：https://atcoder.jp/contests/abc020/tasks/abc020_c
C - 壁抜け
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
constexpr ld EPS = 1e-11;
// 各座標に格納したい情報を構造体にする
// 今回はX座標,Y座標,深さ(距離)を記述している
struct Corr {
  int x;
  int y;
  ll depth;
};
queue<Corr> q;
ll bfs(vs &grid, ll loss, int gx, int gy, int sx, int sy) {
  // 既に探索の場所を1，探索していなかったら0を格納する配列
  vector<vector<int>> ispassed(grid.size(), vector<int>(grid[0].size(), false));
  vvll ans(grid.size(), vector<ll>(grid[0].size(), LLINF));
  // このような記述をしておくと，この後のfor文が綺麗にかける
  int dx[8] = {1, 0, -1, 0};
  int dy[8] = {0, 1, 0, -1};
  ispassed[sy][sx] = true;
  ans[sy][sx] = 0;
  while (!q.empty()) {
    Corr now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nextx = now.x + dx[i];
      int nexty = now.y + dy[i];
      ll nextd = now.depth;

      // 次に探索する場所のX座標がはみ出した時
      if (nextx >= grid[0].size())
        continue;
      if (nextx < 0)
        continue;

      // 次に探索する場所のY座標がはみ出した時
      if (nexty >= grid.size())
        continue;
      if (nexty < 0)
        continue;

      // 次に探索する場所が既に探索済みの場合
      // if(ispassed[nexty][nextx]) continue;
      if (grid[nexty][nextx] == '#')
        nextd += loss;
      else
        nextd += 1;

      ispassed[nexty][nextx] = true;
      if (ans[nexty][nextx] > nextd) {
        ans[nexty][nextx] = nextd;
        Corr next = {nextx, nexty, nextd};
        q.push(next);
      }
    }
  }
  // if(loss==6){
  //     rep(i,2)dump(ans[i]);
  // }
  return ans[gy][gx];
}

bool solve(int h, int y, ll t, int sx, int sy, int gx, int gy, vs &v, ll loss) {
  while (!q.empty())
    q.pop();
  Corr c = {sx, sy, 0};
  q.push(c);
  ll ans = bfs(v, loss, gx, gy, sx, sy);
  // cout<<loss<<" "<<ans<<endl;
  return ans <= t;
}

int main() {

  int h, w, t;
  cin >> h >> w >> t;
  vs v(h);
  rep(i, h) cin >> v[i];
  int sx, sy, gx, gy;
  rep(i, h) rep(j, w) {
    if (v[i][j] == 'S') {
      sx = j;
      sy = i;
    }
    if (v[i][j] == 'G') {
      gx = j;
      gy = i;
    }
  }
  // vector vの中のn以下の数で最大のものを返す
  ll ok = -1; //これがx以下
  ll ng = 2e9; // x以上
  // 問題によってokとngを入れ替える
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (solve(h, w, t, sx, sy, gx, gy, v, mid))
      ok = mid;
    else
      ng = mid;
  }
  fin(ok);
}
