/*
引用元：https://atcoder.jp/contests/abc111/tasks/arc103_a
C - /\/\/\/
Time Limit : 2 sec / Memory Limit : 1024 MB
配点 : 300 点
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
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
struct io {
    io() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
};
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr double EPS = 1e-9;

int n;
mii m, p;
vpii mM(2), pM(2);
int main() {
    cin >> n;
    vi v(n);
    rep(i, n) {
        cin >> v[i];
        if (i % 2)
            p[v[i]]++;
        else
            m[v[i]]++;
    }
    irep(i, m) {
        if (i->second > mM[1].second) {
            mM[1].first = i->first;
            mM[1].second = i->second;
            if (mM[0].second < mM[1].second) swap(mM[0], mM[1]);
        }
    }
    irep(i, p) {
        if (i->second > pM[1].second) {
            pM[1].first = i->first;
            pM[1].second = i->second;
            if (pM[0].second < pM[1].second) swap(pM[0], pM[1]);
        }
    }
    int ans = INF;
    if (mM[0].first != pM[0].first) chmin(ans, n - mM[0].second - pM[0].second);
    if (mM[1].first != pM[0].first) chmin(ans, n - mM[1].second - pM[0].second);
    if (mM[0].first != pM[1].first) chmin(ans, n - mM[0].second - pM[1].second);
    if (mM[1].first != pM[1].first) chmin(ans, n - mM[1].second - pM[1].second);
    fin(ans);
}
