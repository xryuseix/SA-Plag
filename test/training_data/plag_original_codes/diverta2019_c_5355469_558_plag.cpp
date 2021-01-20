/*
引用元：https://atcoder.jp/contests/diverta2019/tasks/diverta2019_c
C - AB SubstringsEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/diverta2019/submissions/5355469
// 提出ID : 5355469
// 問題ID : diverta2019_c
// コンテストID : diverta2019
// ユーザID : xryuseix
// コード長 : 1584
// 実行時間 : 3



*/
#include <bits/stdc++.h>

#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;


int main(void) {
    int i, n;
    string s;
    int ans = 0;
    cin >> n;
    int lasta = 0, firstb = 0, doubleab = 0;
    rep(i, n) {
        cin >> s;
        while (s.find("AB") != string::npos) {
            s.replace(s.find("AB"), 2, "a");
            ans++;
        }
        if (s[0] == 'B' && s[s.length() - 1] == 'A')
            doubleab++;
        else if (s[s.length() - 1] == 'A')
            lasta++;
        else if (s[0] == 'B')
            firstb++;
    }
    if (doubleab > 1) {
        doubleab = 1;
        ans += doubleab - 1;
    }
    if (doubleab == 1) {
        if (lasta > 0) {
            lasta--;
            ans++;
        }
        if (firstb > 0) {
            firstb--;
            ans++;
        }
    }
    cout << ans + min(lasta, firstb) << endl;
}
