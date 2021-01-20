/*
引用元：https://atcoder.jp/contests/arc066/tasks/arc066_a
C - Lining UpEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc066/submissions/7710160
// 提出ID : 7710160
// 問題ID : arc066_a
// コンテストID : arc066
// ユーザID : xryuseix
// コード長 : 2250
// 実行時間 : 37



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

const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int n;
map<int, int> m;
int main(void) {
    cin >> n;
    vi v(n);
    rep(i, n) cin >> v[i];
    rep(i, n) m[v[i]]++;
    bool ch = 1;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->first == 0 && it->second != 1)
            ch = 0;
        else {
            if (it->first != 0 && it->second != 2) {
                ch = 0;
            }
        }
    }
    if (!ch)
        fin(0);
    else {
        cout << mod_pow(2, n / 2, P) << endl;
    }
}
