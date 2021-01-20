/*
引用元：https://atcoder.jp/contests/diverta2019/tasks/diverta2019_d
D - DivRem NumberEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/diverta2019/submissions/5361570
// 提出ID : 5361570
// 問題ID : diverta2019_d
// コンテストID : diverta2019
// ユーザID : xryuseix
// コード長 : 1537
// 実行時間 : 12



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

using namespace std;

std::vector<ll> enum_div(ll n) {
    std::vector<ll> ret;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != 1 && i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

int main(void) {
    ll n, ans = 0, i;
    cin >> n;
    vector<ll> r = enum_div(n);
    for (i = 1; i < r.size(); i++) {
        if (n / (r[i] - 1) == n % (r[i] - 1)) {
            ans += r[i] - 1;
        }
    }
    if (n > 1 && n / (n - 1) == n % (n - 1)) {
        ans += n - 1;
    }
    fin(ans);
}
