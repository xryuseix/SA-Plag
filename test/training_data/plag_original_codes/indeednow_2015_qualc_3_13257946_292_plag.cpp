/*
引用元：https://atcoder.jp/contests/indeednow-qualb/tasks/indeednow_2015_qualc_3
C - 木Editorial
// ソースコードの引用元 :
https://atcoder.jp/contests/indeednow-qualb/submissions/13257946
// 提出ID : 13257946
// 問題ID : indeednow_2015_qualc_3
// コンテストID : indeednow-qualb
// ユーザID : xryuseix
// コード長 : 3015
// 実行時間 : 161



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
#define arep(i, v) for (auto i : v)
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

template <class T>
inline void dump(T &v) {
    irep(i, v) { cout << (*i) + 1 << ((i == --v.end()) ? '\n' : ' '); }
}
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr double EPS = 1e-9;

void solve() {
    set<int> s;
    int n;
    cin >> n;
    vvi v(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        v[a - 1].pb(b - 1);
        v[b - 1].pb(a - 1);
    }
    vi ans;
    ans.pb(0);
    set<int> rem;
    rem.insert(0);
    rep(i, v[0].size()) s.insert(v[0][i]);
    while (!s.empty()) {
        int A = *s.begin();
        s.erase(s.begin());
        rep(i, v[A].size()) {
            if (rem.count(v[A][i]) == 1) {
                continue;
            }
            s.insert(v[A][i]);
        }
        ans.pb(A);
        rem.insert(A);
    }
    dump(ans);
}

int main() { solve(); }
