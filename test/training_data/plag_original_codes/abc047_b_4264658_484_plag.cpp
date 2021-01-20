/*
引用元：https://atcoder.jp/contests/abc047/tasks/abc047_b
B - Snuke's Coloring 2 (ABC Edit)Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc047/submissions/4264658
// 提出ID : 4264658
// 問題ID : abc047_b
// コンテストID : abc047
// ユーザID : xryuseix
// コード長 : 1506
// 実行時間 : 2



*/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>
#define ld long double
#define ll long long int
#define ull unsigned long long int
using namespace std;

const long long INF = 1LL << 60;

int main(void) {

    int w, h, n, a, b, c, i, j, k;
    cin >> w >> h >> n;
    int m[h][w];
    for (j = 0; j < h; j++)
        for (k = 0; k < w; k++) m[j][k] = 0;
    for (i = 0; i < n; i++) {
        cin >> a >> b >> c;
        switch (c) {
            case 2:
                for (j = 0; j < h; j++) {
                    for (k = 0; k < w; k++) {
                        if (k >= a) m[j][k] = 1;
                    }
                }
                break;
            case 1:
                for (j = 0; j < h; j++) {
                    for (k = 0; k < w; k++) {
                        if (k < a) m[j][k] = 1;
                    }
                }
                break;
            case 4:
                for (j = 0; j < h; j++) {
                    for (k = 0; k < w; k++) {
                        if (j >= b) m[j][k] = 1;
                    }
                }
                break;
            case 3:
                for (j = 0; j < h; j++) {
                    for (k = 0; k < w; k++) {
                        if (j < b) m[j][k] = 1;
                    }
                }
                break;
        }
    }
    int s = 0;
    for (j = 0; j < h; j++) {
        for (k = 0; k < w; k++) {
            s += m[j][k];
        }
    }
    cout << w * h - s << endl;

    return 0;
}
