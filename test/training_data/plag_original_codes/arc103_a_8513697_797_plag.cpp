/*
引用元：https://atcoder.jp/contests/abc111/tasks/arc103_a
C - /\/\/\/Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc111/submissions/8513697
// 提出ID : 8513697
// 問題ID : arc103_a
// コンテストID : abc111
// ユーザID : xryuseix
// コード長 : 3546
// 実行時間 : 67



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
#define itn int
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
struct io {
    io() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    };
};
const ll MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

vpii seqa, seqb;
int n;
map<int, int> m, o;
int ans = INF;
int tans = 0;
int a, b;

int main(void) {
    cin >> n;

    vi v(n);
    rep(i, n) cin >> v[i];
    for (int i = 0; i < n; i++) {
        if (!(i % 2))
            m[v[i]]++;
        else
            o[v[i]]++;
    }

    for (auto it = o.begin(); it != o.end(); it++) {
        seqb.push_back(mp(it->second, it->first));
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        seqa.push_back(mp(it->second, it->first));
    }
    Sort(seqb);
    Sort(seqa);
    int b = seqb[seqb.size() - 1].second;
    int a = seqa[seqa.size() - 1].second;
    if (a != b) {
        for (int i = 0; i < n; i++) {
            if (!(i % 2) && v[i] != a) {
                tans++;
            } else if (i % 2 && v[i] != b) {
                tans++;
            }
        }
        ans = min(ans, tans);
    } else {
        for (auto it = m.begin(); it != m.end(); it++) {
            seqa.push_back(mp(it->second, it->first));
        }
        for (auto it = o.begin(); it != o.end(); it++) {
            seqb.push_back(mp(it->second, it->first));
        }
        Sort(seqb);
        Sort(seqa);
        {
            a = seqa[seqa.size() - 1].second;
            if (seqb.size() <= 1)
                b = INF;
            else
                b = seqb[seqb.size() - 2].second;
            rep(i, n) {
                if (!(i % 2) && v[i] != a) {
                    tans++;
                } else if (i % 2 && v[i] != b) {
                    tans++;
                }
            }
        }
        ans = min(ans, tans);
        {
            if (seqa.size() <= 1)
                a = -(INF - 10);
            else
                a = seqa[seqa.size() - 2].second;
            int b = seqb[seqb.size() - 1].second;
            rep(i, n) {
                if (!i % 2 && v[i] != a) {
                    tans++;
                } else if (i % 2 && v[i] != b) {
                    tans++;
                }
            }
        }
        ans = min(ans, tans);
    }

    fin(ans);
}
