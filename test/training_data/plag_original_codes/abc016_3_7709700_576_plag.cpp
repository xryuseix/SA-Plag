/*
引用元：https://atcoder.jp/contests/abc016/tasks/abc016_3
C - 友達の友達Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc016/submissions/7709700
// 提出ID : 7709700
// 問題ID : abc016_3
// コンテストID : abc016
// ユーザID : xryuseix
// コード長 : 3133
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
                    d[i][j] = INF;
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

int main(void) {
    int n, q, a, b;
    cin >> n >> q;

    WAR_FLY wa(n);
    rep(i, q) {
        cin >> a >> b;
        wa.add(a - 1, b - 1, 1);
        wa.add(b - 1, a - 1, 1);
    }
    wa.warshall_floyd();
    rep(i, n) {
        int ans = 0;
        for (int j = 0; j < wa.d[i].size(); j++) {
            if (wa.d[i][j] == 2) ans++;
        }
        fin(ans);
    }
}
