/*
引用元：https://atcoder.jp/contests/abc018/tasks/abc018_3
C - 菱型カウントEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc018/submissions/8330584
// 提出ID : 8330584
// 問題ID : abc018_3
// コンテストID : abc018
// ユーザID : xryuseix
// コード長 : 3094
// 実行時間 : 16



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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int r, c, k;
string s;
int ans = 0;

struct Corr {
    int x;
    int y;
    int depth;
};

queue<Corr> q;
Corr co;
void bfs(vvc &v, int k, int r, int c) {
    while (!q.empty()) {
        Corr now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (now.x + dx[i] >= 0 && now.y + dy[i] >= 0 && now.x + dx[i] < c &&
                now.y + dy[i] < r && v[now.y + dy[i]][now.x + dx[i]] == 'o' &&
                now.depth < k - 1) {
                co = {now.x + dx[i], now.y + dy[i], now.depth + 1};
                v[now.y + dy[i]][now.x + dx[i]] = 'x';
                q.push(co);
            }
        }
    }
    return;
}

int main(void) {
    cin >> r >> c >> k;
    vvc v(r, vc(c));
    rep(i, r) {
        cin >> s;
        rep(j, c) {
            v[i][j] = s[j];
            if (v[i][j] == 'x') {
                co = {j, i, 0};
                q.push(co);
            }
        }
    }

    bfs(v, k, r, c);
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < r; j++) {
            v[j][i] = 'x';
        }
    }
    for (int i = c - 1; i >= c - k + 1; i--) {
        for (int j = 0; j < r; j++) {
            v[j][i] = 'x';
        }
    }
    for (int i = r - 1; i >= r - k + 1; i--) {
        for (int j = 0; j < c; j++) {
            v[i][j] = 'x';
        }
    }
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < c; j++) {
            v[i][j] = 'x';
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == 'o') ans++;
        }
    }
    fin(ans);
}
