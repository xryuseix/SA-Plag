/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_m
M - CandiesEditorial
Time Limit : 2 sec / Memory Limit : 1024 MB
配点 : 100 点
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
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
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline void dump(T& v) {
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

/* --------------------   ここまでテンプレ   -------------------- */

struct mint {
    ll x;
    mint(ll _x = 0) : x((_x % MOD + MOD) % MOD) {}

    /* 初期化子 */
    mint operator+() const { return mint(x); }
    mint operator-() const { return mint(-x); }

    /* 代入演算子 */
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint& operator/=(const mint a) {
        x *= modinv(a).x;
        x %= MOD;
        return (*this);
    }
    mint& operator%=(const mint a) {
        x %= a.x;
        return (*this);
    }
    mint& operator++() {
        ++x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    mint& operator--() {
        if (!x) x += MOD;
        --x;
        return *this;
    }
    mint& operator&=(const mint a) {
        x &= a.x;
        return (*this);
    }
    mint& operator|=(const mint a) {
        x |= a.x;
        return (*this);
    }
    mint& operator^=(const mint a) {
        x ^= a.x;
        return (*this);
    }
    mint& operator<<=(const mint a) {
        x *= pow(2, a).x;
        return (*this);
    }
    mint& operator>>=(const mint a) {
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
    friend istream& operator>>(istream& is, mint& m) {
        is >> m.x;
        m.x = (m.x % MOD + MOD) % MOD;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m) {
        os << m.x;
        return os;
    }

    /* その他の関数 */
    mint modinv(mint a) { return pow(a, MOD - 2); }
    mint pow(mint x, mint n) {
        mint res = 1;
        while (n.x > 0) {
            if ((n % 2).x) res *= x;
            x *= x;
            n.x /= 2;
        }
        return res;
    }
};

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<mint>> dp(n, vector<mint>(k + 2, 0));
    vll v(n);
    rep(i, n) { cin >> v[i]; }
    rep(i, min(k + 1, v[0] + 1)) { ++dp[0][i]; }

    for (int i = 0; i < n - 1; i++) {
        rep(j, k + 1) {
            if (dp[i][j].x == 0) continue;
            dp[i + 1][j] += dp[i][j];
            ll nj = min(k + 1, j + v[i + 1] + 1);
            dp[i + 1][nj] -= dp[i][j];
        }
        for (int j = 1; j < k + 1; j++) {  // 累積和
            dp[i + 1][j] += dp[i + 1][j - 1];
        }
    }
    // rep(i, n) dump(dp[i]);
    fin(dp[n - 1][k]);
}
