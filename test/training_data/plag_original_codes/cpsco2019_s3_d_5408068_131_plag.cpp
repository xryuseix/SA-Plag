/*
引用元：https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_d
D - Decode RGB SequenceEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cpsco2019-s3/submissions/5408068
// 提出ID : 5408068
// 問題ID : cpsco2019_s3_d
// コンテストID : cpsco2019-s3
// ユーザID : xryuseix
// コード長 : 1792
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
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
using namespace std;
int main(void) {
    int n, i;
    string s;
    cin >> n;
    cin >> s;
    if (s.find("GG") != std::string::npos) {
        cout << "No" << endl;
        return 0;
    }
    if (s.find("RB") != std::string::npos) {
        cout << "No" << endl;
        return 0;
    }
    if (s.find('R') == std::string::npos) {
        cout << "No" << endl;
        return 0;
    }
    if (s.find('G') == std::string::npos) {
        cout << "No" << endl;
        return 0;
    }
    if (s.find('B') == std::string::npos) {
        cout << "No" << endl;
        return 0;
    }
    if (s[0] != 'R') {
        cout << "No" << endl;
        return 0;
    }
    if (s[s.length() - 1] != 'B') {
        cout << "No" << endl;
        return 0;
    }
    if (s.find("RGB") != std::string::npos) {
        cout << "Yes" << endl;
    } else
        cout << "No" << endl;

    //////////////////////////////////////////////////////
    return 0;
}
