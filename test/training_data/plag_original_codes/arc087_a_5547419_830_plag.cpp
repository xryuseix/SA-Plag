/*
引用元：https://atcoder.jp/contests/abc082/tasks/arc087_a
C - Good SequenceEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc082/submissions/5547419
// 提出ID : 5547419
// 問題ID : arc087_a
// コンテストID : abc082
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
    int n;
    cin >> n;
    int ans = 0, tmp;
    vector<int> v(n, 0);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    rep(i, n) {
        tmp = v[i];
        int j = false;
        while (i + j < n && v[i + j] == v[i]) {
            j += 1;
        }
        if (j > tmp)
            ans = ans + j - tmp;
        else if (j < tmp)
            ans = ans + j;
        i = i + j - 1;
    }
    cout << ans << endl;
}
