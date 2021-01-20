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
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << '\n'
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        ll v, c, n, m;
        cin >> v >> c >> n >> m;
        if (v + c < n + m) {
            fin("No");
            continue;
        }
        ll d = min(abs(v - c), n);
        if (v > c)
            v -= min(abs(v - c), n);
        else
            c -= min(abs(v - c), n);
        n -= d;
        ll lp = min(n, m);
        v = v - lp;
        m = m - lp;
        c = c - lp;
        n = n - lp;
        if (v < 0 || c < 0) {
            fin("No");
            continue;
        }
        if (n > 0) {
            Yn(v + c >= n);
        } else if (m > 0) {
            Yn(min(v, c) >= m);
        } else {
            fin("Yes");
        }
    }
}
