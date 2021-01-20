/*
引用元：https://atcoder.jp/contests/abc063/tasks/arc075_b
D - WidespreadEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc063/submissions/7437107
// 提出ID : 7437107
// 問題ID : arc075_b
// コンテストID : abc063
// ユーザID : xryuseix
// コード長 : 2399
// 実行時間 : 22



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

bool enough(vll &h, ll x, ll a, ll b) {
    ll use = 0;
    rep(i, h.size()) {
        use +=
            (h[i] - (ll)x * b) ? ceil((double)(h[i] - (ll)x * b) / (a - b)) : 0;
    }
    return use > x;
}

ll n, a, b;
pair<ll, ll> range = {1, INF};
int main(void) {
    cin >> n >> a >> b;
    vll h(n);
    rep(i, n) cin >> h[i];

    while (range.first < range.second) {
        ll x = (range.first + range.second) / 2;
        if (enough(h, x, a, b)) {
            range.second = x;
        } else {
            range.first = x + 1;
        }
    }
    cout << range.first << endl;
}
