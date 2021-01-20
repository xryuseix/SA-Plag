/*
引用元：https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_c
C - Infinite GridEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/s8pc-6/submissions/5027744
// 提出ID : 5027744
// 問題ID : s8pc_6_c
// コンテストID : s8pc-6
// ユーザID : xryuseix
// コード長 : 2015
// 実行時間 : 75



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
#define rep(i, n) for (i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
using namespace std;

bool up = 0, down = 0;
int ddfs(vector<vector<char>> &v, int x, int y, int border) {
    //	cout<<x<<" "<<v[x][y]<<endl;
    if (v[x][y] == '%' || v[x][y] == '#' || down) return 0;
    if (x == border) {
        down = true;
        return 0;
    }
    ddfs(v, x, y + 1, border);
    ddfs(v, x + 1, y, border);
}
int udfs(vector<vector<char>> &v, int x, int y, int border) {
    if (v[x][y] == '%' || v[x][y] == '#' || up) return 0;
    if (x == border) {
        up = true;
        return 0;
    }
    udfs(v, x, y - 1, border);
    udfs(v, x - 1, y, border);
}

int main(void) {
    int h;
    int w;
    int i;
    int j;
    int border;
    bool yoko = 0;
    bool ch = 0;
    cin >> h >> w;
    vector<vector<char>> v(h + 2, vector<char>(w + 2, '%'));
    string t, s = string(w, '.');
    rep(i, h) {
        cin >> t;
        if (s == t) {
            ch = 1;
            border = i;
            border++;
        }
        rep(j, w) v[i + 1][j + 1] = t[j];
    }

    //横一列に並んだまで、右上から、さらに右下からたどり着けるか
    if (!ch) {
        cout << ":(" << endl;
        return 0;
    }
    ddfs(v, 1, 1, border);
    udfs(v, h, w, border);

    if (up && down)
        cout << "Yay!" << endl;
    else
        cout << ":(" << endl;
}
