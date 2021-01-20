/*
引用元：https://atcoder.jp/contests/abc084/tasks/abc084_c
C - Special TrainsEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/abc084/submissions/5014448
// 提出ID : 5014448
// 問題ID : abc084_c
// コンテストID : abc084
// ユーザID : xryuseix
// コード長 : 1549
// 実行時間 : 4



*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <bitset>
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
using namespace std;
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
const long long LLINF = 1LL << 60;
// set<int>::iterator it;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////////////////////

  int i, j, n;
  cin >> n;
  int c[n - 1], s[n], f[n - 1];
  rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
  s[n - 1] = 0;
  //動き続けてアップアップ！！
  // mod切り上げをしよう
  // O(N^2) でとけるはず！
  int ans;
  for (i = 0; i < n - 1; i++) {
    ans = s[i];
    //		cout<<"1:"<<ans<<endl;
    for (j = i; j < n - 2; j++) {
      ans += c[j];
      //			cout<<"2:"<<ans<<endl;
      if (ans <= s[j + 1]) {
        ans = s[j + 1];
      } else {
        // ans切り上げ作業
        //			cout<<ans<<" "<<s[j+1]<<" "<<f[j+1]<<endl;
        ans = s[j + 1] +
              f[j + 1] * ceil((double)(ans - s[j + 1]) / (double)f[j + 1]);
      }
      //			cout<<"3:"<<ans<<endl;
    }
    cout << ans + c[n - 2] << endl;
  }
  cout << 0 << endl;

  //////////////////////////////////////////////////////
  return 0;
}
