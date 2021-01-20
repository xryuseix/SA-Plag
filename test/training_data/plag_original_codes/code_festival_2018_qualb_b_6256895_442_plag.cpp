/*
引用元：https://atcoder.jp/contests/code-festival-2018-qualb/tasks/code_festival_2018_qualb_b
B - TensaiEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-festival-2018-qualb/submissions/6256895
// 提出ID : 6256895
// 問題ID : code_festival_2018_qualb_b
// コンテストID : code-festival-2018-qualb
// ユーザID : xryuseix
// コード長 : 1979
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
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << endl

int main(void) {
    int n, x, ans = 0;
    cin >> n >> x;
    vvi v(n, vi(3, 0));
    rep(i, n) cin >> v[i][0] >> v[i][1];
    rep(j, x) {
        rep(i, n) v[i][2] = (v[i][0] + 1 - v[i][0]) * v[i][1];
        int maxs = 0, maxp = 0;
        rep(i, n) {
            if (v[i][2] >= maxs) {
                maxs = v[i][2];
                maxp = i;
            }
        }
        ++v[maxp][0];
    }
    rep(i, n) ans += v[i][0] * v[i][1];
    fin(ans);
}
