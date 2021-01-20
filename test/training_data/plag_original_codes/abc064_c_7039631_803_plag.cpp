/*
引用元：https://atcoder.jp/contests/abc064/tasks/abc064_c
C - Colorful LeaderboardEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc064/submissions/7039631
// 提出ID : 7039631
// 問題ID : abc064_c
// コンテストID : abc064
// ユーザID : xryuseix
// コード長 : 2199
// 実行時間 : 1



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
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())

const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {
    vi v(9);
    v[0] = 0;
    v[1] = 399;
    v[2] = 799;
    v[3] = 1199;
    v[4] = 1599;
    v[5] = 1999;
    v[6] = 2399;
    v[7] = 2799;
    v[8] = 3199;

    int n;
    cin >> n;
    vi a(n);
    vi co(9, 0);
    rep(i, n) cin >> a[i];
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        co[distance(v.begin(), it)-1]++;
    }

    ll ans = 0;
    for (int i = 0; i < 8; i++) {
        if (co[i] > 0) {
            ans++;
        }
    }

    if (ans > 0)
        cout << ans << " ";
    else
        cout << "1 ";
    cout << ans + co[8] << endl;
}
