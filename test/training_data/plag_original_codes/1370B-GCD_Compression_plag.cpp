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
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

vpii solve(map<int, vi> &m, int B, int n, vpii &ans) {
    irep(i, m) {
        int a = i->first;
        int b = (B - i->first) % B;
        if (b < a) continue;
        if (b == a) {
            int l = 0;
            int r = m[a].size() - 1;
            while (l < r) {
                ans.pb(mp(m[a][l], m[b][r]));
                r--;
                l++;
            }
        } else {
            if (m.find(b) == m.end()) continue;
            rep(j, min(m[b].size(), m[a].size())) ans.pb(mp(m[a][j], m[b][j]));

            if (ans.size() < n - 1) ans.clear();
        }
    }
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int n;
        cin >> n;
        vi v(n * 2);
        rep(i, 2 * n) cin >> v[i];
        for (int B = 2; B <= 1000; B++) {
            map<int, vi> m;
            rep(i, 2 * n) {
                if (m.find(v[i] % B) == m.end()) {
                    vi w(1, i);
                    m[v[i] % B] = (w);
                } else {
                    m[v[i] % B].pb(i);
                }
            }
            vpii ans;
            solve(m, B, n, ans);

            if (ans.size() >= n - 1) {
                rep(i, n - 1) {
                    cout << ans[i].fi + 1 << " " << ans[i].se + 1 << endl;
                }
                break;
            }
        }
    }
}