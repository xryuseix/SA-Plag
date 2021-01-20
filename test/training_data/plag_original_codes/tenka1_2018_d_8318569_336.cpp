/*
引用元：https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_d
D - CrossingEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/tenka1-2018-beginner/submissions/8318569
// 提出ID : 8318569
// 問題ID : tenka1_2018_d
// コンテストID : tenka1-2018-beginner
// ユーザID : xryuseix
// コード長 : 2864
// 実行時間 : 20



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
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL << 62;

bool isok(int n) {
  set<int> s;
  int add = 0;
  for (int i = 0;; i++) {
    add += 3;
    s.insert(add);
    if (add > 100000)
      break;
    add += i;
  }
  if (s.find(n) == s.end()) {
    return 0;
  } else {
    return 1;
  }
}

int main(void) {

  int n;
  cin >> n;
  if (n == 1) {
    cout << "Yes" << endl;
    cout << 2 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  if (!isok(n)) {
    cout << "No" << endl;
    return 0;
  } else {
    cout << "Yes" << endl;
  }
  vvi v;
  vector<int> a{1, 2};
  v.push_back(a);
  vector<int> b{2, 3};
  v.push_back(b);
  vector<int> c{3, 1};
  v.push_back(c);

  int tate = 0;
  int yoko = 2;
  for (int i = 4; i <= n; i++) {
    if (v[0].size() == v[v.size() - 1].size()) {
      vector<int> tmp(1, i);
      v.push_back(tmp);
      yoko++;
    } else {
      v[yoko].push_back(i);
    }
    v[tate].push_back(i);
    tate++;
    if (tate == yoko) {
      tate = 0;
    }
  }
  cout << (int)v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << (int)v[i].size();
    for (int j = 0; j < v[i].size(); j++) {
      cout << " " << v[i][j];
    }
    cout << endl;
  }
}
