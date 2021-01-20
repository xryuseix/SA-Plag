/*
引用元：https://atcoder.jp/contests/wupc2019/tasks/wupc2019_b
B - 10 puzzle
Time Limit : 2 sec / Memory Limit : 1024
MBMathJax.Hub.Config({messageStyle:"none",tex2jax:{skipTags:["script","noscript","style","textarea","code"],inlineMath:[['\\(','\\)']]}});
配点 : \(100\) 点
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

template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const int INF = INT_MAX;

int main() {

  int h, w;
  cin >> h >> w;
  vvi v(h, vi(w));
  vi num(10, 0);
  bool forz = 1;
  rep(i, h) rep(j, w) {
    cin >> v[i][j];
    num[v[i][j]]++;
    if (v[i][j] != 5 && v[i][j] != 0)
      forz = 0;
  }
  if(forz || num[5] == 0 || (h == 1 && w == 1)) {
    if (forz) {
      cout << "Yes " << ((num[5]) ? 1 : 0) << endl;
    } else if (num[5] == 0) {
      fin("No");
    } else if (h == 1 && w == 1) {
      fin("Yes 1");
    }
    return 0;
  }
  int need[] = {0, 0, 0, 0, 0, 0, 1, 1, 2, 3};
  if (h == 1) {
    int ans = INF;
    for (int i = 0; i < w; i++) {
      if (v[0][i] == 5) {
        int l = 0, r = 0, ln = 0, rn = 0;
        for (int j = 0; j < i; j++) {
          if (ln < v[0][j]) {
            l = need[v[0][j]];
            ln = v[0][j];
          }
        }
        for (int j = i + 1; j < w; j++) {
          if (rn < v[0][j]) {
            r = need[v[0][j]];
            rn = v[0][j];
          }
        }
        chmin(ans, l + r + 1);
      }
    }
    cout << "Yes " << ans << endl;
    return 0;
  }
  if (1==w) {
    int ans = INF;
    for (int i = 0; i < h; i++) {
      if (v[i][0] == 5) {
        int l = 0, r = 0;
        int ln = 0, rn = 0;
        for (int j = 0; j < i; j++) {
          if (ln < v[j][0]) {
            ln = v[j][0];
            l = need[v[j][0]];
          }
        }
        for (int j = i + 1; j < h; j++) {
          if (rn < v[j][0]) {
            rn = v[j][0];
            r = need[v[j][0]];
          }
        }
        chmin(ans, l + r + 1);
      }
    }
    cout << "Yes " << ans << endl;
    return 0;
  } else if (num[9]) {
    fin("Yes 4");
  } else if (num[8]) {
    fin("Yes 3");
  } else if (num[7]) {
    fin("Yes 2");
  } else if (num[6]) {
    fin("Yes 2");
  } else if (num[5]) {
    fin("Yes 1");
  }
}
