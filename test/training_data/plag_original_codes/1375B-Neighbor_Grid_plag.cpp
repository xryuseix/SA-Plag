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
template <class T> inline void dump(T &v) {
  irep(i, v) { cout << *i << ((i == --v.end()) ? '\n' : ' '); }
}

int main() {

  int Q;
  cin >> Q;
  while (Q--) {
    int h, w;
    cin >> h >> w;
    bool ch = 1;
    vector<vi> v(h, vi(w));
    rep(i, h) rep(j, w) cin >> v[i][j];
    rep(i, h) {
      rep(j, w) {
        bool hasiy = (i == 0) | (i == h - 1);
        bool hasix = (j == 0) | (j == w - 1);
        if (hasix && hasiy) {
          if (v[i][j] > 2)
            ch = 0;
          v[i][j] = 2;
        } else if (hasix || hasiy) {
          if (v[i][j] > 3)
            ch = 0;
          v[i][j] = 3;
        } else {
          if (v[i][j] > 4)
            ch = 0;
          v[i][j] = 4;
        }
      }
    }
    if (!ch)
      fin("NO");
    else {
      fin("YES");
      rep(i, h) dump(v[i]);
    }
  }
}
