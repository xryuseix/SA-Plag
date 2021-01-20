/*
引用元：https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_c
C - Camp ReceptionEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cpsco2019-s3/submissions/5407711
// 提出ID : 5407711
// 問題ID : cpsco2019_s3_c
// コンテストID : cpsco2019-s3
// ユーザID : xryuseix
// コード長 : 1580
// 実行時間 : 51



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
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main(void) {
    int i, n, s, t;
    cin >> n;
    vpii v;
    rep(i, n) {
        cin >> s >> t;
        v.push_back(make_pair(s, t));
    }
    sort(v.begin(), v.end());
    int l = v[0].second;
    int f = v[0].first;
    int ans = 1;
    rep(i, n) {
        if (i == 1) continue;
        if (v[i].first >= f && v[i].first <= l) {
            chmax(l, v[i].second);
        } else {
            l = v[i].second;
            f = v[i].first;
            ++ans;
        }
    }
    cout << ans << endl;
}
