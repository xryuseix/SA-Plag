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
template <class T, class U>
inline void dump(map<T, U> &v) {
    irep(i, v) { cout << i->first << " " << i->second << '\n'; }
}
inline string getline() {
    string s;
    getline(cin, s);
    return s;
}
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
const int INF = INT_MAX;
constexpr ull LLINF = 1LL << 63;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

/* --------------------   ここまでテンプレ   -------------------- */

int digsum(ull n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        string n;
        ll s;
        cin >> n >> s;
        ull ans = LLINF;
        if (digsum(STLL(n)) <= s) {
            cout << 0 << endl;
            continue;
        }
        if (STLL(n) < 1e18) {
            string t = "1" + string(n.size(), '0');
            chmin(ans, (ull)STLL(t) - STLL(n));
        }
        for (int i = n.size() - 2; i >= 0; i--) {
            string t = n;
            if (t[i] == '9') continue;
            ++t[i];
            for (int j = i + 1; j < t.size(); j++) {
                t[j] = '0';
            }
            if (digsum(STLL(t)) > s) continue;
            ull cost = STLL(t) - STLL(n);
            chmin(ans, cost);
        }
        fin(ans);
    }
}
