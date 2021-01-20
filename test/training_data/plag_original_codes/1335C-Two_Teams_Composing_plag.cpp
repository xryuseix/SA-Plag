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
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (int i = 0; i < (n); ++i)

template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int n, a, b;
        cin >> n;
        set<int> s;
        int N;
        int max = 0, num = 0;
        map<int, int> m;
        rep(i, n) {
            cin >> N;
            m[N]++;
        }
        for (auto i = m.begin(); i != m.end(); i++) {
            if (i->second > num) {
                num = i->second;
                max = i->first;
            }
        }
        for (auto i = m.begin(); i != m.end(); i++) {
            if (i->first == max)
                continue;
            else
                s.insert(i->first);
        }
        int ans = 0;
        if (s.size() + 1 == num - 1) chmax(ans, num - 1);
        if (s.size() == num) chmax(ans, num);
        chmax(ans, min((int)s.size() + 1, num - 1));
        chmax(ans, min((int)s.size(), num));
        cout << ans << endl;
    }
}
