/*
引用元：https://atcoder.jp/contests/abc001/tasks/abc001_4
D - 感雨時刻の整理Editorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc001/submissions/7945342
// 提出ID : 7945342
// 問題ID : abc001_4
// コンテストID : abc001
// ユーザID : xryuseix
// コード長 : 2653
// 実行時間 : 364



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
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
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
const ll LLINF = 1LL << 60;

int main(void) {

  int n;
  cin >> n;
  string s;
  vector<pair<int, int>> v;

  rep(i, n) {
    cin >> s;
    int a = STI(s.substr(0, 4));
    int b = STI(s.substr(5, 4));
    if (a % 10 > 5) {
      a /= 10;
      a *= 10;
      a += 5;
    } else if (a % 10 > 0 && a % 10 != 5) {
      a /= 10;
      a *= 10;
    }
    if (b % 10 > 5) {
      b /= 10;
      b *= 10;
      b += 10;
    } else if (b % 10 > 0 && b % 10 != 5) {
      b /= 10;
      b *= 10;
      b += 5;
    }
    if (b % 100 == 60) {
      b += 40;
    }
    v.push_back(mp(a, b));
  }
  Sort(v);

  // cout<<"---------"<<endl;
  // for(int i=0;i<v.size();i++){
  //     cout<<v[i].first<<" "<<v[i].second<<endl;
  // }
  // cout<<"---------"<<endl;

  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i].second >= v[i + 1].first) {
      v[i + 1].first = v[i].first;
      v[i + 1].second = max(v[i].second, v[i + 1].second);
      v.erase(v.begin() + i);
      i--;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    printf("%04d-%04d\n", v[i].first, v[i].second);
  }
}
