/*
引用元：https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_b
B - Kleene InversionEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/jsc2019-qual/submissions/7111415
// 提出ID : 7111415
// 問題ID : jsc2019_qual_b
// コンテストID : jsc2019-qual
// ユーザID : xryuseix
// コード長 : 2140
// 実行時間 : 14



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

int main(void) {
    ll n, k;
    ll ans = 0;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi all(n, 0), right(n, 0);
    rep(i, n) {
        rep(j, n) {
            if (a[i] > a[j]) {
                all[i]++;
                if (i < j) right[i]++;
            }
        }
    }
    ll K = (k * (k - 1) / 2) % int(1e9 + 7);
    rep(i, n) {
        ans = (ans +
               ((all[i] * K) % int(1e9 + 7) + (right[i] * k) % int(1e9 + 7)) %
                   int(1e9 + 7)) %
              int(1e9 + 7);
    }
    fin(ans);
}
