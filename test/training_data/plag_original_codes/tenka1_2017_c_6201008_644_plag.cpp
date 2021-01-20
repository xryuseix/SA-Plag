/*
引用元：https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_c
C - 4/NEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/tenka1-2017/submissions/6201008
// 提出ID : 6201008
// 問題ID : tenka1_2017_c
// コンテストID : tenka1-2017
// ユーザID : xryuseix
// コード長 : 1697
// 実行時間 : 5



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
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define P 1000000007
#define STI(s) atoi(s.c_str())  // string to int
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define Sort(a) sort(a.begin(), a.end())

int main(void) {
    ll N;
    cin >> N;
    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            ll d = (4 * h * n - N * n - N * h);
            if (d <= 0) continue;
            if (N * h * n % d == 0) {
                cout << h << " " << n << " " << N * h * n / d << endl;
                return 0;
            }
        }
    }
}
