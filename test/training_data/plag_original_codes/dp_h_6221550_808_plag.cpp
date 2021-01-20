/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_h
H - Grid 1Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6221550
// 提出ID : 6221550
// 問題ID : dp_h
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 2238
// 実行時間 : 19



*/
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
typedef vector<ll> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<ll>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = 1; i <= (n); ++i)
#define drep(i, n) for (ll i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define P 1000000007


int main(void) {
    ll h, w;
    cin >> h >> w;
    char grid[h][w];
    ll path[h][w];
    rep(i, h) rep(j, w) cin >> grid[i][j];
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            path[i][j] = 0;
        }
    }
    for (ll i = 0; i < w; i++) {
        if (grid[0][i] == '.')
            path[0][i] = 1;
        else
            break;
    }
    for (ll i = 0; i < h; i++) {
        if (grid[i][0] == '.')
            path[i][0] = 1;
        else
            break;
    }
    for (ll i = 1; i < h; i++) {
        for (ll j = 1; j < w; j++) {
            if (grid[i][j] == '#')
                path[i][j] = 0;
            else {
                path[i][j] = max(path[i][j], path[i - 1][j] + path[i][j - 1]);
                path[i][j] %= P;
            }
        }
    }
    cout << path[h - 1][w - 1] << endl;
}
