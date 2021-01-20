/*
引用元：https://atcoder.jp/contests/abc069/tasks/arc080_b
D - Grid ColoringEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc069/submissions/7057147
// 提出ID : 7057147
// 問題ID : arc080_b
// コンテストID : abc069
// ユーザID : xryuseix
// コード長 : 1759
// 実行時間 : 3



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
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define P 1000000007
using namespace std;

int main(void) {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n, 0);
    vector<int> num;
    rep(i, n) cin >> a[i];
    rep(i, n) rep(j, a[i]) num.push_back(i + 1);

    vvi ans(h, vi(w, 0));
    int p = 0;
    rep(i, h) {
        if (!(i % 2)) {
            rep(j, w) {
                ans[i][j] = num[p];
                p++;
            }
        } else {
            for (int j = w - 1; j >= 0; j--) {
                ans[i][j] = num[p];
                p++;
            }
        }
    }
    rep(i, h) {
        rep(j, w) {
            if (j != w - 1)
                cout << ans[i][j] << " ";
            else
                cout << ans[i][j] << endl;
        }
    }
}
