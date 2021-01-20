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
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //////////////////////////////////////////////////////

    int n, m, a, b;
    cin >> n;
    set<int> s, t;
    rep(i, n) {
        cin >> a;
        s.insert(a);
    }
    cin >> m;
    rep(i, m) {
        cin >> b;
        t.insert(b);
    }
    irep(it, s) {
        irep(i, t) {
            if (s.find(*it + *i) == s.end() && t.find(*it + *i) == t.end()) {
                cout << *it << " " << *i << endl;
                return 0;
            }
        }
    }

    //////////////////////////////////////////////////////
    return 0;
}