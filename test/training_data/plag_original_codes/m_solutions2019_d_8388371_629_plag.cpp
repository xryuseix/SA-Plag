/*
引用元：https://atcoder.jp/contests/m-solutions2019/tasks/m_solutions2019_d
D - Maximum Sum of MinimumEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/m-solutions2019/submissions/8388371
// 提出ID : 8388371
// 問題ID : m_solutions2019_d
// コンテストID : m-solutions2019
// ユーザID : xryuseix
// コード長 : 2377
// 実行時間 : 12



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
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int num = 0;

void dfs(vi &score, vi &c, vvi &G, int pos) {
    score[pos] = c[num];
    rep(i, G[pos].size()) {
        if (score[G[pos][i]] == -10000) {
            num++;
            dfs(score, c, G, G[pos][i]);
        }
    }
    return;
}

int main(void) {
    int n;
    cin >> n;
    vvi G(n);
    vi l(n + 10000);
    vi r(n + 10000);
    vi c(n);
    vi score(n, -10000);
    rep(i, n - 1) {
        int b;
        int a;
        cin >> a;
        cin >> b;
        b--;
        a--;
        r[i] = b;
        l[i] = a;
        G[b].push_back(a);
        G[a].push_back(b);
    }
    rep(i, n) cin >> c[i];
    sort(c.rbegin(), c.rend());

    dfs(score, c, G, 0);
    ll ans = 0;
    rep(i, n - 1) { ans += min(score[l[i]], score[r[i]]); }
    fin(ans);
    rep(i, n) {
        if (!i)
            cout << score[i];
        else
            cout << " " << score[i];
    }
    cout << endl;
}
