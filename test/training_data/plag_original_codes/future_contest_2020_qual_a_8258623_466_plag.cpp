/*
引用元：https://atcoder.jp/contests/future-contest-2020-qual/tasks/future_contest_2020_qual_a
A - ロボットの誘導Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/future-contest-2020-qual/submissions/8258623
// 提出ID : 8258623
// 問題ID : future_contest_2020_qual_a
// コンテストID : future-contest-2020-qual
// ユーザID : xryuseix
// コード長 : 7478
// 実行時間 : 2664



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

int main(void) {

  int n, m, b;
  cin >> n >> m >> b;
  int gy, gx;
  cin >> gy >> gx;
  vi ry(m), rx(m);
  vc c(m);
  rep(i, m) { cin >> ry[i] >> rx[i] >> c[i]; }
  vi by(b), bx(b);
  rep(i, b) { cin >> by[i] >> bx[i]; }

  vvi grid(n, vi(n, 0));
  // 0..何もなし
  // 1..ロボット
  // 2..ブロック
  // 3..ゴール

  vvi info(n, vi(n, 0));
  // 0..何もなし
  // 1..案内板(上)
  // 2..案内板(右)
  // 3..案内板(下)
  // 4..案内板(左)
  //ゴールを設置
  grid[gy][gx] = 3;

  //ロボットとその向きを設置
  vi muki(m);
  rep(i, m) {
    if (c[i] == 'U')
      muki[i] = 1;
    if (c[i] == 'R')
      muki[i] = 2;
    if (c[i] == 'D')
      muki[i] = 3;
    if (c[i] == 'L')
      muki[i] = 4;
    grid[ry[i]][rx[i]] = 1;
  }

  // ブロックを設置
  rep(i, b) { grid[by[i]][bx[i]] = 2; }

  //ゴールへBFS
  for (int r = 0; r < m; r++) { //ここあとで帰る
    // cout<<"r:"<<r<<endl;
    vector<vector<int>> prev_x(n, vector<int>(n, -1));
    vector<vector<int>> prev_y(n, vector<int>(n, -1));
    vector<vector<bool>> passed(n, vector<bool>(n, false));
    for (int i = 0; i < b; i++) {
      passed[by[i]][bx[i]] = true;
    }
    int lastx = gx, lasty = gy;
    queue<pair<int, int>> q;
    q.push(mp(rx[r], ry[r]));
    while (!q.empty()) {
      pair<int, int> now = q.front();
      q.pop();
      passed[now.second][now.first] = true;
      if (now.first == gx && now.second == gy) {
        //ゴール
        break;
      }
      if (info[now.second][now.first] > 0) {
        lastx = now.first;
        lasty = now.second;
        //既に書かれているから終了
        break;
      }
      {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
          int next_x = now.first + dx[i];
          int next_y = now.second + dy[i];

          if (next_x >= n)
            next_x -= n;
          if (next_x < 0)
            next_x += n;
          if (next_y >= n)
            next_y -= n;
          if (next_y < 0)
            next_y += n;

          if (grid[next_y][next_x] == 2)
            continue; //ブロック
          if (passed[next_y][next_x])
            continue;
          q.push(mp(next_x, next_y));
          prev_x[next_y][next_x] = now.first;
          prev_y[next_y][next_x] = now.second;
        }
      }
    }
    vvc field(n, vc(n, '_'));
    {
      //経路を復元
      int x = lastx, y = lasty;
      while (x != -1 && y != -1) {
        field[y][x] = 'o'; // 通過した
        // 前の頂点へ行く
        int px = prev_x[y][x];
        int py = prev_y[y][x];
        x = px, y = py;
      }
    }
    {
      int x = rx[r], y = ry[r];
      field[y][x] = '_';
      while (1) {
        if (x == gx && y == gy)
          break;
        bool ch = false;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
          int next_x = x + dx[i];
          int next_y = y + dy[i];

          if (next_x >= n)
            next_x -= n;
          if (next_x < 0)
            next_x += n;
          if (next_y >= n)
            next_y -= n;
          if (next_y < 0)
            next_y += n;

          if (field[next_y][next_x] == 'o') {
            ch = true;
            if (i == 0) {
              info[y][x] = 2;
            } else if (i == 1) {
              info[y][x] = 3;
            } else if (i == 2) {
              info[y][x] = 4;
            } else if (i == 3) {
              info[y][x] = 1;
            }
            field[y][x] = '_';
            y = next_y;
            x = next_x;
            break;
          }
        }
        if (!ch)
          break;
      }
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (info[i][j] != info[i + 1][j])
        continue;
      if (info[i][j] != info[i - 1][j])
        continue;
      if (info[i][j] == 2 || info[i][j] == 4)
        continue;
      if (info[i][j - 1] == 2)
        continue;
      if (info[i][j + 1] == 4)
        continue;
      if (grid[i][j] == 1)
        continue;
      info[i][j] = 0;
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (info[i][j] != info[i][j + 1])
        continue;
      if (info[i][j] != info[i][j - 1])
        continue;
      if (info[i][j] == 1 || info[i][j] == 3)
        continue;
      if (info[i - 1][j] == 3)
        continue;
      if (info[i + 1][j] == 1)
        continue;
      if (grid[i][j] == 1)
        continue;
      info[i][j] = 0;
    }
  }

  // //infoのいらないマスは消す
  // for(int i=0;i<n;i++){
  //     //横の被りを消す

  // }

  // ここから出力系
  vi ansy, ansx;
  vc ansr;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (info[i][j] > 0) {
        ansy.push_back(i);
        ansx.push_back(j);
        if (info[i][j] == 1) {
          ansr.push_back('U');
        } else if (info[i][j] == 2) {
          ansr.push_back('R');
        } else if (info[i][j] == 3) {
          ansr.push_back('D');
        } else if (info[i][j] == 4) {
          ansr.push_back('L');
        }
      }
    }
  }
  cout << ansy.size() << endl;
  for (int i = 0; i < ansy.size(); i++) {
    cout << ansy[i] << " " << ansx[i] << " " << ansr[i] << endl;
  }
}
