/*
引用元：https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_c
C - Strawberry Cakes
Time Limit : 2 sec / Memory Limit : 1024 MB
配点: 400 点
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
#include <unordered_set>
#include <vector>
#pragma GCC optimize("Ofast")
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> s(h);
    vector<vector<int>> v(h, vector<int>(w, 0));
    rep(i, h) cin >> s[i];
    int num = 1;
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] != '#') continue;
            v[i][j] = num;
            num++;
        }
    }

    for (int i = 1; i < h; i++) {
        rep(j, w) {
            if (v[i][j]) continue;
            v[i][j] = v[i - 1][j];
        }
    }
    for (int i = h - 2; i >= 0; i--) {
        rep(j, w) {
            if (v[i][j]) continue;
            v[i][j] = v[i + 1][j];
        }
    }

    for (int i = 1; i < w; i++) {
        rep(j, h) {
            if (v[j][i]) continue;
            v[j][i] = v[j][i - 1];
        }
    }
    for (int i = w - 2; i >= 0; i--) {
        rep(j, h) {
            if (v[j][i]) continue;
            v[j][i] = v[j][i + 1];
        }
    }

    rep(i, h) {
        rep(j, w) {
            if (!j)
                cout << v[i][0];
            else
                cout << " " << v[i][j];
        }
        cout << endl;
    }
}
