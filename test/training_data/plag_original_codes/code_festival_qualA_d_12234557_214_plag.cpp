/*
引用元：https://atcoder.jp/contests/code-festival-2014-quala/tasks/code_festival_qualA_d
D - 壊れた電卓Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-festival-2014-quala/submissions/12234557
// 提出ID : 12234557
// 問題ID : code_festival_qualA_d
// コンテストID : code-festival-2014-quala
// ユーザID : xryuseix
// コード長 : 3185
// 実行時間 : 13



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
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int stringcount(string s, char c) { return count(s.cbegin(), s.cend(), c); }

int main() {
    string a;
    ll K, na;
    cin >> a >> K;
    na = STLL(a);
    ll ans = 1 << 60;
    int set;
    rep(i, 15) {
        rep(j, 10) {
            rep(k, 10) {
                rep(l, 15) {
                    string s = a.substr(0, i);
                    s += (j + '0');
                    rep(m, l) s += (k + '0');
                    if (s.size() > 16) continue;
                    set = 0;
                    rep(m, 10) set += (bool)stringcount(s, '0' + m);
                    if (set > K) continue;
                    chmin(ans, abs(na - STLL(s)));
                }
            }
        }
    }
    fin(ans);
}
