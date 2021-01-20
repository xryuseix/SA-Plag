/*
引用元：https://atcoder.jp/contests/abc071/tasks/arc081_b
D - Coloring DominoesEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc071/submissions/7680519
// 提出ID : 7680519
// 問題ID : arc081_b
// コンテストID : abc071
// ユーザID : xryuseix
// コード長 : 2399
// 実行時間 : 1



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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {
    int n;
    cin >> n;
    string s, t, u = "";
    cin >> s >> t;
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i != s.size() - 1 && s[i] == s[i + 1]) {
            u += 'Y';
            i++;
        } else {
            u += 'X';
        }
    }

    int diff = false;

    if (u[0] == 'X')
        ans = 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 1 * 3;
    else {
        ans = 6;
    }

    for (int i = 1; i < u.size(); i++) {
        if (u[i] == 'X') {
            if (u[i - 1] == 'X') {
                ans = ans * 2 % P;
            }
        } else {  // Y
            if (u[i - 1] == 'X') {
                ans = ans * 2 % P;
            } else {  // Y
                ans = ans * 3 % P;
            }
        }
    }

    fin(ans);
}
