/*
引用元：https://atcoder.jp/contests/arc045/tasks/arc045_a
A - スペース高橋君Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc045/submissions/5395471
// 提出ID : 5395471
// 問題ID : arc045_a
// コンテストID : arc045
// ユーザID : xryuseix
// コード長 : 1666
// 実行時間 : 1



*/
#include <bits/stdc++.h>

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
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define P 1000000007
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
// set<int>::iterator it;

int main(void) {
    string s[150];
    int j, i;
    rep(i, 150) s[i] = "";
    string t = "";
    char c;
    while (1) {
        scanf("%c", &c);
        if (c == '\n') break;
        t += c;
    }
    j = 0;
    rep(i, t.length()) {
        if (t[i] == ' ') {
            j++;
            continue;
        } else {
            s[j] += t[i];
        }
    }
    if (s[0] == "Left") {
        cout << "<";
    } else if (s[0] == "Right") {
        cout << ">";
    } else {
        cout << "A";
    }
    i = 1;
    while (s[i] != "") {
        if (s[i] == "Right") {
            cout << " >";
        } else if (s[i] == "Left") {
            cout << " <";
        } else {
            cout << " A";
        }
        i++;
    }
    cout << endl;

    //////////////////////////////////////////////////////
    return 0;
}
