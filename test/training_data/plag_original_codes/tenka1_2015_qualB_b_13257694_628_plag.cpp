/*
引用元：https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_b
B - 天下一リテラルEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/tenka1-2015-qualb/submissions/13257694
// 提出ID : 13257694
// 問題ID : tenka1_2015_qualB_b
// コンテストID : tenka1-2015-qualb
// ユーザID : xryuseix
// コード長 : 2928
// 実行時間 : 3



*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << '\n'

int main() {
    string s;
    cin >> s;
    if (s == "{}") {
        fin("dict");
        return 0;
    }
    int sum = 0;

    rep(i, s.size()) {
        if (s[i] == '{')
            sum++;
        else if (s[i] == '}')
            sum--;
        else if (sum == 1 && s[i] == ':') {
            fin("dict");
            return 0;
        }
    }
    fin("set");
}