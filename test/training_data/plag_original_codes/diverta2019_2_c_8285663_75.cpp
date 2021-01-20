/*
引用元：https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_c
C - Successive SubtractionEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/diverta2019-2/submissions/8285663
// 提出ID : 8285663
// 問題ID : diverta2019_2_c
// コンテストID : diverta2019-2
// ユーザID : xryuseix
// コード長 : 2878
// 実行時間 : 204



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

  int n;
  cin >> n;
  vi v(n);
  ll ans = 0;
  vector<pair<int, int>> log;
  bool isneg = false, ispos = false;
  rep(i, n) {
    cin >> v[i];
    if (v[i] >= 0)
      ispos = true;
    else
      isneg = true;
  }
  Sort(v);

  if (ispos && isneg) {
    for (int i = v.size() - 2; i > 0; i--) {
      if (v[i] < 0)
        break;
      log.push_back(mp(v[0], v[i]));
      v[0] -= v[i];
      v[i] = INF;
    }
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i] == INF)
        continue;
      else {
        log.push_back(mp(v[v.size() - 1], v[i]));
        v[v.size() - 1] -= v[i];
      }
    }
    ans = v[v.size() - 1];
  } else if (ispos) {
    for (int i = 1; i < v.size() - 1; i++) {
      log.push_back(mp(v[0], v[i]));
      v[0] -= v[i];
    }
    log.push_back(mp(v[v.size() - 1], v[0]));
    v[v.size() - 1] -= v[0];
    ans = v[v.size() - 1];
  } else if (isneg) {
    Rort(v);
    log.push_back(mp(v[0], v[1]));
    v[0] -= v[1];
    for (int i = 2; i < v.size(); i++) {
      log.push_back(mp(v[0], v[i]));
      v[0] -= v[i];
    }
    ans = v[0];
  }

  cout << ans << endl;
  for (int i = 0; i < log.size(); i++) {
    cout << log[i].first << " " << log[i].second << endl;
  }
}
