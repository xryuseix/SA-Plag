/*
引用元：https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_c
C - Palindromic MatrixEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-festival-2017-quala/submissions/8234683
// 提出ID : 8234683
// 問題ID : code_festival_2017_quala_c
// コンテストID : code-festival-2017-quala
// ユーザID : xryuseix
// コード長 : 3313
// 実行時間 : 2



*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
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
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
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
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

int main(void) {

  int h, w;
  cin >> h >> w;
  int alpha[26] = {0};
  rep(i, h) rep(j, w) {
    char c;
    cin >> c;
    alpha[c - 'a']++;
  }
  bool ch = true;
  if (h == 1 && w == 1) {
    fin("Yes");
    return 0;
  } else if (h == 1 || w == 1) {
    int odd = 0;
    for (int i = 0; i < 26; i++) {
      if (alpha[i] % 2 == 1)
        odd++;
    }
    if (max(h, w) % 2 == 0 && odd == 0) {
      ch = true;
    } else if (max(h, w) % 2 == 1 && odd == 1) {
      ch = true;
    } else {
      ch = false;
    }
  } else if (h % 2 == 0 && w % 2 == 0) {
    for (int i = 0; i < 26; i++) {
      if (alpha[i] % 4 != 0)
        ch = false;
    }
  } else if ((h % 2 == 1 || w % 2 == 1) && (h % 2 == 0 || w % 2 == 0)) {
    int four = 0;
    int odd = 0;
    int needfour = (h / 2) * (w / 2);
    for (int i = 0; i < 26; i++) {
      if (alpha[i] % 2 == 1) {
        odd++;
        alpha[i]--;
      }
      if (alpha[i] >= 4) {
        four += alpha[i] / 4;
      }
    }
    if (odd != 0)
      ch = false;
    if (needfour > four)
      ch = false;
    // for(int i=0;i<26;i++){
    //     cout<<char('a'+i)<<" "<<alpha[i]<<endl;
    // }
    // cout<<h/2<<" "<<w/2<<endl;
    // cout<<needfour<<" "<<four<<" "<<odd<<endl;
  } else {
    int needfour = ((h - 1) / 2) * ((w - 1) / 2);
    int odd = 0;
    int four = 0;
    for (int i = 0; i < 26; i++) {
      if (alpha[i] % 2 == 1) {
        odd++;
        alpha[i]--;
      }
      if (alpha[i] >= 4) {
        four += alpha[i] / 4;
      }
    }
    // cout<<needfour<<" "<<four<<" "<<odd<<endl;
    if (needfour > four)
      ch = false;
    if (odd != 1)
      ch = false;
  }
  if (ch)
    fin("Yes");
  else
    fin("No");
}
