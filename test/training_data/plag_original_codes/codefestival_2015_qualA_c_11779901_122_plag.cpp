/*
引用元：https://atcoder.jp/contests/code-festival-2015-quala/tasks/codefestival_2015_qualA_c
C - 8月31日Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-festival-2015-quala/submissions/11779901
// 提出ID : 11779901
// 問題ID : codefestival_2015_qualA_c
// コンテストID : code-festival-2015-quala
// ユーザID : xryuseix
// コード長 : 2981
// 実行時間 : 58



*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>
#pragma GCC optimize("Ofast")
using namespace std;
typedef vector<pair<int, int>> vpii;
#define rep(i, n) for (int i = 0; i < (n); ++i)

template <class T>
void lambdaSort(vector<T> &v) {
    sort(all(v), [](auto const &l, auto const &r) {
        return l.fi - l.se > r.fi - r.se;  // このbool式が成り立つ時入れ替える
    });
}

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vpii v(n);
    rep(i, n) cin >> v[i].first >> v[i].second;
    lambdaSort(v);
    int sum1 = 0, sum2 = 0;
    rep(i, n) {
        sum2 += min(v[i].first, v[i].second);
        sum1 += v[i].first;
    }
    if (sum2 > m) {
        cout << -1 << endl;
        return 0;
    }
    else if (sum1 <= m) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, n) {
        ans++;
        sum1 = sum1 - v[i].first + v[i].second;
        if (sum1 <= m) break;
    }
    cout << ans << endl;
}
