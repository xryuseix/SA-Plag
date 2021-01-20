/*
引用元：https://atcoder.jp/contests/abc061/tasks/abc061_c
C - Big ArrayEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc061/submissions/5561361
// 提出ID : 5561361
// 問題ID : abc061_c
// コンテストID : abc061
// ユーザID : xryuseix
// コード長 : 1640
// 実行時間 : 25



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

ll i, k, n, s, t, sum = 0;
vector<ll> dsum;

int main(void) {
    cin >> n >> k;
    vector<pair<ll, ll>> a(n, make_pair(0, 0));
    rep(i, n) {
        cin >> s >> t;
        a[i] = make_pair(s, t);
    }
    sort(a.begin(), a.end());
    rep(i, n) {
        if (!i)
            dsum.push_back(a[i].second + dsum[i - 1]);
        else
            dsum.push_back(a[i].second);
    }

    rep(i, n + 1) {
        if (k > dsum[i]) continue;
        cout << a[i].first << endl;
        return 0;
    }

}
