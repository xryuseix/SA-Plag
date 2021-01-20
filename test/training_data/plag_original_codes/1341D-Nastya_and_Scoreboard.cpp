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
#pragma GCC optimize("Ofast")
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
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
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
#define itn int
// #define endl '\n';
#define fi first
#define se second
#define NONVOID [[nodiscard]]
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
template <class T> inline void dump(T &v) {
  irep(i, v) { cout << *i << ((i == --v.end()) ? '\n' : ' '); }
}
inline string getline() {
  string s;
  getline(cin, s);
  return s;
}
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int count(int n) {
  int res = 0;
  while (n > 0) {
    res += n % 2;
    n /= 2;
  }
  return res;
}

template <class T> void print_vector(vector<T> &v) {
  rep(i, v.size()) {
    if (!i)
      cout << v[i];
    else
      cout << " " << v[i];
  }
  cout << endl;
}

int hontonum(int bef, vi &num, int n) {
  for (int j = 9; j >= 0; j--) {
    if ((bef & num[j]) == bef && count(bef ^ num[j]) == n) {
      return j;
    }
  }
  return 0;
}
int gyaku(int A, vi &num, int v) { return count(num[A] ^ v); }

int main() {

  string numbers[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                      "1101011", "1101111", "1010010", "1111111", "1111011"};
  vi num(10);
  rep(i, 10) {
    int po = 6;
    int t = 0;
    rep(j, 7) {
      t += (numbers[i][j] - '0') * pow(2, po);
      po--;
    }
    num[i] = t;
  }

  int n, k;
  cin >> n >> k;
  vi need(n, INF);
  vi v(n);
  rep(i, n) {
    string s;
    cin >> s;
    int po = 6;
    int t = 0;
    rep(j, 7) {
      t += (s[j] - '0') * pow(2, po);
      po--;
    }
    v[i] = t;
  }

  vvi w(n);
  rep(i, n) {
    int crrMax[10] = {0};
    for (int j = 9; j >= 0; j--) {
      if ((v[i] & num[j]) == v[i]) {
        int ne = count(v[i] ^ num[j]);
        if (!crrMax[ne]) {
          w[i].pb(ne);
          crrMax[ne] = 1;
        }
      }
    }
  }
  // dump(w[0]);
  vvi dp(n + 1, vi(k + 1, 0)), bef(n + 1, vi(k + 1, -1));
  dp[0][k] = 1;
  for (int i = 0; i < n; i++) {
    // dp[i+1]=dp[i];
    for (int j = k; j >= 0; j--) {
      if (!dp[i][j])
        continue;
      for (auto l : w[n - i - 1]) {
        if (j - l < 0)
          continue;
        dp[i + 1][j - l] = 1;
        chmax(bef[i + 1][j - l], hontonum(v[n - i - 1], num, l));
      }
    }
  }
  // rep(i,n+1)print_vector(dp[i]);
  // cout<<endl;
  // rep(i,n+1)print_vector(bef[i]);

  vi x(n);
  int H = n, W = 0;
  if (!dp[n][0]) {
    fin(-1);
    return 0;
  }
  while (1) {
    // cout<<H<<" "<<W<<endl;
    if (H == 0 && W == k)
      break;
    x[n - H] = bef[H][W];
    W += gyaku(bef[H][W], num, v[n - H]);
    H--;
  }
  // dump(x);

  rep(i, x.size()) cout << x[i];
  cout << endl;
}