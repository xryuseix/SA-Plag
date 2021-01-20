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

ll inter(ll l1, ll r1, ll l2, ll r2) {
    if (r1 <= l2)
        return 0;
    else if (r2 <= r1)
        return r2 - l2;
    return r1 - l2;
}
ll diff(ll l1, ll r1, ll l2, ll r2) {
    ll d = inter(l1, r1, l2, r2);
    if (d > 0)
        return -d;
    else
        return l2 - r1;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        ll n, k, l1, r1, l2, r2;
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) {
            swap(r1, r2);
            swap(l1, l2);
        }
        ll ans = 0;
        k -= inter(l1, r1, l2, r2) * (n);
        if (k <= 0) {
            fin(0);
            continue;
        }
        ll x = diff(l1, r1, l2, r2);

        if (x > 0) {
            ans += x;
            if (k <= (r2 - l1)) {
                ans += k;
                fin(ans);
                continue;
            }
            ans += (r2 - l1);
            k -= (r2 - l1);
            ll addAns = k * 2;
            ll tmpAns = 0;
            rep(i, n - 1) {
                if (k <= 0) break;
                if (k > r2 - l1) {
                    k -= r2 - l1;
                    tmpAns += r2 - l1;
                    tmpAns += x;
                } else {
                    tmpAns += min(x + k, k * 2);
                    k = 0;
                }
            }
            tmpAns += k * 2;
            ans += min(tmpAns, addAns);
            fin(ans);
        } else {
            if ((l2 - l1 + abs(r2 - r1)) * n >= k) {
                fin(k);
                continue;
            } else {
                fin((l2 - l1 + abs(r2 - r1)) * n +
                    (k - (l2 - l1 + abs(r2 - r1)) * n) * 2);
                continue;
            }
        }
    }
}
