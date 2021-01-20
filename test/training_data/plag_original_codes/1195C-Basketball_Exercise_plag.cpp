#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
// g++ -std=c++1z temp.cpp
//./a.out

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //////////////////////////////////////////////////////
    ll n;
    cin >> n;
    vvll v(2, vll(n));
    rep(i, n) cin >> v[0][i];
    rep(i, n) cin >> v[1][i];
    ll ans = 0;
    vvll dp(n, vll(2, -1));
    dp[0][0] = v[0][0];
    // dp[0][1]=v[0][0];
    rep(i, n) {
        if (i != 1) {
            rep(j, 2) {
                dp[i][j] =
                    max({dp[i][j], dp[i - 2][0], dp[i - 2][1] + v[j][i]});
            }
        }
        rep(j, 2) { dp[i][j] = max(dp[i][j], dp[i - 1][1 - j] + v[j][i]); }
    }
    ans = max(dp[n - 1][0], dp[n - 1][1]);

    ll ans2 = 0;
    vvll dp2(n, vll(2, -1));
    // dp2[0][0]=v[1][0];
    dp2[0][1] = v[1][0];
    rep(i, n) {
        if (i != 1) {
            rep(j, 2) {
                dp2[i][j] =
                    max({dp2[i][j], dp2[i - 2][0], dp2[i - 2][1] + v[j][i]});
            }
        }
        rep(j, 2) { dp[i][j] = max(dp[i][j], dp[i - 1][1 - j] + v[j][i]); }
    }
    ans2 = max(dp2[n - 1][0], dp2[n - 1][1]);
    cout << max(ans, ans2) << endl;

    //////////////////////////////////////////////////////
    return 0;
}