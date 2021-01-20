/*
引用元：https://atcoder.jp/contests/code-formula-2014-quala/tasks/code_formula_2014_qualA_b
B - ボウリングゲームEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-formula-2014-quala/submissions/6628242
// 提出ID : 6628242
// 問題ID : code_formula_2014_qualA_b
// コンテストID : code-formula-2014-quala
// ユーザID : xryuseix
// コード長 : 2960
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
typedef vector<int> vi;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
    int a, b;
    cin >> a >> b;
    vi v(a), w(b), pin(10, 0);  // 0..倒れてない、1..１かいめ
    rep(i, a) cin >> v[i];
    rep(i, b) cin >> w[i];
    rep(i, b) pin[w[i]] = 2;
    rep(i, a) pin[v[i]] = 1;
    int n;
    {
        n = 7;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << " ";
    }
    {
        n = 8;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << " ";
    }
    {
        n = 9;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << " ";
    }
    {
        n = 0;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << endl;

        cout << " ";
    }
    {
        n = 4;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << " ";
    }
    {
        n = 5;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << " ";
    }
    {
        n = 6;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << endl;

        cout << "  ";
    }
    {
        n = 2;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << " ";
    }
    {
        n = 3;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << endl;

        cout << "   ";
    }
    {
        n = 1;
        if (pin[n] == 0)
            cout << 'x';
        else if (pin[n] == 1)
            cout << '.';
        else
            cout << 'o';
        cout << endl;
    }
}
