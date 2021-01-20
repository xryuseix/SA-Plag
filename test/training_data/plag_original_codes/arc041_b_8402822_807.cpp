/*
引用元：https://atcoder.jp/contests/arc041/tasks/arc041_b
B - アメーバEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc041/submissions/8402822
// 提出ID : 8402822
// 問題ID : arc041_b
// コンテストID : arc041
// ユーザID : xryuseix
// コード長 : 2344
// 実行時間 : 24



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

  int n, m;
  cin >> n >> m;
  vvi a(n, vi(m, 0)), b(n, vi(m));
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, m) b[i][j] = int(s[j] - '0');
  }
  // for(int i=0;i<n;i++){
  //     for(int j=0;j<m;j++){
  //         cout<<b[i][j];
  //     }
  //     cout<<endl;
  // }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] > 0) {
        // cout<<i<<" "<<j<<endl;
        a[i + 1][j] = b[i][j];
        b[i + 1][j - 1] -= b[i][j];
        b[i + 1][j + 1] -= b[i][j];
        b[i + 2][j] -= b[i][j];
        b[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
