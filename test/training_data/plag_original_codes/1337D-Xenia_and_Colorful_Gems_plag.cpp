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
// const ll LLINF = 1LL<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const ll LLINF = 1LL << 62;

// vector vの中のn以下の数で最大のものを返す
ll bs(vector<ll> &v, ll x) {
    int ok = -1;        //これがx以下
    int ng = v.size();  // x以上
    // 問題によってokとngを入れ替える
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (v[mid] <= x)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}
ll pow(ll x) { return x * x; }

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;
        ll ans = LLINF;
        vll x(a), y(b), z(c);
        rep(i, a) cin >> x[i];
        rep(i, b) cin >> y[i];
        rep(i, c) cin >> z[i];
        Sort(z);
        Sort(y);
        Sort(x);

        rep(i, a) {
            int posC = bs(z, x[i]);
            int posB = bs(y, x[i]);
            for (int j = max(posB - 1, 0); j <= min(posB + 1, b - 1); j++) {
                for (int k = max(posC - 1, 0); k <= min(posC + 1, c - 1); k++) {
                    ans = min(ans, pow(x[i] - y[j]) + pow(x[i] - z[k]) +
                                       pow(y[j] - z[k]));
                }
            }
        }
        rep(i, c) {
            int posB = bs(y, z[i]);
            int posA = bs(x, z[i]);
            for (int j = max(posA - 1, 0); j <= min(posA + 1, a - 1); j++) {
                for (int k = max(posB - 1, 0); k <= min(posB + 1, b - 1); k++) {
                    ans = min(ans, pow(x[j] - y[k]) + pow(x[j] - z[i]) +
                                       pow(y[k] - z[i]));
                }
            }
        }
        rep(i, b) {
            int posC = bs(z, y[i]);
            int posA = bs(x, y[i]);
            for (int j = max(posA - 1, 0); j <= min(posA + 1, a - 1); j++) {
                for (int k = max(posC - 1, 0); k <= min(posC + 1, c - 1); k++) {
                    ans = min(ans, pow(x[j] - y[i]) + pow(x[j] - z[k]) +
                                       pow(y[i] - z[k]));
                }
            }
        }
        fin(ans);
    }
}
