/*
引用元：https://atcoder.jp/contests/abc094/tasks/arc095_a
C - Many MediansEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc094/submissions/5868204
// 提出ID : 5868204
// 問題ID : arc095_a
// コンテストID : abc094
// ユーザID : xryuseix
// コード長 : 1679
// 実行時間 : 463



*/
#include <algorithm>
#include <bitset>
#include <cctype>
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
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(j, n) for (j = 0; j < n; j++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define P 1000000007
#define STI(s) atoi(s.c_str())  // string to int
using namespace std;
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
const long long LLINF = 1LL << 60;

int main(void) {
    int j, n;
    cin >> n;
    vector<int> v(n), w(n);
    rep(j, n) {
        cin >> v[j];
        w[j] = v[j];
    }
    int cen = n / 2;
    sort(w.begin(), w.end());
    map<int, int> m;
    rep(j, n) {
        if (w[j] < w[cen] || w[j] > w[cen]) {
            m[w[j]] = w[cen];
        }
        if (w[j] >= w[cen] && w[j - 1] < w[cen]) {
            cen--;
            m[w[j]] = w[cen];
        }
    }
    rep(j, n) cout << m[v[j]] << endl;
}
