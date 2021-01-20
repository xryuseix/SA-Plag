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
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //////////////////////////////////////////////////////

    int n, k;
    cin >> n >> k;
    vi v(n), w;
    rep(i, n) cin >> v[i];
    Sort(v);
    if (n == 1) {
        cout << v[0] + k << endl;
        return 0;
    }
    for (int i = n / 2; i < n; i++) w.push_back(v[i]);
    map<int, int> m;
    rep(i, w.size()) {
        if (m.find(w[i]) != m.end()) {
            m[w[i]]++;
        } else {
            m[w[i]] = (ll)1;
        }
    }
    ll use = (ll)0;
    vector<pair<int, int>> c;
    for (auto it = m.begin(); it != m.end(); it++)
        c.push_back(mp((ll)it->first, (ll)it->second));

    int maxp = 0;
    for (int i = 1; i < c.size(); i++) {
        if ((ll)use + (ll)(c[i].first - c[i - 1].first) * (ll)c[i - 1].second <=
            k) {
            use += (ll)(c[i].first - c[i - 1].first) * (ll)c[i - 1].second;
            c[i].second += (ll)c[i - 1].second;
            c[i - 1].second = (ll)0;
            maxp = (ll)i;
            continue;
        }
        break;
    }
    cout << (ll)c[maxp].first + (k - use) / (ll)c[maxp].second << endl;

    //////////////////////////////////////////////////////
    return 0;
}