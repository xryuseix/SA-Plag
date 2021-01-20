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
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int n, m;
  cin >> n >> m;
  vvi a(n, vi(m)), b(n, vi(m, 0));
  rep(i, n) rep(j, m) cin >> a[i][j];
  vvi ans;
  vi tmp(2);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 &&
          a[i + 1][j + 1] == 1) {
        b[i][j] = 1;
        b[i + 1][j] = 1;
        b[i][j + 1] = 1;
        b[i + 1][j + 1] = 1;
        tmp[0] = i + 1;
        tmp[1] = j + 1;
        ans.push_back(tmp);
      }
    }
  }
  bool ch = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        ch = false;
      }
    }
  }
  if (!ch) {
    fin(-1);
    return 0;
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) { cout << ans[i][0] << " " << ans[i][1] << endl; }

  //////////////////////////////////////////////////////
  return 0;
}