/*
引用元：https://atcoder.jp/contests/cpsco2019-s4/tasks/cpsco2019_s4_b
B - MeetingEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cpsco2019-s4/submissions/5491458
// 提出ID : 5491458
// 問題ID : cpsco2019_s4_b
// コンテストID : cpsco2019-s4
// ユーザID : xryuseix
// コード長 : 1428
// 実行時間 : 1



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

int n, d;
int ans = 0, k;
string s[201010];
int main(void) {
    cin >> n >> d;
    rep(i, d) cin >> s[i];

    rep(i, d - 1) {
        for (int j = i + 1; j < d; j++) {
            int t = 0;
            for (k = 0; k < s[i].length(); k++) {
                if (s[i][k] == 'o' || s[j][k] == 'o') t++;
            }

            ans = max(ans, t);
        }
    }

    fin(ans);
}
