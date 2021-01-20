/*
引用元：https://atcoder.jp/contests/keyence2019/tasks/keyence2019_c
C - Exam and WizardEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/keyence2019/submissions/7923175
// 提出ID : 7923175
// 問題ID : keyence2019_c
// コンテストID : keyence2019
// ユーザID : xryuseix
// コード長 : 2830
// 実行時間 : 83

*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
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
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define PI acos(-1)

int main(void) {
    int n;
    cin >> n;
    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll asum = 0, bsum = 0;
    rep(i, n) { asum += a[i]; }
    rep(i, n) { bsum += b[i]; }
    if (asum < bsum) {
        fin(-1);
        return 0;
    }

    asum -= bsum;
    vi rest;
    int ans = 0, pos = 0;
    rep(i, n) {
        if (a[i] > b[i])
            rest.push_back((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((a[i] - b[i]))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
        else if (a[i] == b[i])
            continue;
        else
            ans++;
    }
    Sort(rest);
    while (pos < rest.size()) {
        if (rest[pos] <= asum) {
            asum -= rest[pos];
        } else
            ans++;
        pos++;
    }
    if (asum > 0 && ans == 0) {
        ans++;
    }
    fin(ans);
}
