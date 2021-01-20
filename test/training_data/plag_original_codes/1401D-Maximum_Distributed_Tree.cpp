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
#define fi first
#define se second
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
  irep(i, v) { cout << (*i) << ((i == --v.end()) ? '\n' : ' '); }
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
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

struct mint {
  ll x;
  mint(ll _x = 0) : x((_x % MOD + MOD) % MOD) {}

  /* 初期化子 */
  mint operator+() const { return mint(x); }
  mint operator-() const { return mint(-x); }

  /* 代入演算子 */
  mint &operator+=(const mint a) {
    if ((x += a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint &operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint &operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint &operator/=(const mint a) {
    x *= modinv(a).x;
    x %= MOD;
    return (*this);
  }
  mint &operator%=(const mint a) {
    x %= a.x;
    return (*this);
  }
  mint &operator++() {
    ++x;
    if (x >= MOD)
      x -= MOD;
    return *this;
  }
  mint &operator--() {
    if (!x)
      x += MOD;
    --x;
    return *this;
  }
  mint &operator&=(const mint a) {
    x &= a.x;
    return (*this);
  }
  mint &operator|=(const mint a) {
    x |= a.x;
    return (*this);
  }
  mint &operator^=(const mint a) {
    x ^= a.x;
    return (*this);
  }
  mint &operator<<=(const mint a) {
    x *= pow(2, a).x;
    return (*this);
  }
  mint &operator>>=(const mint a) {
    x /= pow(2, a).x;
    return (*this);
  }

  /* 算術演算子 */
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
  mint operator%(const mint a) const {
    mint res(*this);
    return res %= a;
  }
  mint operator&(const mint a) const {
    mint res(*this);
    return res &= a;
  }
  mint operator|(const mint a) const {
    mint res(*this);
    return res |= a;
  }
  mint operator^(const mint a) const {
    mint res(*this);
    return res ^= a;
  }
  mint operator<<(const mint a) const {
    mint res(*this);
    return res <<= a;
  }
  mint operator>>(const mint a) const {
    mint res(*this);
    return res >>= a;
  }

  /* 条件演算子 */
  bool operator==(const mint a) const noexcept { return x == a.x; }
  bool operator!=(const mint a) const noexcept { return x != a.x; }
  bool operator<(const mint a) const noexcept { return x < a.x; }
  bool operator>(const mint a) const noexcept { return x > a.x; }
  bool operator<=(const mint a) const noexcept { return x <= a.x; }
  bool operator>=(const mint a) const noexcept { return x >= a.x; }

  /* ストリーム挿入演算子 */
  friend istream &operator>>(istream &is, mint &m) {
    is >> m.x;
    m.x = (m.x % MOD + MOD) % MOD;
    return is;
  }
  friend ostream &operator<<(ostream &os, const mint &m) {
    os << m.x;
    return os;
  }

  /* その他の関数 */
  mint modinv(mint a) { return pow(a, MOD - 2); }
  mint pow(mint x, mint n) {
    mint res = 1;
    while (n.x > 0) {
      if ((n % 2).x)
        res *= x;
      x *= x;
      n.x /= 2;
    }
    return res;
  }
};

vector<pair<ll, ll>> s;
vi pass(101010, 0);
ll dfs(int pos, ll sum, vvi &v) {
  ll anssum = 1;
  for (auto ne : v[pos]) {
    if (pass[ne])
      continue;
    pass[ne] = 1;
    ll ans = dfs(ne, sum, v);
    anssum += ans;
    anssum %= MOD;
    s.pb(mp(ans, v.size()));
  }
  return anssum;
}
template <class T> void lambdaSort(vector<T> &v) {
  sort(all(v), [](auto const &l, auto const &r) {
    return abs(l.fi - (l.se - l.fi)) <
           abs(r.fi - (r.se - r.fi)); // このbool式が成り立つ時入れ替える
  });
}

int main() {

  int Q;
  cin >> Q;
  while (Q--) {
    pass = vi(101010, 0);
    s.clear();
    ll n;
    scanf("%lld", &n);
    vvi v(n);
    rep(i, n - 1) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--;
      b--;
      v[a].pb(b);
      v[b].pb(a);
    }
    pass[0] = 1;
    dfs(0, 0, v);
    lambdaSort(s);
    // for(auto p:s){
    //     cout<<"   "<<p.fi<<" "<<p.se<<endl;
    // }
    ll m;
    scanf("%lld", &m);
    vll w(m);
    rep(i, m) scanf("%lld", &w[i]);
    Sort(w);
    while (w.size() > n - 1) {
      ll t = *w.rbegin();
      w.pop_back();
      w[w.size() - 1] *= t;
      w[w.size() - 1] %= MOD;
    }
    reverse(all(w));
    mint ans = 0;
    rep(i, n - 1) {
      mint t = s[i].fi * (n - s[i].fi);
      if (i < m)
        t *= w[i];
      ans += t;
    }
    fin(ans.x);
  }
}
