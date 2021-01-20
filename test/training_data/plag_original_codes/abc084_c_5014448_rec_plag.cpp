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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int i, y, n;
  cin >> n;
  int c[n-1], s[n], f[n-1];
  rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
  s[n-1]=0;
  int answer;
  for (i=0; i<(n-1); i++) {
    answer=s[i];
    for (y=i; y<(n-2); y++) {
      answer += c[y];
      if (answer<=s[y+1]) {
        answer=s[y+1];
      } else {
        answer=s[y+1]+f[y+1]*ceil((double)(answer-s[y+1])/(double)f[y+1]);
      }
    }
    cout << ans+c[n-2] << endl;
  }
  cout << 0 << endl;
}
