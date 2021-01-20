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
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

int stringcount(string s, char c) { return count(s.cbegin(), s.cend(), c); }

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        vi zero(1, 0), one(1, 0);
        string s;
        cin >> s;
        int n = s.size();
        int ans = INF;
        rep(i, s.size()) {
            if (s[i] == '0') {
                one.push_back(one[one.size() - 1]);
                zero.push_back(zero[zero.size() - 1] + 1);
            } else {
                one.push_back(one[one.size() - 1] + 1);
                zero.push_back(zero[zero.size() - 1]);
            }
        }
        chmin(ans, stringcount(s, '0'));
        chmin(ans, stringcount(s, '1'));
        rep(i, s.size()) chmin(ans, one[i + 1] + zero[n] - zero[i + 1]);
        rep(i, s.size()) chmin(ans, zero[i + 1] + one[n] - one[i + 1]);

        cout << ans << endl;
    }
}
