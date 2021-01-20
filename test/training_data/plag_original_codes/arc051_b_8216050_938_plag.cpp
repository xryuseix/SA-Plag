/*
引用元：https://atcoder.jp/contests/arc051/tasks/arc051_b
B - 互除法Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc051/submissions/8216050
// 提出ID : 8216050
// 問題ID : arc051_b
// コンテストID : arc051
// ユーザID : xryuseix
// コード長 : 1728
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
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define STI(s) atoi(s.c_str())
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int main(void) {
    vll fib(50);
    fib[0] = 0;
    fib[1] = fib[0] + 1;
    fib[2] = fib[0] + 1;
    for (int i = 3; i < 45; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int k;
    cin >> k;
    cout << fib[k] << " " << fib[k + 1] << endl;
}
