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
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << '\n'
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const int INF = INT_MAX;

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int n;
        cin >> n;
        vvi dp(n + 1, vi(2, INF));
        vi v(n);
        rep(i, n) cin >> v[i];
        dp[0][1] = 0;
        rep(i, n) {
            rep(j, 2) {
                if (dp[i][j] == INF) continue;
                int p1 = (j) ? v[i] : 0;
                chmin(dp[i + 1][1 - j], dp[i][j] + p1);
                if (i < n - 1) {
                    int p2 = (j) ? p1 + v[i + 1] : 0;
                    chmin(dp[i + 2][1 - j], dp[i][j] + p2);
                }
            }
        }
        fin(min(dp[n][0], dp[n][1]));
    }
}
