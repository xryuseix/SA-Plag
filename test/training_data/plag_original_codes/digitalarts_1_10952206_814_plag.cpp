/*
引用元：https://atcoder.jp/contests/digitalarts2012/tasks/digitalarts_1
A - C-FilterEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/digitalarts2012/submissions/10952206
// 提出ID : 10952206
// 問題ID : digitalarts_1
// コンテストID : digitalarts2012
// ユーザID : xryuseix
// コード長 : 2919
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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define pb(n) push_back(n)

bool ch(string &t, string &v) {
    if (t.size() != v.size()) return false;
    bool res = 1;
    rep(i, t.size()) {
        if (t[i] == v[i])
            continue;
        else {
            if (t[i] == '*')
                continue;
            else
                res = 0;
        }
    }
    return res;
}
bool Number(string s) {
    bool res = 1;
    rep(i, s.size()) {
        if (s[i] < '0' || s[i] > '9') res = 0;
    }
    return res;
}


int main() {
    vs v;
    int n;
    while (1) {
        string s;
        cin >> s;
        if (Number(s)) {
            n = STLL(s);
            break;
        } else {
            v.pb(s);
        }
    }
    vs t(n);
    rep(i, n) cin >> t[i];
    vb b(v.size(), false);
    rep(i, n) {
        rep(j, v.size()) {
            if (b[j]) continue;
            b[j] = ch(t[i], v[j]);
        }
    }
    rep(i, v.size()) {
        if (!b[i]) {
            cout << v[i];
            if (i != v.size() - 1) cout << ' ';
        } else {
            rep(j, v[i].size()) cout << '*';
            if (i != v.size() - 1) cout << ' ';
        }
    }
    cout << endl;
}
