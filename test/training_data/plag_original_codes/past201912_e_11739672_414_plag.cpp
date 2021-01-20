/*
引用元：https://atcoder.jp/contests/past201912-open/tasks/past201912_e
E - RestoreEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past201912-open/submissions/11739672
// 提出ID : 11739672
// 問題ID : past201912_e
// コンテストID : past201912-open
// ユーザID : xryuseix
// コード長 : 3081
// 実行時間 : 2



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

const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {
    int n;
    cin >> n;
    vvc v(n, vc(n, 'N'));

    int Q, a, b;
    cin >> Q;
    rep(_, Q) {
        int q;
        cin >> q;
        if (q == 1) {
            cin >> a >> b;
            v[a - 1][b - 1] = 'Y';
        } else if (q == 2) {
            cin >> a;
            rep(j, n) {
                v[a - 1][j] = (v[j][a - 1] == 'Y') ? 'Y' : v[a - 1][j];
            }
        } else {
            cin >> a;
            vc w = v[a - 1];
            rep(k, n) {
                if (w[k] == 'Y') {
                    rep(j, n) {
                        if (!(j - (a - 1))) continue;
                        if (v[k][j] == 'Y') v[a - 1][j] = 'Y';
                    }
                }
            }
        }
    }
    rep(i, n) {
        rep(j, n) cout << v[i][j];
        cout << endl;
    }
}
