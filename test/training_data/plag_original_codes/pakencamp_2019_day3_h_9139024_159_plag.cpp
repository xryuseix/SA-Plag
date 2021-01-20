/*
引用元：https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_h
H - パ研王国を守れ！Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/pakencamp-2019-day3/submissions/9139024
// 提出ID : 9139024
// 問題ID : pakencamp_2019_day3_h
// コンテストID : pakencamp-2019-day3
// ユーザID : xryuseix
// コード長 : 2329
// 実行時間 : 2



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
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main(void) {
    int n, m;
    cin >> n >> m;
    vs v(n);
    rep(i, n) cin >> v[i];
    rep(i, n) rep(j, n) {
        if (v[i][j] != 'Q') continue;
        rep(k, 8) {
            int X = j + dx[k];
            int Y = i + dy[k];
            while (1) {
                if (!(X >= 0 && X < n && Y >= 0 && Y < n)) break;
                if (v[Y][X] == '#' || v[Y][X] == 'Q') break;
                if (v[Y][X] == 'X' && v[i + dy[k]][j + dx[k]] == '.') {
                    v[i + dy[k]][j + dx[k]] = '#';
                    break;
                }
                Y += dy[k];
                X += dx[k];
            }
        }
    }
    rep(i, n) cout << v[i] << endl;
}
