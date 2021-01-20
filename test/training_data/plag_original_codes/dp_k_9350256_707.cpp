/*
引用元：https://atcoder.jp/contests/dp/tasks/dp_m
// ソースコードの引用元 : https://atcoder.jp/contests/dp/submissions/9350256
K - Stones
Time Limit : 2 sec / Memory Limit : 1024 MB
配点 : 100 点
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
typedef vector<pair<int, int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
struct io {
    io() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
};
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {
    int n, k;
    cin >> n >> k;
    vi v(n);
    rep(i, n) { cin >> v[i]; }
    Sort(v);
    int dp[101010];

    // 残りの石がi個の時，勝利状態かチェックする
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {  //これは取れる石のかずループ
            if (i - v[j] >= 0) {
                /*
                    石を取った時，勝利状態ならとる．
                    この時の，dp[i - v[j]]はfalseである(相手が敗北条件なので)
                    だから，falseを反転させる．

                    石を取った時，敗北条件なら保留する．
                    この時の，dp[i - v[j]]はtrueである(相手が勝利条件なので)
                    これを反転させると，falseであり，falseはorをとっても影響を与えない(保留)
                */
                dp[i] |= !dp[i - v[j]];
            }
        }
    }
    if (dp[k])
        fin("First");
    else
        fin("Second");
}
