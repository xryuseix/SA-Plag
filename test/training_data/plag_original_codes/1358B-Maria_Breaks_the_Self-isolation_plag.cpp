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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define arep(i, v) for (auto i : v)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline void dump(T &v) {
  irep(i, v) { cout << *i << ((i == --v.end()) ? '\n' : ' '); }
}
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr double EPS = 1e-9;

int main() {

  int Q;
  cin >> Q;
  while (Q--) {
    map<int, int> m;
    int n;
    int ans = 0;
    cin >> n;
    vi v(n);
    rep(i, n) cin >> v[i];
    rep(i, n) m[v[i]]++;
    vector<pair<int, int>> w;
    irep(i, m) w.push_back(make_pair(i->first, i->second));
    sort(w.begin(), w.end());
    vi csum(1, 0);
    rep(i, w.size()) csum.push_back(csum[csum.size() - 1] + w[i].second);
    // dump(csum);
    drep(i, w.size()) {
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      // cout<<w[i].fi<<" "<<csum[i+1]<<endl;
      if (w[i].first <= csum[i + 1]) {
        ans = csum[i + 1];
        break;
      }
    }

    fin(ans + 1);
  }
}
