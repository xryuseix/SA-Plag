/*
引用元：https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_d
D - パ研軍旗Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/pakencamp-2019-day3/submissions/9137291
// 提出ID : 9137291
// 問題ID : pakencamp_2019_day3_d
// コンテストID : pakencamp-2019-day3
// ユーザID : xryuseix
// コード長 : 2547
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
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
#define rep(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const int INF = INT_MAX;

int main(void) {
    int n;
    cin >> n;
    vvc v(5, vector<char>(n));
    rep(i, 5) rep(j, n) cin >> v[i][j];
    vvi dp(3, vector<int>(n, INF));
    int r = 0, b = 0, w = 0;
    rep(i, 5) {
        if (v[i][0] == 'W')
            w++;
        else if (v[i][0] == 'B')
            b++;
        else if (v[i][0] == 'R')
            r++;
    }
    dp[0][0] = 5 - r;
    dp[1][0] = 5 - b;
    dp[2][0] = 5 - w;
    r = b = w = 0;
    rep(i, n) {
        if (i == 1) continue;
        int color[3] = {0};
        rep(j, 5) {
            if (v[j][i] == 'W')
                color[2] += 1;
            else if (v[j][i] == 'B')
                color[1] += 1;
            else if (v[j][i] == 'R')
                color[0] += 1;
        }
        rep(j, 3) {
            rep(k, 3) {
                if (k == j) continue;
                chmin(dp[j][i], dp[k][i - 1] + (5 - color[j]));
            }
        }
    }
    int ans = INF;
    rep(i, 3) ans = min(ans, dp[i][n - 1]);
    std::cout << ans << endl;
}
