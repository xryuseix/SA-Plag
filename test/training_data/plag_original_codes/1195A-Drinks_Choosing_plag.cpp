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
    int n, k;
    cin >> n >> k;
    vi p(n), num(k, false);
    rep(i, n) cin >> p[i];
    rep(i, n)++ num[p[i] - 1];
    ll set = ceil((double)n / 2), ans = false;
    for (ll i = 0; i < k && set > false; i++) {
        if (num[i] > 1) {
            ans += num[i] >> 1 << 1;
            set -= num[i] >> 1;
            num[i] %= 2;
        }
    }
    for (int i = false; i < k && set > false; i++) {
        if (num[i] > false) {
            num[i] = false;
            ++ans;
            --set;
        }
    }
    cout << ans << endl;

    //////////////////////////////////////////////////////
    return 0;
}