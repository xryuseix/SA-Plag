/*
引用元：https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_b
B - Problem SetEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-festival-2017-qualb/submissions/5791399
// 提出ID : 5791399
// 問題ID : code_festival_2017_qualb_b
// コンテストID : code-festival-2017-qualb
// ユーザID : xryuseix
// コード長 : 1684
// 実行時間 : 67



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

int main(void) {
    int n, i, m, j;
    cin >> n;
    vector<int> d(n, 0);
    rep(i, n) cin >> d[i];
    cin >> m;
    vi t(m, 0);
    rep(i, m) cin >> t[i];
    sort(t.begin(), t.end());
    sort(d.begin(), d.end());

    bool ch = false;
    for (i = 0, j = 0; i < n && j < m;) {
        if (d[i] == t[j]) {
            if (j == m - 1) ch = true;
            i++, j++;
        } else if (d[i] <= t[j]) {
            i++;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (ch)
        fin("YES");
    else
        fin("NO");
}
