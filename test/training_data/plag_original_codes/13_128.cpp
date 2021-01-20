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

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  bool zero_exists = false;
  int64_t minv = INT64_MAX;
  int64_t sum = 0;
  int minus_cnt = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] == 0)
      zero_exists = true;
    if (A[i] < 0) {
      A[i] = -A[i];
      minus_cnt++;
    }
    if (A[i] != 0)
      minv = min({minv, A[i]});
    sum += A[i];
  }
  if (zero_exists || minus_cnt % 2 == 0)
    cout << sum << endl;
  else
    cout << sum - 2*minv << endl;
  return 0;
}
