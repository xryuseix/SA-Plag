/*
引用元：https://atcoder.jp/contests/abc005/tasks/abc005_3
C - おいしいたこ焼きの売り方Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc005/submissions/4643428
// 提出ID : 4643428
// 問題ID : abc005_3
// コンテストID : abc005
// ユーザID : xryuseix
// コード長 : 1436
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
#define ull unsigned long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX;
using namespace std;

int t, m, n, tmp, per = -1;
queue<int> a, b;

int main(void) {
    cin >> t >> n;
    rep(i, n) {
        cin >> tmp;
        a.push(tmp);
    }
    cin >> m;
    rep(i, m) {
        cin >> tmp;
        b.push(tmp);
    }
    bool ch = true;
    for (int i = 0; i < m; i++) {
        per = b.front();
        b.pop();
        if (!a.size()) ch = false;
        while (a.size()) {
            tmp = a.front();
            a.pop();
            if (per - tmp <= t && per - tmp >= 0)
                break;
            if (!a.size()) {
                ch = false;
            }
        }
    }
    if (ch)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
