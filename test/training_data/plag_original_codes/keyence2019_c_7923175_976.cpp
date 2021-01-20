/*
引用元：https://atcoder.jp/contests/keyence2019/tasks/keyence2019_c
C - Exam and WizardEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/keyence2019/submissions/7923175
// 提出ID : 7923175
// 問題ID : keyence2019_c
// コンテストID : keyence2019
// ユーザID : xryuseix
// コード長 : 2830
// 実行時間 : 83



/*
                                   _ooOoo_
                                  o8888888o
                                  88" . "88
                                  (| -_- |)
                                  O\  =  /O
                           ____/`---'\____
                         .'  \\|     |//  `.
                        /  \\|||  :  |||//  \
                   /  _||||| -:- |||||-  \
                   |   | \\\  -  /// |   |
                   | \_|  ''\---/''  |   |
                   \  .-\__  `-`  ___/-. /
                 ___`. .'  /--.--\  `. . __
          ."" '<  `.___\_<|>_/___.'  >'"".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                fozubaoyou    pass System Test!
                quoted from
"https://codeforces.com/contest/472/submission/7996840"
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
#define PI acos(-1)
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
  vll a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll asum = 0, bsum = 0;
  rep(i, n) {
    asum += a[i];
    bsum += b[i];
  }
  if (asum < bsum) {
    fin(-1);
    return 0;
  }

  asum -= bsum;
  vector<int> rest;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i])
      rest.push_back(a[i] - b[i]);
    else if (a[i] == b[i])
      continue;
    else
      ans++;
  }
  Sort(rest);
  int pos = 0;
  // rep(i,rest.size()){
  // 	cout<<rest[i]<<" ";
  // }
  // cout<<endl;
  while (pos < rest.size()) {
    // cout << rest[pos] << " " << asum << " " <<ans <<endl;
    if (rest[pos] <= asum) {
      asum -= rest[pos];
      pos++;
    } else {
      ans++;
      pos++;
    }
  }
  if (asum > 0 && ans == 0) {
    ans++;
  }
  fin(ans);
}
