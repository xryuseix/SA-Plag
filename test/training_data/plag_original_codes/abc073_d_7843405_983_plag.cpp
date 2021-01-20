/*
引用元：https://atcoder.jp/contests/abc073/tasks/abc073_d
D - joisino's travelEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc073/submissions/7843405
// 提出ID : 7843405
// 問題ID : abc073_d
// コンテストID : abc073
// ユーザID : xryuseix
// コード長 : 4157
// 実行時間 : 35

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

class WAR_FLY {
   public:
    vvi d;  //辺の数
    int V;  //頂点の数

    WAR_FLY(int n) {
        V = n;
        d = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i == j) {
                    d[i][j] = 0;
                } else {
                    d[i][j] = 1 << 30;
                }
            }
        }
    }

    void warshall_floyd() {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    d[i][j] = min((ll)d[i][j], (ll)d[i][k] + (ll)d[k][j]);
                }
            }
        }
    }

    void add(int from, int to, int cost) { d[from][to] = cost; }
};

vector<vector<pair<int, int>>> v(8);
ll ans = 1 << 60;

void dfs(int pos, vector<bool> passed, int passnum, int n, ll cost) {
    passed[pos] = true;
    if (passnum == n) {
        ans = min(ans, cost);
    }
    for (int i = 0; i < v[pos].size(); i++) {
        if (!passed[v[pos][i].first])
            dfs(v[pos][i].first, passed, passnum + 1, n,
                cost + v[pos][i].second);
    }
}

int main(void) {
    int n, m, R;
    cin >> n >> m >> R;
    vi r(R);
    rep(i, R) cin >> r[i];

    WAR_FLY wa1(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        a--;
        wa1.add(b, a, c);
        wa1.add(a, b, c);
    }
    wa1.warshall_floyd();

    WAR_FLY wa2(R);
    for (int i = 0; i < R - 1; i++) {
        for (int j = i + 1; j < R; j++) {
            wa2.add(i, j, wa1.d[r[i] - 1][r[j] - 1]);
            wa2.add(j, i, wa1.d[r[j] - 1][r[i] - 1]);
        }
    }
    wa2.warshall_floyd();

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < wa2.d[i].size(); j++) {
            v[i].push_back(mp(j, wa2.d[i][j]));
        }
    }

    for (int i = 0; i < R; i++) {
        vector<bool> passed(R, false);
        dfs(i, passed, 1, R, 0);
    }

    fin(ans);
}
