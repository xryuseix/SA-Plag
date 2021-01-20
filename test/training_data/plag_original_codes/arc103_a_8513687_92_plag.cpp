/*
引用元：https://atcoder.jp/contests/arc103/tasks/arc103_a
C - /\/\/\/Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc103/submissions/8513687
// 提出ID : 8513687
// 問題ID : arc103_a
// コンテストID : arc103
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

#define RANK 20
void hakidashi(double a[][RANK+1], int n) { 
  double piv, t;
  int i, j, k;
  for (k = 0; k < n; k++) {
    piv = a[k][k];
    for (j = k; j < n + 1; j++) {
      a[k][j] = a[k][j]/piv;
    }
    for (i = 0; i < n; i++) {
      if (i != k) {
        t = a[i][k];
        for (j = k; j < n+1; j++) {
          a[i][j] = a[i][j] - t*a[k][j];
        }
      }
    }
  }
}

int main(void) {
    int n;
    cin >> n;

    vi v(n);
    rep(i, n) cin >> v[i];
    map<int, int> m, o;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            m[v[i]]++;
        else
            o[v[i]]++;
    }

    int ans = INF;

    int tans = 0;
    vpii seqa, seqb;
    for (auto it = m.begin(); it != m.end(); it++) {
        seqa.push_back(mp(it->second, it->first));
    }
    for (auto it = o.begin(); it != o.end(); it++) {
        seqb.push_back(mp(it->second, it->first));
    }
    Sort(seqa);
    Sort(seqb);
    int a = seqa[seqa.size() - 1].second;
    int b = seqb[seqb.size() - 1].second;
    if (a != b) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && v[i] != a) {
                tans++;
            } else if (i % 2 == 1 && v[i] != b) {
                tans++;
            }
        }
        ans = min(ans, tans);
    } else {
        int tans = 0;
        vpii seqa, seqb;
        for (auto it = m.begin(); it != m.end(); it++) {
            seqa.push_back(mp(it->second, it->first));
        }
        for (auto it = o.begin(); it != o.end(); it++) {
            seqb.push_back(mp(it->second, it->first));
        }
        Sort(seqa);
        Sort(seqb);
        {
            int a = seqa[seqa.size() - 1].second;
            int b;
            if (seqb.size() <= 1)
                b = INF;
            else
                b = seqb[seqb.size() - 2].second;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0 && v[i] != a) {
                    tans++;
                } else if (i % 2 == 1 && v[i] != b) {
                    tans++;
                }
            }
        }
        ans = min(ans, tans);
        tans = 0;
        {
            int a;
            if (seqa.size() <= 1)
                a = -(INF - 10);
            else
                a = seqa[seqa.size() - 2].second;
            int b = seqb[seqb.size() - 1].second;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0 && v[i] != a) {
                    tans++;
                } else if (i % 2 == 1 && v[i] != b) {
                    tans++;
                }
            }
        }
        ans = min(ans, tans);
    }

    fin(ans);
}
