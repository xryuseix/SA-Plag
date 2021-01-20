/*
引用元：https://atcoder.jp/contests/abc081/tasks/arc086_a
C - Not so DiverseEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc081/submissions/5795849
// 提出ID : 5795849
// 問題ID : arc086_a
// コンテストID : abc081
// ユーザID : xryuseix
// コード長 : 1766
// 実行時間 : 129



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
#define rep(i, n) for (i = 0; i < n; i++)
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
using namespace std;

set<int> s;
vector<pair<int, int>> v, x;
int main(void) {
    int n, k, i, j = 0;
    cin >> n >> k;
    vector<int> w(n, 0);
    rep(i, n) cin >> w[i];
    sort(w.begin(), w.end());
    rep(i, n) {
        int t = w[i];
        if (s.find(t) != s.end()) {
            v[v.size() - 1].second++;
        } else {
            v.push_back(make_pair(t, 1));
            s.insert(t);
        }
    }
    rep(i, v.size()) { x.push_back(make_pair(v[i].second, v[i].first)); }
    sort(x.begin(), x.end());
    ll ans = 0;
    rep(i, max((int)x.size() - k, 0)) { ans += x[i].first; }
    fin(ans);
}
