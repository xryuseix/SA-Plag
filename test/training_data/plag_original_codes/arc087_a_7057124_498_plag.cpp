/*
引用元：https://atcoder.jp/contests/arc087/tasks/arc087_a
C - Good SequenceEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc087/submissions/7057124
// 提出ID : 7057124
// 問題ID : arc087_a
// コンテストID : arc087
// ユーザID : xryuseix
// コード長 : 1457
// 実行時間 : 17



*/
#include <bits/stdc++.h>

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
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int i, j;
    int ans = 0, tmp;
    vector<int> v(n, 0);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    rep(i, n) {
        tmp = v[i];
        j = 0;
        while (i + j < n && v[i + j] == v[i]) {
            j++;
        }
        if (j > tmp)
            ans += j - tmp;
        else if (j < tmp)
            ans += j;
        i += j - 1;
    }
    cout << ans << endl;
}
