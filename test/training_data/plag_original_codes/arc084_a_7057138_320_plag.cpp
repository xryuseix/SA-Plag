/*
引用元：https://atcoder.jp/contests/abc077/tasks/arc084_a
C - Snuke FestivalEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc077/submissions/7057138
// 提出ID : 7057138
// 問題ID : arc084_a
// コンテストID : abc077
// ユーザID : xryuseix
// コード長 : 1677
// 実行時間 : 60



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

using namespace std;

int main(void) {
    int i, n, an, cn;
    cin >> n;

    vector<int> a(n, 0), b(n, 0), c(n, 0);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    sort(c.begin(), c.end());
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    ll ans = 0;
    rep(i, n) {
        ans += (ll)(lower_bound((a).begin(), (a).end(), b[i]) - a.begin()) *
               (c.end() - upper_bound((c).begin(), (c).end(), b[i]));
    }
    fin(ans);
}
