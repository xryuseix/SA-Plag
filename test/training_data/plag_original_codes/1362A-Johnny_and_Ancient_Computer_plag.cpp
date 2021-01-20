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
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define arep(i, v) for (auto i : v)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        ll a, b;
        cin >> a >> b;
        auto can = [&](ll a, ll b) {
            if (a > b) swap(a, b);
            ll A = a, B = b;
            while (a > 0 && a % 2 == 0) {
                a /= 2;
            }
            while (b > 0 && b % 2 == 0) {
                b /= 2;
            }
            return b == a;
        };
        if (!can(a,b)) {
            fin(-1);
            continue;
        }
        ll da = 0;
        ll db = 0;
        while (b > 0 && b % 2 == 0) {
            db++;
            b /= 2;
        }
        while (a > 0 && a % 2 == 0) {
            da++;
            a /= 2;
        }

        ll ans = 0;
        ll d = abs(da - db);
        ans += abs(da - db) / 3;
        d %= 3;
        ans += d / 2;
        d %= 2;
        ans += d;
        fin(ans);
    }
}