/*
引用元：https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_b
B - Picking UpEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/diverta2019-2/submissions/8123484
// 提出ID : 8123484
// 問題ID : diverta2019_2_b
// コンテストID : diverta2019-2
// ユーザID : xryuseix
// コード長 : 2168
// 実行時間 : 15



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
typedef vector<bool> vb;
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
const ll LLINF = 1LL << 62;

int main(void) {
    long long int n;
    cin >> n;
    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    long long int ans = INF;
    for (long long int i = 0; i < n; i++) {
        for (long long int j = 0; j < n; j++) {
            if (i == j) continue;
            long long int p = x[i] - x[j], q = y[i] - y[j];
            vi group;
            for (long long int k = 0; k < n; k++) {
                for (long long int l = 0; l < n; l++) {
                    if (k == l) continue;
                    if (x[k] - x[l] == p && y[k] - y[l] == q) {
                        group.push_back(k);
                    }
                }
            }
            ans = min(ans, n - (long long int)group.size());
        }
    }
    if (n == 1) ans = 1;
    fin(ans);
}
