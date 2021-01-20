/*
引用元：https://atcoder.jp/contests/abc022/tasks/abc022_d
D - Big Bang
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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define mp(p, q) make_pair(p, q)
#define fi first
#define se second
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int n;
    cin >> n;
    vpii v(n), w(n);
    rep(i, n) {
        double a, b;
        cin >> a >> b;
        v[i] = mp(a, b);
        y1 += b;
        x1 += a;
    }
    rep(i, n) {
        double a, b;
        cin >> a >> b;
        w[i] = mp(a, b);
        y2 += b;
        x2 += a;
    }

    x2 /= n;
    y1 /= n;
    y2 /= n;
    x1 /= n;
    double disB = 0;
    double disA = 0;
    rep(i, n) {
        chmax(disB, sqrt((w[i].fi - x2) * (w[i].fi - x2) +
                         (w[i].se - y2) * (w[i].se - y2)));
        chmax(disA, sqrt((v[i].fi - x1) * (v[i].fi - x1) +
                         (v[i].se - y1) * (v[i].se - y1)));
    }
    if (!disA) {
        double ans = (w[0].se * w[0].se + w[0].fi * w[0].fi) /
                     (v[0].se * v[0].se + v[0].fi * v[0].fi);
        printf("%.6f\n", ans);
    } else {
        printf("%.6f\n", disB / disA);
    }
}
