/*
引用元：https://atcoder.jp/contests/abc024/tasks/abc024_c
C - 民族大移動Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc024/submissions/7951925
// 提出ID : 7951925
// 問題ID : abc024_c
// コンテストID : abc024
// ユーザID : xryuseix
// コード長 : 2538
// 実行時間 : 13



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
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> v(d);
    rep(i, d) {
        int a, b;
        cin >> a >> b;
        v[i] = mp(a, b);
    }
    rep(j, k) {
        int s, t;
        cin >> s >> t;
        int ans = 0;
        while (s != t) {
            for (int i = 0; i < d; i++) {
                if (s < t) {
                    if (v[i].first <= s && s <= v[i].second) {
                        s = v[i].second;
                    }
                } else {
                    if (v[i].first <= s && s <= v[i].second) {
                        s = v[i].first;
                    }
                }
                if ((s < t && s >= t) || (s >= t && s <= t)) {
                    s = t;
                    ans = i + 1;
                    break;
                }
            }
        }

        fin(ans);
    }
}
