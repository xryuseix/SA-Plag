/*
引用元：https://atcoder.jp/contests/past201912-open/tasks/past201912_f
F - DoubleCamelCase SortEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/past201912-open/submissions/11739894
// 提出ID : 11739894
// 問題ID : past201912_f
// コンテストID : past201912-open
// ユーザID : xryuseix
// コード長 : 2844
// 実行時間 : 37



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
#define pb(n) push_back(n)
#define Sort(a) sort(a.begin(), a.end())
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {
    vector<pair<string, string>> v;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[j] >= 'A' && s[j] <= 'Z') {
                string t = s.substr(i, j - i + 1);
                v.pb(make_pair(t, t));
                i += j - i;
                break;
            }
        }
    }
    rep(i, v.size()) {
        rep(j, v[i].first.size()) {
            if ('A' <= v[i].first[j] && v[i].first[j] <= 'Z') {
                v[i].first[j] += 'a' - 'A';
            }
        }
    }
    Sort(v);
    rep(i, v.size()) cout << v[i].second;
    cout << endl;
}
