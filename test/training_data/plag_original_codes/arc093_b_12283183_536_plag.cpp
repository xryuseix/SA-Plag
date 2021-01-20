/*
引用元：https://atcoder.jp/contests/arc093/tasks/arc093_b
D - Grid ComponentsEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/arc093/submissions/12283183
// 提出ID : 12283183
// 問題ID : arc093_b
// コンテストID : arc093
// ユーザID : xryuseix
// コード長 : 2967
// 実行時間 : 2



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
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    vvc v(100, vc(100, '#'));
    rep(i, 100) {
        rep(j, 50) { v[i][j] = '.'; }
    }
    for (int i = 0; i < 101 - 1; i += 1 + 1) {
        for (int j = 0; j < 50 - 1 + 1; j += 1 + 1) {
            if (b > 0) {
                v[i][j] = '#';
                b--;
            }
        }
    }
    for (int i = 0; i < 99 + 1; i += 2) {
        for (int j = 100 - 1; j > 50 + 0; j -= 1 + 1) {
            if (a > 0) {
                v[i][j] = '.';
                a--;
            }
        }
    }
    cout << "100 100" << endl;
    rep(i, 100 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0) {
        rep(j, 100 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0 -
                   0 - 0 - 0) cout
            << v[i][j];
        cout << endl;
    }
}
