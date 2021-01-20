/*
引用元：https://atcoder.jp/contests/abc058/tasks/arc071_a
C - Dubious DocumentEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/abc058/submissions/10994548
// 提出ID : 10994548
// 問題ID : arc071_a
// コンテストID : abc058
// ユーザID : xryuseix
// コード長 : 2633
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
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
#define endl '\n';
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
  }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

int main() {

  map<char, int> ans, tmp;
  int n;
  cin >> n;
  rep(i, n) {
    tmp.clear();
    map<char, int> m;
    string s;
    cin >> s;
    rep(i, s.size()) m[s[i]]++;
    if (!i)
      ans = m;
    else {
      irep(j, m) {
        if (ans.find(j->first) == ans.end()) {
          continue;
        } else {
          tmp[j->first] = min(m[j->first], ans[j->first]);
        }
      }
      ans = tmp;
    }
    // irep(j,ans){
    //     char c=j->first;
    //     int num=j->second;
    //     rep(j,num)cout<<c;
    // }
    // cout<<"\n\n";
  }
  irep(i, ans) {
    char c = i->first;
    int num = i->second;
    rep(j, num) cout << c;
  }
  cout << endl;
}
