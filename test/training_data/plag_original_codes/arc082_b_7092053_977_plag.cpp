/*
引用元：https://atcoder.jp/contests/abc072/tasks/arc082_b
D - DerangementEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc072/submissions/7092053
// 提出ID : 7092053
// 問題ID : arc082_b
// コンテストID : abc072
// ユーザID : xryuseix
// コード長 : 1883
// 実行時間 : 9



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
    int n;
    cin >> n;
    vi v(n);
    rep(i, n) cin >> v[i];
    int num;
    ll ans = 0;
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        if (v[i] != i + 1)
            s[i] = 'o';
        else
            s[i] = 'x';
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != 'x') continue;
        s[i] = 'o';
        if (i < n - 1) s[i + 1] = 'o';
        ans++;
    }
    fin(ans);
}
