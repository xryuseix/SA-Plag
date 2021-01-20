/*
引用元：https://atcoder.jp/contests/nomura2020/tasks/nomura2020_c
C - Folia
Time Limit : 2 sec / Memory Limit : 1024 MB
配点 : 600 点
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
#define rep(i, n) for (ll i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    n++;
    vll a(n), M(n);
    rep(i, n) cin >> a[i];
    M[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        M[i] = a[i + 1] + M[i + 1];
    }
    if (a[0] != 1 && n == 1) {
        cout << -1 << endl;
        return 0;
    } else if (n > 1 && a[0] > 0) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0, lef = 1;
    int i;
    rep(i, n - 1) {
        ans += min(lef, M[i]) + a[i];
        lef = lef * 2 - a[i + 1];
        if (lef < 0) {
            cout << -1 << endl;
            return 0;
        }
        if (lef > M[i + 1]) break;
    }
    i++;
    for (; i < n - 1; i++) {
        ans += M[i] + a[i];
    }
    ans += a[n - 1];
    cout << ans << endl;
}
