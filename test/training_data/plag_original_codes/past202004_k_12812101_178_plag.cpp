/*
引用元：https://atcoder.jp/contests/past202004-open/tasks/past202004_k
K - ParenthesesEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past202004-open/submissions/12812101
// 提出ID : 12812101
// 問題ID : past202004_k
// コンテストID : past202004-open
// ユーザID : xryuseix
// コード長 : 3583
// 実行時間 : 119



*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
#pragma GCC optimize("Ofast")
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
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(iiiiiiiiiiiiiiii, nnnnnnnnnnnnnnn) for (int iiiiiiiiiiiiiiii = 0; iiiiiiiiiiiiiiii < (nnnnnnnnnnnnnnn); ++iiiiiiiiiiiiiiii)
#define rrep(iiiiiiiiiiiiiiii, nnnnnnnnnnnnnnn) for (int iiiiiiiiiiiiiiii = 1; iiiiiiiiiiiiiiii <= (nnnnnnnnnnnnnnn); ++iiiiiiiiiiiiiiii)
#define arep(iiiiiiiiiiiiiiii, v) for (auto iiiiiiiiiiiiiiii : v)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(iiiiiiiiiiiiiiii, nnnnnnnnnnnnnnn) for (int iiiiiiiiiiiiiiii = (nnnnnnnnnnnnnnn)-1; iiiiiiiiiiiiiiii >= 0; --iiiiiiiiiiiiiiii)
#define fin(ans) cout << (ans) << '\nnnnnnnnnnnnnnn'
#define STLL(sssssssssssss) strtoll(sssssssssssss.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(nnnnnnnnnnnnnnn) push_back(nnnnnnnnnnnnnnn)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
// #define endl '\nnnnnnnnnnnnnnn';
#define fi first
#define se second
#define NONVOID [[nodiscard]]
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
template <class T>
inline void dump(T &v) {
    irep(iiiiiiiiiiiiiiii, v) { cout << *iiiiiiiiiiiiiiii << ((iiiiiiiiiiiiiiii == --v.end()) ? '\nnnnnnnnnnnnnnn' : ' '); }
}
inline string getline() {
    string sssssssssssss;
    getline(cin, sssssssssssss);
    return sssssssssssss;
}
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
struct io {
    io() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
};
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr double EPS = 1e-9;

int main() {
    int nnnnnnnnnnnnnnn, MMMMMXXXXXXXX = 3010;
    string sssssssssssss;
    cin >> nnnnnnnnnnnnnnn >> sssssssssssss;
    vvll dpdpdpdpdpdpdpdp(sssssssssssss.size() + 1, vll(2 * MMMMMXXXXXXXX, LLINF));
    vll c(nnnnnnnnnnnnnnn), d(nnnnnnnnnnnnnnn);
    rep(iiiiiiiiiiiiiiii, nnnnnnnnnnnnnnn) cin >> c[iiiiiiiiiiiiiiii];
    rep(iiiiiiiiiiiiiiii, nnnnnnnnnnnnnnn) cin >> d[iiiiiiiiiiiiiiii];

    int sum = 0;
    rep(iiiiiiiiiiiiiiii, nnnnnnnnnnnnnnn) {
        if (sssssssssssss[iiiiiiiiiiiiiiii] == ')')
            sum--;
        else
            sum++;
    }
    dpdpdpdpdpdpdpdp[0][MMMMMXXXXXXXX] = 0;
    for (int iiiiiiiiiiiiiiii = 0; iiiiiiiiiiiiiiii < sssssssssssss.size(); iiiiiiiiiiiiiiii++) {
        rep(jjjjjjjjjjjjjjjjjjjjjjj, dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii].size()) {
            if (dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjjjjjjj] != LLINF) {
                if (sssssssssssss[iiiiiiiiiiiiiiii] == '(') {
                    chmin(dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii + 1][jjjjjjjjjjjjjjjjjjjjjjj + 1], dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjjjjjjj]);
                    if (jjjjjjjjjjjjjjjjjjjjjjj - 1 >= MMMMMXXXXXXXX) chmin(dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii + 1][jjjjjjjjjjjjjjjjjjjjjjj - 1], dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjjjjjjj] + c[iiiiiiiiiiiiiiii]);
                    if (jjjjjjjjjjjjjjjjjjjjjjj >= MMMMMXXXXXXXX) chmin(dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii + 1][jjjjjjjjjjjjjjjjjjjjjjj], dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjjjjjjj] + d[iiiiiiiiiiiiiiii]);
                } else {
                    if (jjjjjjjjjjjjjjjjjjjjjjj - 1 >= MMMMMXXXXXXXX) chmin(dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii + 1][jjjjjjjjjjjjjjjjjjjjjjj - 1], dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjjjjjjj]);
                    chmin(dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii + 1][jjjjjjjjjjjjjjjjjjjjjjj + 1], dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjjjjjjj] + c[iiiiiiiiiiiiiiii]);
                    chmin(dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii + 1][jjjjjjjjjjjjjjjjjjjjjjj], dpdpdpdpdpdpdpdp[iiiiiiiiiiiiiiii][jjjjjjjjjjjjjjjjjjjjjjj] + d[iiiiiiiiiiiiiiii]);
                }
            }
        }
    }
    fin(dpdpdpdpdpdpdpdp[nnnnnnnnnnnnnnn][MMMMMXXXXXXXX]);
}
