/*
引用元：https://atcoder.jp/contests/abc092/tasks/arc093_b
D - Grid ComponentsEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc092/submissions/7817476
// 提出ID : 7817476
// 問題ID : arc093_b
// コンテストID : abc092
// ユーザID : xryuseix
// コード長 : 2756
// 実行時間 : 2

*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
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
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())

int a, b;
int ly = 1, lx = 1, ry = 1, rx = 51;
int main(void) {
    cin >> a >> b;
    vvc v(100, vc(100, '.'));
    rep(i, 100) {
        for (int j = 50; j < 100; j++) {
            v[i][j] = '#';
        }
    }

    rep(i, b - 1) {
        v[ly][lx] = '#';
        lx += 2;
        if (lx >= 49) {
            lx = 1;
            ly += 2;
        }
    }
    rep(i, a - 1) {
        v[ry][rx] = '.';
        rx += 2;
        if (rx >= 99) {
            rx = 51;
            ry += 2;
        }
    }
    cout << 100 << " " << 100 << endl;
    rep(i, 100) {
        rep(j, 100) { cout << v[i][j]; }
        cout << endl;
    }
}
