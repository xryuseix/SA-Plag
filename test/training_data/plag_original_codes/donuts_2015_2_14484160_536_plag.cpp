/*
引用元：https://atcoder.jp/contests/donuts-2015/tasks/donuts_2015_2
B - Tokyo 7th シスターズ
Time Limit : 2 sec / Memory Limit : 256 MB
*/
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
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

ll n, m;
vll v(101010);
vll score(101010);
vll bit(101010, 0);
ll ans = 0;
ll k;

void input() {
    rep(i, m) {
        cin >> score[i] >> k;
        rep(j, k) {
            ll t;
            cin >> t;
            t--;
            bit[i] |= (1LL << t);
        }
    }
}

void solve() {
    rep(i, (1LL << n)) {
        ll count = 0;
        ll tmp = 0;
        rep(j, n) {
            if (i & (1LL << j)) {
                count++;
                tmp += v[j];
            }
        }
        if (count != 9) continue;
        rep(j, m) {
            ll nb = i & bit[j], c = 0;
            rep(k, n) {
                if ((nb >> k) & 1) c++;
            }
            if (c > 2) tmp += score[j];
        }
        ans = max(ans, tmp);
    }
}

int main() {
    cin >> n >> m;
    rep(i, n) cin >> v[i];
    input();
    solve();
    fin(ans);
}
