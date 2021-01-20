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
#define rep(i, n) for (ll i = 0; i < (n); ++i)
void intersect(set<int> &Set_A, set<int> &Set_B, set<int> &Set_res) {
    set_intersection(Set_A.begin(), Set_A.end(), Set_B.begin(), Set_B.end(),
                     inserter(Set_res, Set_res.end()));
}

int main() {
    {
        int n = 10, xo = 0;
        int ma = 0;
        rep(i, n) {
            int x;
            cin >> x;
            xo ^= x;
        }
        if (n % 2 == 1) {
            ma++;
        }
        if (ma < xo) {
            ma++;
        } else {
            ma++;
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        set<int> s, t, u;
        int n;
        cin >> n;
        vi v(n);
        rep(i, n) {
            cin >> v[i];
            s.insert(v[i]);
        }
        bool ch = 0;
        for (int i = 1; i <= 1 << 10; i++) {
            t.clear();
            u = t;
            rep(j, v.size()) t.insert(i ^ v[j]);
            intersect(s, t, u);
            if (t.size() == u.size() && s.size() == u.size()) {
                ch = 1;
                cout << i << endl;
                break;
            }
        }
        if (!ch) cout << -1 << endl;
    }
}
