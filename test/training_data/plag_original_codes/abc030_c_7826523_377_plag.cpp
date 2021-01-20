/*
引用元：https://atcoder.jp/contests/abc030/tasks/abc030_c
C - 飛行機乗りEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc030/submissions/7826523
// 提出ID : 7826523
// 問題ID : abc030_c
// コンテストID : abc030
// ユーザID : xryuseix
// コード長 : 2873
// 実行時間 : 75


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
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {
    int n, m;
    int x, y;
    cin >> n >> m >> x >> y;
    vi a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    ll zero = 0;
    ll ans = zero;

    a.push_back(INF);
    b.push_back(INF);

    ll turn = zero;
    ll time = a[zero];

    while (zero + 1) {
        if (turn == zero) {
            auto it = lower_bound(b.begin(), b.end(), time + x);
            if (*it == INF) {
                ans++;
                break;
            }
            time = *it;
            turn = 1 - turn;
            ans++;
        } else {
            auto it = lower_bound(a.begin(), a.end(), time + y);
            if (*it == INF) {
                ans++;
                break;
            }
            time = *it;
            turn = zero + 1 - turn;
            ans++;
        }
    }
    fin(ans / 2);
}
