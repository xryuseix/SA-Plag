// 引用元 : https://atcoder.jp/contests/abc125/submissions/6478220
// 得点 : 400
// コード長 : 707
// 実行時間 : 48


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  bool zero_exists = false;
  long long minv = 1LL<<62;
  long long sum = 0;
  int minus_cnt = 0;
  rep (i,N) {
    cin >> A[i];
    if (!A[i])
      zero_exists = true;
    if (A[i] < 0) {
      A[i] = -A[i];
      minus_cnt++;
    }
    if (A[i])
      minv = min(minv, A[i]);
    sum += A[i];
  }
  if (zero_exists || !(minus_cnt % 2))
    cout << sum << endl;
  else
    cout << sum - 2*minv << endl;
  return 0;
}
