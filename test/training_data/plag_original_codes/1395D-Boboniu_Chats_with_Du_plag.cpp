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
#define rep(i, n) for (ull i = 0; i < (n); ++i)
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
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline void dump(T &v) {
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

template <typename T>
class BIT {
    int N;
    vector<T> tree;

   public:
    BIT(vector<T> &v) : N(v.size()), tree(vector<T>(v.size() + 1)) {
        rep(i, v.size()) { add(i, v[i]); }
    }

    void add(int i, T x = 1) {
        for (++i; i <= N; i += i & -i) {
            tree[i] += x;
        }
    }

    T sum(int i) {  // [0,i)の和
        T x = 0;
        for (; i; i -= i & -i) {
            x += tree[i];
        }
        return x;
    }

    T sum(int l, int r) {  // [l,r)の和
        return sum(r) - sum(l);
    }
};

int main() {
    ll n, d, m;
    cin >> n >> d >> m;
    vll v, w;
    rep(i, n) {
        ll t;
        cin >> t;
        if (t <= m)
            w.pb(t);
        else
            v.pb(t);
    }
    Rort(v);
    Rort(w);
    ll ans = 0;
    BIT<ll> bit(v), bit2(w);

    rep(x, v.size() + 1) {
        if (!x)
            chmax(ans, bit2.sum(w.size()));
        else {
            int y = min((ll)w.size(), n - 1 - (x - 1) * (d + 1));
            // fin(y);
            if (y < 0) break;
            chmax(ans, bit.sum(0, x) + bit2.sum(0, y));
        }
    }
    fin(ans);
}