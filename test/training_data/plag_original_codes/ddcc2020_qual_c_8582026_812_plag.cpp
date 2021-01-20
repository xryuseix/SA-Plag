/*
引用元：https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_c
C - Strawberry CakesEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/ddcc2020-qual/submissions/8582026
// 提出ID : 8582026
// 問題ID : ddcc2020_qual_c
// コンテストID : ddcc2020-qual
// ユーザID : xryuseix
// コード長 : 2947
// 実行時間 : 14



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
#include <unordered_set>
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
const ll MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int h, w, k;
void solve(int &num, vvi &ans, vvc &v) {
    rep(i, w) {
        rep(j, h) {
            if (v[j][i] != '#') continue;
            ++num;
            int pos = j - 1;
            while (pos >= 0) {
                if (!ans[pos][i] && v[pos][i] != '#') {
                    ans[pos--][i] = num;
                    pos--;
                } else {
                    break;
                }
            }
            ans[j][i] = num;
            pos = 1 + j;
            while (pos < h) {
                if (!ans[pos][i] && v[pos][i] != '#') {
                    ans[pos++][i] = num;
                } else {
                    break;
                }
            }
        }
    }
}

int main(void) {
    cin >> h >> w >> k;
    string s;
    vvi ans(h, vi(w, 0));
    vvc v(h, vc(w));
    rep(i, h) {
        cin >> s;
        rep(j, w) { v[i][j] = s[j]; }
    }
    int num = 0;
    solve(num, ans, v);
    rep(i, h) {
        for (int j = w - 1; j >= 0; j--) {
            if (!ans[i][j]) {
                ans[i][j] = ans[i][j + 1];
            }
        }
    }
    rep(i, h) {
        for (int j = 1; j < w; j++) {
            if (!ans[i][j]) {
                ans[i][j] = ans[i][j - 1];
            }
        }
    }
    rep(i, h) {
        rep(j, w) {
            if (!j)
                cout << ans[i][j];
            else
                cout << " " << ans[i][j];
        }
        cout << endl;
    }
}
