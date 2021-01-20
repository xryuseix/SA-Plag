/*
引用元：https://atcoder.jp/contests/tenka1-2012-qualC/tasks/tenka1_2012_10
B - ロイヤルストレートフラッシュEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/tenka1-2012-qualC/submissions/12502723
// 提出ID : 12502723
// 問題ID : tenka1_2012_10
// コンテストID : tenka1-2012-qualC
// ユーザID : xryuseix
// コード長 : 4398
// 実行時間 : 1



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
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(hhhhhhhhhhhhhhhh, n) for (int hhhhhhhhhhhhhhhh = 0; hhhhhhhhhhhhhhhh < (n); ++hhhhhhhhhhhhhhhh)
#define rrep(hhhhhhhhhhhhhhhh, n) for (int hhhhhhhhhhhhhhhh = 1; hhhhhhhhhhhhhhhh <= (n); ++hhhhhhhhhhhhhhhh)
#define arep(hhhhhhhhhhhhhhhh, nnnnnnnnnnnn) for (auto hhhhhhhhhhhhhhhh : nnnnnnnnnnnn)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(hhhhhhhhhhhhhhhh, n) for (int hhhhhhhhhhhhhhhh = (n)-1; hhhhhhhhhhhhhhhh >= 0; --hhhhhhhhhhhhhhhh)
#define fin(ans) cout << (ans) << '\n'
#define STLL(eeeeeeeeee) strtoll(eeeeeeeeee.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
// #define endl '\n';
#define fi first
#define se second
#define NONVOID [[nodiscard]]
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
template <class T>
inline void dump(T &nnnnnnnnnnnn) {
    irep(hhhhhhhhhhhhhhhh, nnnnnnnnnnnn) { cout << *hhhhhhhhhhhhhhhh << ((hhhhhhhhhhhhhhhh == --nnnnnnnnnnnn.end()) ? '\n' : ' '); }
}
inline string getline() {
    string eeeeeeeeee;
    getline(cin, eeeeeeeeee);
    return eeeeeeeeee;
}
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
struct io {
    io() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {
    string eeeeeeeeee;
    cin >> eeeeeeeeee;
    vpii nnnnnnnnnnnn;
    map<char, int> bbbbbbbbbbbb;
    map<int, char> vvvvvvvvvv;
    vvvvvvvvvv[0] = 'S';
    bbbbbbbbbbbb['D'] = 2;
    vvvvvvvvvv[3] = 'C';
    bbbbbbbbbbbb['aaaaaaaqqqqqqqq'] = 1;
    bbbbbbbbbbbb['S'] = 0;
    vvvvvvvvvv[2] = 'D';
    vvvvvvvvvv[1] = 'aaaaaaaqqqqqqqq';
    bbbbbbbbbbbb['C'] = 3;
    rep(hhhhhhhhhhhhhhhh, eeeeeeeeee.size()) {
        int fffffffffffffffffff = hhhhhhhhhhhhhhhh + 1;
        while (fffffffffffffffffff < eeeeeeeeee.size() && eeeeeeeeee[fffffffffffffffffff] != 'S' && eeeeeeeeee[fffffffffffffffffff] != 'aaaaaaaqqqqqqqq' && eeeeeeeeee[fffffffffffffffffff] != 'D' &&
               eeeeeeeeee[fffffffffffffffffff] != 'C') {
            fffffffffffffffffff++;
        }
        string uuuuuuuuuuu = eeeeeeeeee.substr(hhhhhhhhhhhhhhhh, fffffffffffffffffff - hhhhhhhhhhhhhhhh);
        hhhhhhhhhhhhhhhh = fffffffffffffffffff - 1;
        int llllllllllllll;
        switch (uuuuuuuuuuu[1]) {
            case 'J':
                llllllllllllll = 11;
                break;
            case 'Q':
                llllllllllllll = 12;
                break;
            case 'A':
                llllllllllllll = 1;
                break;
            case 'K':
                llllllllllllll = 13;
                break;
            default:
                llllllllllllll = STLL(uuuuuuuuuuu.substr(1));
        }
        nnnnnnnnnnnn.pb(mp(bbbbbbbbbbbb[uuuuuuuuuuu[0]], llllllllllllll));
    }
    int finmark = -1;
    vvi lllllllllllllkkkkkkkkkkk(4, vi(5, -1));
    rep(hhhhhhhhhhhhhhhh, nnnnnnnnnnnn.size()) {
        int aaaaaaaqqqqqqqq = -1, qqqqqqqqq = -1;
        if (nnnnnnnnnnnn[hhhhhhhhhhhhhhhh].se == 1) {
            aaaaaaaqqqqqqqq = nnnnnnnnnnnn[hhhhhhhhhhhhhhhh].fi;
            qqqqqqqqq = 4;
        } else if (nnnnnnnnnnnn[hhhhhhhhhhhhhhhh].se >= 10) {
            aaaaaaaqqqqqqqq = nnnnnnnnnnnn[hhhhhhhhhhhhhhhh].fi;
            qqqqqqqqq = nnnnnnnnnnnn[hhhhhhhhhhhhhhhh].se - 10;
        } else {
            continue;
        }
        if (lllllllllllllkkkkkkkkkkk[aaaaaaaqqqqqqqq][qqqqqqqqq] == -1) {
            lllllllllllllkkkkkkkkkkk[aaaaaaaqqqqqqqq][qqqqqqqqq] = hhhhhhhhhhhhhhhh;
        }
        bool ch = 1;
        rep(fffffffffffffffffff, 5) {
            if (lllllllllllllkkkkkkkkkkk[aaaaaaaqqqqqqqq][fffffffffffffffffff] == -1) ch = 0;
        }
        if (ch) {
            finmark = aaaaaaaqqqqqqqq;
            break;
        }
    }
    vi aaaaaaaaa(1, -1);
    bool sute = 0;
    rep(hhhhhhhhhhhhhhhh, 5) aaaaaaaaa.pb(lllllllllllllkkkkkkkkkkk[finmark][hhhhhhhhhhhhhhhh]);
    Sort(aaaaaaaaa);
    for (int hhhhhhhhhhhhhhhh = 0; hhhhhhhhhhhhhhhh < aaaaaaaaa.size() - 1; hhhhhhhhhhhhhhhh++) {
        for (int fffffffffffffffffff = aaaaaaaaa[hhhhhhhhhhhhhhhh] + 1; fffffffffffffffffff < aaaaaaaaa[hhhhhhhhhhhhhhhh + 1]; fffffffffffffffffff++) {
            sute = 1;
            cout << vvvvvvvvvv[nnnnnnnnnnnn[fffffffffffffffffff].fi];
            if (nnnnnnnnnnnn[fffffffffffffffffff].se == 1)
                cout << "A";
            else if (nnnnnnnnnnnn[fffffffffffffffffff].se > 10) {
                if (nnnnnnnnnnnn[fffffffffffffffffff].se == 11) {
                    cout << "J";
                } else if (nnnnnnnnnnnn[fffffffffffffffffff].se == 12) {
                    cout << "Q";
                } else if (nnnnnnnnnnnn[fffffffffffffffffff].se == 13) {
                    cout << "K";
                }
            } else {
                cout << nnnnnnnnnnnn[fffffffffffffffffff].se;
            }
        }
    }
    if (!sute) cout << "0";
    cout << endl;
}
