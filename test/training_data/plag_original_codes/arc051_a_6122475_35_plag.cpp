/*
引用元：https://atcoder.jp/contests/arc051/tasks/arc051_a
A - 塗り絵Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc051/submissions/6122475
// 提出ID : 6122475
// 問題ID : arc051_a
// コンテストID : arc051
// ユーザID : xryuseix
// コード長 : 2724
// 実行時間 : 1



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
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define P 1000000007
#define STI(s) atoi(s.c_str())  // string to int
#define mp(p, q) make_pair(p, q)
#define Sort(a) sort(a.begin(), a.end())
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const int INF = INT_MAX;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //////////////////////////////////////////////////////

    bool red = true, blue = true;
    int x1, x2, x3, y1, y2, y3, r1, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> x3 >> y3;
    int co = 0;
    r2 = pow(x2 - x1, 2) + pow(y2 - y1, 2);  //左下
    if (r1 * r1 >= r2) co++;
    r2 = pow(x2 - x1, 2) + pow(y3 - y1, 2);  //左上
    if (r1 * r1 >= r2) co++;
    r2 = pow(x3 - x1, 2) + pow(y3 - y1, 2);  //右上
    if (r1 * r1 >= r2) co++;
    r2 = pow(x3 - x1, 2) + pow(y2 - y1, 2);  //右下
    if (r1 * r1 >= r2) co++;

    if (co == 4) blue = false;

    if (x1 + r1 <= x3 && x1 - r1 >= x2 && y1 + r1 <= y3 && y1 - r1 >= y2)
        red = false;

    if (red)
        fin("YES");
    else
        fin("NO");
    if (blue)
        fin("YES");
    else
        fin("NO");

    //////////////////////////////////////////////////////
    return 0;
}
