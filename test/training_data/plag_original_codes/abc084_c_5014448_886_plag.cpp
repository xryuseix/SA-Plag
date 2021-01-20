/*
引用元：https://atcoder.jp/contests/abc084/tasks/abc084_c
C - Special TrainsEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc084/submissions/5014448
// 提出ID : 5014448
// 問題ID : abc084_c
// コンテストID : abc084
// ユーザID : xryuseix
// コード長 : 1549
// 実行時間 : 4



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
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
using namespace std;
const long long LLINF = 1LL << 60;

int main(void) {
    int n;
    cin >> n;
    int c[n - 1], s[n], f[n - 1];
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
    s[n - 1] = 0;
    int ans;
    for (int i = 0; i < n - 1; i++) {
        ans = s[i];
        for (int j = i; j < n - 2; j++) {
            ans += c[j];
            if (ans <= s[j + 1]) {
                ans = s[j + 1];
            } else {
                ans = s[j + 1] + f[j + 1] * ceil((double)(ans - s[j + 1]) /
                                                 (double)f[j + 1]);
            }
        }
        cout << ans + c[n - 2] << endl;
    }
    cout << 0 << endl;

    return 0;
}
