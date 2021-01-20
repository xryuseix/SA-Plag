/*
引用元：https://atcoder.jp/contests/abc075/tasks/abc075_c
C - BridgeEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc075/submissions/6865389
// 提出ID : 6865389
// 問題ID : abc075_c
// コンテストID : abc075
// ユーザID : xryuseix
// コード長 : 2719
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

bool path;
queue<int> q;
bool bfs(int from, int to, vector<bool> &passed, vvi &g, int bef) {
  if (path)
    return true;
  int pos = q.front();
  q.pop();
  // cout<<pos<<" "<<bef<<endl;

  if (passed[pos]) {
    return false;
  }
  passed[pos] = true;

  for (int i = 0; i < g[pos].size(); i++) {
    if (pos == from && g[pos][i] == to)
      continue;
    // cout<<"from:"<<from<<" "<<"to:"<<to<<" "<<"pos:"<<pos<<"
    // "<<"i:"<<i<<endl;
    if (g[pos][i] == to && pos != from) {
      path = true;
      return true;
    }
    q.push(g[pos][i]);
    bfs(from, to, passed, g, pos);
  }
  if (path)
    return true;

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int n, m;
  cin >> n >> m;
  int A, B;
  vi a(m), b(m);

  vvi g(n);

  rep(i, m) {
    cin >> A >> B;
    a[i] = A - 1;
    b[i] = B - 1;
    g[A - 1].push_back(B - 1);
    g[B - 1].push_back(A - 1);
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    // cout<<"main:"<<i<<endl;
    vector<bool> passed(n, false);
    path = false;
    while (!q.empty())
      q.pop();
    q.push(a[i]);
    if (bfs(a[i], b[i], passed, g, a[i]))
      ans++;
    // cout<<"ans:"<<ans<<endl;
  }

  fin(m - ans);

  //////////////////////////////////////////////////////
  return 0;
}
