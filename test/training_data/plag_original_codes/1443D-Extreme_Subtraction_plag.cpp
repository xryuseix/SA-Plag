#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <deque>
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

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
constexpr ll LLINF = 1LL << 61;


/* --------------------   ここまでテンプレ   -------------------- */

int main() {
    int Q;
    cin >> Q;
    int n;
    while (Q--) {
        cin >> n;
        vi v(n), w, csum(n);
        rep(i, n) cin >> v[i];
        csum[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--) csum[i] = min(csum[i + 1], v[i]);

        ll min = LLINF;
        rep(i, n) {
            chmin(min, v[i]);
            if (min == v[i]) {
                v[i] = 0;
            } else {
                v[i] -= min;
                i++;
                while (i <= n - 2) {
                    chmin(min, (ll)max(0, v[i] - v[i - 1]));
                    if (v[i - 1] <= v[i] - min) {
                        v[i] -= min;
                        i++;
                    } else
                        break;
                }
                break;
            }
        }
        bool ch = 1;
        rep(i, n - 1) if (v[i] > v[i + 1]) ch = 0;

        YN(ch);
    }
}
