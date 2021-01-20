/*
引用元：https://atcoder.jp/contests/arc080/tasks/arc080_b
D - Grid ColoringEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc080/submissions/5791318
// 提出ID : 5791318
// 問題ID : arc080_b
// コンテストID : arc080
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
#define rep(i, n) for (i = 0; i < n; i++)
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
const long long LLINF = 1LL << 60;

int h, w, i, j, n;
vector<int> num;
vector<int> a(201010, 0);
vvi ans(2020, vi(2020, 0));
int p = 0;
int main(void) {
    cin >> h >> w >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) rep(j, a[i]) num.push_back(i + 1);

    rep(i, h) {
        if (i % 2 == 0) {
            rep(j, w) {
                ans[i][j] = num[p];
                p++;
            }
        } else {
            for (j = w - 1; j >= 0; j--) {
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
