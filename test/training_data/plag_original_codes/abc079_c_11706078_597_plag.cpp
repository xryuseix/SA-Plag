/*
引用元：https://atcoder.jp/contests/abc079/tasks/abc079_c
C - Train TicketEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/abc079/submissions/11706078
// 提出ID : 11706078
// 問題ID : abc079_c
// コンテストID : abc079
// ユーザID : xryuseix
// コード長 : 2906
// 実行時間 : 1



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
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
#define endl '\n';
#define fi first
#define se second
#define NONVOID [[nodiscard]]
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
inline string getline() {
    string s;
    getline(cin, s);
    return s;
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
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {
    int a, b, c, d;
    string s;
    cin >> s;
    b = s[1] - '0';
    d = s[3] - '0';
    c = s[2] - '0';
    a = s[0] - '0';
    if (a + b + c + d == 7)
        cout << a << "+" << b << "+" << c << "+" << d << "=7" << '\n';
    else if (a - b - c + d == 7)
        cout << a << "-" << b << "-" << c << "+" << d << "=7" << '\n';
    else if (a + b + c - d == 7)
        cout << a << "+" << b << "+" << c << "-" << d << "=7" << '\n';
    else if (a + b - c - d == 7)
        cout << a << "+" << b << "-" << c << "-" << d << "=7" << '\n';
    else if (a - b + c + d == 7)
        cout << a << "-" << b << "+" << c << "+" << d << "=7" << '\n';
    else if (a - b - c - d == 7)
        cout << a << "-" << b << "-" << c << "-" << d << "=7" << '\n';
    else if (a - b + c - d == 7)
        cout << a << "-" << b << "+" << c << "-" << d << "=7" << '\n';
    else if (a + b - c + d == 7)
        cout << a << "+" << b << "-" << c << "+" << d << "=7" << '\n';
}
