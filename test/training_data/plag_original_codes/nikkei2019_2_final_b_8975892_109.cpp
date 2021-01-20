/*
引用元：https://atcoder.jp/contests/nikkei2019-2-final/tasks/nikkei2019_2_final_b
B - NIKKEI StringEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/nikkei2019-2-final/submissions/8975892
// 提出ID : 8975892
// 問題ID : nikkei2019_2_final_b
// コンテストID : nikkei2019-2-final
// ユーザID : xryuseix
// コード長 : 2525
// 実行時間 : 676



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
#define itn int
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
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

// set<pair<pair<int,int>,pair<int,int> > > memo;

int main(void) {

  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  for (int i = 2; i < n - 3; i++) { //中央
    int cl = i, cr = i + 1;
    string cls, crs;
    while (cl >= 2 && cr < n - 2) {
      // cls=s.substr(cl,i-cl+1);
      // crs=s.substr(i+1,cr-(i+1)+1);
      if (s.substr(cl, i - cl + 1) == s.substr(i + 1, cr - (i + 1) + 1)) {
        int bl = cl - 1, br = n - 1;
        while (bl >= 1 && br > cr + 1) {
          string bls, brs;
          // bls=s.substr(bl,cl-bl);
          // brs=s.substr(br,n-br);
          if (s.substr(bl, cl - bl) == s.substr(br, n - br)) {
            ans++;
            // memo.insert(mp(mp(bl,br),mp(cl,cr)));
          }
          bl--;
          br--;
        }
      }
      cl--;
      cr++;
    }
  }
  fin(ans);
  // fin((int)memo.size());
}
