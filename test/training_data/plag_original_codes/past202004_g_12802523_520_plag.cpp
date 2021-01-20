/*
引用元：https://atcoder.jp/contests/past202004-open/tasks/past202004_g
G - String QueryEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past202004-open/submissions/12802523
// 提出ID : 12802523
// 問題ID : past202004_g
// コンテストID : past202004-open
// ユーザID : xryuseix
// コード長 : 3294
// 実行時間 : 82



*/
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<pair<int, int>> vpii;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define fin(ans) cout << (ans) << '\n'
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define fi first
#define se second

int main() {
    map<char, ll> m;
    vpii v;
    int pos = 0;

    int n;
    cin >> n;
    rep(_, n) {
        int Q;
        cin >> Q;
        m.clear();
        if (Q == 1) {
            char c;
            int d;
            cin >> c >> d;
            v.pb(mp(c, d));
        } else {
            int d;
            cin >> d;
            for (int i = pos; i < v.size(); i++) {
                if (d < v[i].se) {
                    m[v[i].fi] += d;
                    v[i].se -= d;
                    d = 0;
                } else {
                    d -= v[i].se;
                    m[v[i].fi] += v[i].se;
                    v[i].se = 0;
                }
                if (!v[i].se) pos++;
                if (!d) break;
            }
            ll ans = 0;
            irep(i, m) { ans += pow(i->second, 2); }
            fin(ans);
        }
    }
}
