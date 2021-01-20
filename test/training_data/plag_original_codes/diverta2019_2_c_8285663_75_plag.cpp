/*
引用元：https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_c
C - Successive SubtractionEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/diverta2019-2/submissions/8285663
// 提出ID : 8285663
// 問題ID : diverta2019_2_c
// コンテストID : diverta2019-2
// ユーザID : xryuseix
// コード長 : 2878
// 実行時間 : 204



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

const int INF = INT_MAX;

int main(void) {
    int n;
    cin >> n;
    vi v(n);
    ll ans = 0;
    vector<pair<int, int>> log;
    bool isneg = 0, ispos = 0;
    rep(i, n) {
        cin >> v[i];
        if (v[i] >= 0)
            ispos = 1;
        else
            isneg = 1;
    }
    sort(v.begin(), v.end());

    if (ispos && isneg) {
        for (int i = v.size() - 2; i > 0; i--) {
            if (v[i] < 0) break;
            log.push_back(make_pair(v[0], v[i]));
            v[0] -= v[i];
            v[i] = INF;
        }
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] == INF)
                continue;
            else {
                log.push_back(make_pair(v[v.size() - 1], v[i]));
                v[v.size() - 1] -= v[i];
            }
        }
        ans = v[v.size() - 1];
    } else if (ispos) {
        for (int i = 1; i < v.size() - 1; i++) {
            log.push_back(make_pair(v[0], v[i]));
            v[0] -= v[i];
        }
        log.push_back(make_pair(v[v.size() - 1], v[0]));
        v[v.size() - 1] -= v[0];
        ans = v[v.size() - 1];
    } else if (isneg) {
        sort(v.rbegin(), v.rend());
        log.push_back(make_pair(v[0], v[1]));
        v[0] -= v[1];
        for (int i = 2; i < v.size(); i++) {
            log.push_back(make_pair(v[0], v[i]));
            v[0] -= v[i];
        }
        ans = v[0];
    }

    cout << ans << endl;
    for (int i = 0; i < log.size(); i++) {
        cout << log[i].first << " " << log[i].second << endl;
    }
}
