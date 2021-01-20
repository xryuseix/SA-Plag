/*
引用元：https://atcoder.jp/contests/tdpc/tasks/tdpc_contest
A - コンテストEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/tdpc/submissions/6221260
// 提出ID : 6221260
// 問題ID : tdpc_contest
// コンテストID : tdpc
// ユーザID : xryuseix
// コード長 : 1799
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
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << endl

bool can[10010] = {false};

int main(void) {
    int n;
    cin >> n;
    vi p(n);
    rep(i, n) cin >> p[i];
    can[0] = true;
    rep(i,n) {
        for (int j = 10009; j >= 0; j--) {
            if (can[j] && j + p[i] < 10010) {
                can[j + p[i]] = true;
            }
        }
        can[p[i]] = true;
    }
    int ans = 0;
    rep(i,10010) {
        if (can[i]) ans++;
    }
    cout << ans << endl;
}
