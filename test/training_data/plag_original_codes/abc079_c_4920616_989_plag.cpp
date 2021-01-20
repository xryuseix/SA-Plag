/*
引用元：https://atcoder.jp/contests/abc079/tasks/abc079_c
C - Train TicketEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc079/submissions/4920616
// 提出ID : 4920616
// 問題ID : abc079_c
// コンテストID : abc079
// ユーザID : xryuseix
// コード長 : 1396
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
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
using namespace std;
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
const long long LLINF = 1LL << 60;

int main(void) {
    int i;
    vector<char> v;
    string s;
    cin >> s;
    int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
    if (a + b + c + d == 7)
        printf("%d+%d+%d+%d=7", a, b, c, d);
    else if (a + b + c - d == 7)
        printf("%d+%d+%d-%d=7", a, b, c, d);
    else if (a - b - c + d == 7)
        printf("%d-%d-%d+%d=7", a, b, c, d);
    else if (a - b - c - d == 7)
        printf("%d-%d-%d-%d=7", a, b, c, d);
    else if (a + b - c + d == 7)
        printf("%d+%d-%d+%d=7", a, b, c, d);
    else if (a + b - c - d == 7)
        printf("%d+%d-%d-%d=7", a, b, c, d);
    else if (a - b + c + d == 7)
        printf("%d-%d+%d+%d=7", a, b, c, d);
    else if (a - b + c - d == 7)
        printf("%d-%d+%d-%d=7", a, b, c, d);
}
