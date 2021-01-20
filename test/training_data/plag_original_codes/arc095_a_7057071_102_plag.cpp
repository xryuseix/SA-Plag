/*
引用元：https://atcoder.jp/contests/arc095/tasks/arc095_a
C - Many MediansEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc095/submissions/7057071
// 提出ID : 7057071
// 問題ID : arc095_a
// コンテストID : arc095
// ユーザID : xryuseix
// コード長 : 1679
// 実行時間 : 462



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
#define rep(i, n) for (int i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
#define vi vector<int>
using namespace std;

map<int, int> m;
int main(void) {
    int n;
    cin >> n;
    vector<int> v(n), w(n);
    rep(i, n) {
        cin >> v[i];
        w[i] = v[i];
    }
    int cen = n / 2;
    sort(w.begin(), w.end());
    rep(i, n) {
        if (w[i] < w[cen] || w[i] > w[cen]) {
            m[w[i]] = w[cen];
        }
        if (w[i] >= w[cen] && w[i - 1] < w[cen]) {
            m[w[i]] = w[--cen];
        }
    }
    rep(i, n) cout << m[v[i]] << endl;
}
