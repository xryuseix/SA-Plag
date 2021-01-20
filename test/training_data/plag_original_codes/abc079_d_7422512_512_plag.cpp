/*
引用元：https://atcoder.jp/contests/abc079/tasks/abc079_d
D - WallEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc079/submissions/7422512
// 提出ID : 7422512
// 問題ID : abc079_d
// コンテストID : abc079
// ユーザID : xryuseix
// コード長 : 3075
// 実行時間 : 4



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
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
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
    int h, w;
    cin >> h >> w;

    vvi c(10, vi(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];

    WAR_FLY wa(10);
    rep(i, 10) rep(j, 10) wa.add(i, j, c[i][j]);
    wa.warshall_floyd();

    ll ans = 0;
    int d;
    rep(i, h) rep(j, w) {
        cin >> d;
        if (!(d == 1 || d == -1)) {
            ans += wa.d[d][1];
        }
    }
    fin(ans);

    //////////////////////////////////////////////////////
    return 0;
}
