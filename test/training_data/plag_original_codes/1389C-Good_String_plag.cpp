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

const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

int stringcount(string &s, char c) { return count(s.cbegin(), s.cend(), c); }

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        string s;
        cin >> s;
        int ans = s.size() - 2;
        for (char c = '0'; c <= '9'; c++) {
            chmin(ans, (int)s.size() - stringcount(s, c));
        }
        for (char A = '0'; A <= '9'; A++) {
            for (char B = '0'; B <= '9'; B++) {
                if (!(A - B)) continue;
                int size = 0, mode = 0;
                for (int i = 0; i < s.size(); i++) {
                    if (!mode && s[i] == A) {
                        mode ^= 1;
                        size++;
                    } else if (mode && s[i] == B) {
                        mode ^= 1;
                        size++;
                    }
                }
                size = size / 2 * 2;
                chmin(ans, (int)s.size() - size);
            }
        }
        cout << ans << endl;
    }
}
