/*
引用元：https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_c
C - Strawberry CakesEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/ddcc2020-qual/submissions/8582026
// 提出ID : 8582026
// 問題ID : ddcc2020_qual_c
// コンテストID : ddcc2020-qual
// ユーザID : xryuseix
// コード長 : 2947
// 実行時間 : 14



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
const ll MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int main(void) {

  int h, w, k;
  cin >> h >> w >> k;
  vvc v(h, vc(w));
  vvi ans(h, vi(w, 0));
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) { v[i][j] = s[j]; }
  }
  int num = 0;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (v[j][i] == '#') {
        num++;
        int pos = j - 1;
        while (pos >= 0) {
          if (ans[pos][i] == 0 && v[pos][i] != '#') {
            ans[pos][i] = num;
            pos--;
          } else
            break;
        }
        ans[j][i] = num;
        pos = j + 1;
        while (pos < h) {
          if (ans[pos][i] == 0 && v[pos][i] != '#') {
            ans[pos][i] = num;
            pos++;
          } else
            break;
        }
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 1; j < w; j++) {
      if (ans[i][j] == 0) {
        ans[i][j] = ans[i][j - 1];
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = w - 1; j >= 0; j--) {
      if (ans[i][j] == 0) {
        ans[i][j] = ans[i][j + 1];
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j == 0)
        cout << ans[i][j];
      else
        cout << " " << ans[i][j];
    }
    cout << endl;
  }
}
