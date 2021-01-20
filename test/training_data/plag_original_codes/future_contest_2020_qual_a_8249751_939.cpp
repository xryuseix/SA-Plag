/*
引用元：https://atcoder.jp/contests/future-contest-2020-qual/tasks/future_contest_2020_qual_a
A - ロボットの誘導Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/future-contest-2020-qual/submissions/8249751
// 提出ID : 8249751
// 問題ID : future_contest_2020_qual_a
// コンテストID : future-contest-2020-qual
// ユーザID : xryuseix
// コード長 : 4213
// 実行時間 : 1



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
  // cout<<"-----"<<endl;
  rep(i, m) { cin >> ry[i] >> rx[i] >> c[i]; }
  vi by(b), bx(b);
  // cout<<"------"<<endl;
  rep(i, b) { cin >> by[i] >> bx[i]; }
  // cout<<"------"<<endl;

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
  // cout<<"DDDD"<<endl;
  //ゴールを設置
  grid[gy][gx] = 3;

  // cout<<"CCCC"<<endl;

  //ロボットとその向きを設置
  vi muki(m);
  rep(i, m) {
    // cout<<i<<endl;
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
  // cout<<"EEEE"<<endl;
  // ブロックを設置
  rep(i, b) { grid[by[i]][by[i]] = 2; }
  // cout<<"AAAA"<<endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 2) {
        if (i - 1 >= 0)
          info[i - 1][j] = 4;
        else
          info[i - 1 + n][j] = 4;
        if (i + 1 < n)
          info[i + 1][j] = 2;
        else
          info[i + 1 - n][j] = 2;
        if (j + 1 < n)
          info[i][j + 1] = 1;
        else
          info[i][j + 1 - n] = 1;
        if (j - 1 >= 0)
          info[i][j - 1] = 3;
        else
          info[i][j - 1 + n] = 3;
      }
    }
  }
  // cout<<"BBBB"<<endl;
  {
    if (gy - 1 >= 0)
      info[gy - 1][gx] = 3;
    else
      info[gy - 1 + n][gx] = 3;
    if (gx + 1 < n)
      info[gy][gx + 1] = 4;
    else
      info[gy][gx + 1 - n] = 4;
    if (gy + 1 < n)
      info[gy + 1][gx] = 1;
    else
      info[gy + 1 - n][gx] = 1;
    if (gx - 1 >= 0)
      info[gy][gx - 1] = 2;
    else
      info[gy][gx - 1 + n] = 2;
  }

  vi ansy, ansx;
  vc ansr;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (info[i][j] > 0 && grid[i][j] == 0) {
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
