/*
引用元：https://atcoder.jp/contests/code-formula-2014-quala/tasks/code_formula_2014_qualA_b
B - ボウリングゲームEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/code-formula-2014-quala/submissions/6628242
// 提出ID : 6628242
// 問題ID : code_formula_2014_qualA_b
// コンテストID : code-formula-2014-quala
// ユーザID : xryuseix
// コード長 : 2960
// 実行時間 : 1



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
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
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
const int P = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int a, b;
  cin >> a >> b;
  vi v(a), w(b), pin(10, 0); // 0..倒れてない、1..１かいめ
  rep(i, a) cin >> v[i];
  rep(i, b) cin >> w[i];
  rep(i, a) pin[v[i]] = 1;
  rep(i, b) { pin[w[i]] = 2; }
  // rep(i,10)cout<<pin[i]<<" ";
  // cout<<endl;
  int n;
  n = 7;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << " ";
  n = 8;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << " ";
  n = 9;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << " ";
  n = 0;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << endl;

  cout << " ";
  n = 4;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << " ";
  n = 5;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << " ";
  n = 6;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << endl;

  cout << "  ";
  n = 2;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << " ";
  n = 3;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << endl;

  cout << "   ";
  n = 1;
  if (pin[n] == 0)
    cout << 'x';
  else if (pin[n] == 1)
    cout << '.';
  else
    cout << 'o';
  cout << endl;

  //////////////////////////////////////////////////////
  return 0;
}
