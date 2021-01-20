/*
引用元：https://atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_c
C - Inserting 'x'Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-festival-2017-qualc/submissions/7977030
// 提出ID : 7977030
// 問題ID : code_festival_2017_qualc_c
// コンテストID : code-festival-2017-qualc
// ユーザID : xryuseix
// コード長 : 2107
// 実行時間 : 5



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

const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {
    string s;
    cin >> s;
    bool ch = true;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) ch = false;
    }
    if (ch) {
        cout << 0 << endl;
        return 0;
    }
    int r = 0, l = s.size() - 1;
    int ans = 0;
    ch = true;
    while (r < l) {
        if (s[r] == s[l]) {
            r++;
            l--;
        } else if (s[r] == 'x') {
            r++;
            ans++;
        } else if (s[l] == 'x') {
            l--;
            ans++;
        } else {
            ch = false;
            break;
        }
    }
    if (!ch) {
        fin(-1);
    } else {
        fin(ans);
    }
}
