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
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 61;
constexpr ll MOD = 1000000007;  // 998244353;
constexpr ld EPS = 1e-11;

/* --------------------   ここまでテンプレ   -------------------- */

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int odd = 0, even = 0;
        int n;
        cin >> n;
        vi v(n);
        rep(i, n) cin >> v[i];
        rep(i, n) {
            if (v[i] % 2)
                odd++;
            else
                even++;
        }
        if (!(n % 2)) {
            if (odd != even) {
                fin(-1);
                continue;
            }
        } else {
            if (odd != even - 1) {
                fin(-1);
                continue;
            }
        }
        int ans = 0;
        rep(i, n) {
            if (v[i] % 2 != i % 2) {
                for (int j = i + 1; j < n; j++) {
                    if (v[j] % 2 == i % 2 && v[j] % 2 != j % 2) {
                        ans++;
                        swap(v[j], v[i]);
                        break;
                    }
                }
            }
        }
        fin(ans);
    }
}
