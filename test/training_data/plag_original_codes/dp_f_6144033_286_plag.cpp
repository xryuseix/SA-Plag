/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_f
F - LCSEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/6144033
// 提出ID : 6144033
// 問題ID : dp_f
// コンテストID : dp
// ユーザID : xryuseix
// コード長 : 2461
// 実行時間 : 88



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
#define rep(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main(void) {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.length() + 10, vector<int>(t.length() + 10, 0));
    rep(i, s.length()) {
        rep(j, t.length()) {
            chmax(dp[1 + i][1 + j], dp[i][1 + j]);
            chmax(dp[1 + i][1 + j], dp[1 + i][j]);
            if (s[i] == t[j]) chmax(dp[1 + i][1 + j], 1 + dp[i][j]);
        }
    }

    string res = "";
    int i = s.length();
    int j = t.length();
    while (i && j) {
        if (dp[i][j] == dp[i - 1][j]) {
            // (i-1, j) -> (i, j) と更新されていた場合
            --i;  // DP の遷移を遡る
        } else if (dp[i][j] == dp[i][j - 1]) {
            // (i, j-1) -> (i, j) と更新されていた場合
            --j;  // DP の遷移を遡る
        } else {
            // (i-1, j-1) -> (i, j) と更新されていた場合
            // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
            res = s[i - 1] + res;
            i--;
            j--;  // DP の遷移を遡る
        }
    }
    cout << res << endl;
}
