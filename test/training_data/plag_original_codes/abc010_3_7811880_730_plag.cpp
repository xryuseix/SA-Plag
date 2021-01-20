/*
引用元：https://atcoder.jp/contests/abc010/tasks/abc010_3
C - 浮気調査Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc010/submissions/7811880
// 提出ID : 7811880
// 問題ID : abc010_3
// コンテストID : abc010
// ユーザID : xryuseix
// コード長 : 2001
// 実行時間 : 1



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
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())


double dis(int xa, int ya, int xb, int yb) {
    return sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
}

int main(void) {
    int txa, tya, txb, tyb, t, v, n, x, y;
    cin >> txa >> tya >> txb >> tyb >> t >> v >> n;
    int move = t * v;
    double yoru;
    bool ch = false;
    rep(i, n) {
        cin >> x >> y;
        yoru = dis(x, y, txa, tya) + dis(x, y, txb, tyb);
        if (yoru <= move) {
            ch = true;
        }
    }
    if (ch)
        fin("YES");
    else
        fin("NO");
}
