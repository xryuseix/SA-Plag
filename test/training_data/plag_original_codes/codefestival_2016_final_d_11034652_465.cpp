/*
引用元：https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_d
D - Pair CardsEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cf16-final/submissions/11034652
// 提出ID : 11034652
// 問題ID : codefestival_2016_final_d
// コンテストID : cf16-final
// ユーザID : xryuseix
// コード長 : 3075
// 実行時間 : 42



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
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
inline string getline() {
  string s;
  getline(cin, s);
  return s;
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
  int n, m;
  cin >> n >> m;
  vi v(n);
  rep(i, n) cin >> v[i];
  vvi w(m);
  rep(i, n) w[v[i] % m].pb(v[i]);
  // rep(i,m){
  //     rep(j,w[i].size()){
  //         cout<<w[i][j]<<" ";
  //     }
  //     cout<<endl;
  // }
  ll ans = 0;
  for (int i = 1; i < ceil(m / 2.0); i++) {
    int a = i;
    int b = m - i;
    if (w[a].size() > w[b].size()) {
      swap(a, b);
    }
    int minNum = w[a].size();
    set<int> s;
    int match = 0;
    rep(j, w[b].size()) {
      int t = w[b][j];
      if (s.count(t) == 1) {
        match++;
        s.erase(s.find(t));
      } else
        s.insert(t);
    }
    ans += minNum + min(match * 2, (int)w[b].size() - (int)w[a].size()) / 2;
    // cout<<i<<" "<<minNum<<" "<<match<<" "<<(int)w[b].size()<<"
    // "<<(int)w[a].size()<<endl;
  }

  int match = 0;
  match += w[0].size() / 2;
  if (m % 2 == 0) {
    match += w[m / 2].size() / 2;
  }
  ans += match;
  fin(ans);
}
