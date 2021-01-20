/*
引用元：https://atcoder.jp/contests/arc083/tasks/arc083_a
C - Sugar WaterEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc083/submissions/7057144
// 提出ID : 7057144
// 問題ID : arc083_a
// コンテストID : arc083
// ユーザID : xryuseix
// コード長 : 2026
// 実行時間 : 31



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
using namespace std;

int main(void) {
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<ll> wa, su;
    ll answa = 1, anssu = 0;
    double nomax = -1.0;
    int i, j;
    for (i = 0; i < f; i++) {
        for (j = 0; j < f; j++) {
            if (c * i + d * j <= f && a * i + d * j > 0) {
                su.push_back(c * i + d * j);
            }
        }
    }

    for (i = 0; i < f; i++) {
        for (j = 0; j < f; j++) {
            if ((a * i + b * j) * 100 <= f && a * i + b * j >= 0) {
                wa.push_back((a * i + b * j) * 100);
            }
        }
    }

    for (i = 0; i < wa.size(); i++) {
        for (j = 0; j < su.size(); j++) {
            int s = su[j];
            double m = (wa[i]) * e / 100;
            if (s <= m) {
                double per = (double)s / (wa[i] + s);
                if (nomax <= per && wa[i] + s <= f) {
                    anssu = su[j];
                    nomax = per;
                    answa = wa[i];
                }
            }
        }
    }
    if (answa == 1) {
        answa = min(a, b) * 100;
    }
    cout << answa + anssu << " " << anssu << endl;
}
