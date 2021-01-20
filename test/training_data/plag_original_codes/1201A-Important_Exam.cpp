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
  vs v(n);
  rep(i, n) cin >> v[i];
  ll ans = 0;
  vi point(m);
  rep(i, m) cin >> point[i];

  for (int i = 0; i < m; i++) {
    int co = 0;
    string s = "";
    for (int j = 0; j < n; j++) {
      s += v[j][i];
    }
    int num[5] = {0};
    num[0] = (int)count(s.cbegin(), s.cend(), 'A');
    num[1] = (int)count(s.cbegin(), s.cend(), 'B');
    num[2] = (int)count(s.cbegin(), s.cend(), 'C');
    num[3] = (int)count(s.cbegin(), s.cend(), 'D');
    num[4] = (int)count(s.cbegin(), s.cend(), 'E');
    int maxnum = 0, maxp;
    for (int i = 0; i < 5; i++) {
      if (maxnum < num[i]) {
        maxnum = num[i];
        maxp = i;
      }
    }
    ans += point[i] * num[maxp];
  }
  fin(ans);

  //////////////////////////////////////////////////////
  return 0;
}