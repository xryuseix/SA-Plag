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
#pragma GCC optimize("Ofast")
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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define arep(i, v) for (auto i : v)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define pb(n) push_back(n)
template <class T>
inline void dump(T &v) {
    irep(i, v) { cout << *i << ((i == --v.end()) ? '\n' : ' '); }
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        ll n;
        cin >> n;
        ll N = ceil(log2(n + 1));
        vll v(N, 1);
        v[N - 1] = n * 8 / 20;
        ll sum = n;
        for (ll i = N - 2; i > 0; i--) {
            v[i] = ceil(v[i + 1] / 2.0);
        }
        rep(i, N) sum -= v[i];
        // dump(v);
        // fin(sum);
        for (ll i = 1; i < N; i++) {
            ll l, r;
            if (i == N - 1) {
                l = v[i];
                r = v[i - 1] * 2;
            } else {
                l = v[i];
                r = min(v[i + 1], v[i - 1] * 2);
            }
            if (sum == 0) break;
            if (r - v[i] <= sum) {
                sum -= r - v[i];
                v[i] = r;
            } else {
                v[i] += sum;
                sum = 0;
            }
        }
        vll ans;
        rep(i, v.size() - 1) { ans.pb(v[i + 1] - v[i]); }
        cout << (ans.size()) << endl;
        dump(ans);
    }
}
