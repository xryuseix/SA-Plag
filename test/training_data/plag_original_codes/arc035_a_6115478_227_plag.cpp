/*
引用元：https://atcoder.jp/contests/arc035/tasks/arc035_a
A - 高橋くんと回文Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc035/submissions/6115478
// 提出ID : 6115478
// 問題ID : arc035_a
// コンテストID : arc035
// ユーザID : xryuseix
// コード長 : 1560
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
const long long LLINF = 1LL << 60;
// g++ -std=c++1z temp.cpp
//./a.out

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //////////////////////////////////////////////////////
    string s;
    cin >> s;
    bool ch = true;
    rep(i, s.length() / 2) {
        if (s[i] == s[s.length() - 1 - i] || s[i] == '*' ||
            '*' == s[s.length() - 1 - i])
            continue;
        ch = false;
    }
    if (!ch)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    //////////////////////////////////////////////////////
    return 0;
}
