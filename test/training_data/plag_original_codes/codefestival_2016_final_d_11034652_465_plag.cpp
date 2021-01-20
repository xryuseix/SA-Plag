/*
引用元：https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_d
D - Pair CardsEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cf16-final/submissions/11034652
// 提出ID : 11034652
// 問題ID : codefestival_2016_final_d
// コンテストID : cf16-final
// ユーザID : xryuseix
// コード長 : 3075
// 実行時間 : 42



*/
#include <algorithm>
#include <bitset>
#include <cassert>
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
#define itn int;
#define endl '\n';
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

ll ans = 0;
int n, m;
set<int> s;
int main() {
    cin >> n >> m;
    vi v(n);
    vvi w(m);
    rep(i, n) cin >> v[i];
    rep(i, n) w[v[i] % m].pb(v[i]);
    for (int i = 1; i < ceil(m / 2.0); i++) {
        s.clear();
        int b = m - i;
        int a = i;
        if (w[i].size() > w[m - i].size()) {
            swap(a, b);
        }
        int minNum = w[a].size(), match = 0;
        int t;
        rep(j, w[b].size()) {
            t = w[b][j];
            if (s.count(t) != 1) {
                s.insert(t);
            } else {
                ++match;
                s.erase(s.find(t));
            }
        }
        ans += minNum + min(match * 2, (int)w[b].size() - (int)w[a].size()) / 2;
    }

    int match = w[0].size() / 2;
    if (!(m % 2)) {
        match += w[m / 2].size() / 2;
    }
    ans += match;
    fin(ans);
}
