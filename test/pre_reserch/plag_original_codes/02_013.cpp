// 引用元 : https://atcoder.jp/contests/abc129/submissions/5998282
// 得点 : 300
// コード長 : 810
// 実行時間 : 29


#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int N, M;
  cin >> N >> M;
  vector<long long int> a_v(M+1, -1);
  vector<long long int> f(N+1, 0);
  for (int i = 0; i < M; i++) {
    cin >> a_v.at(i);
  }
  // f_n = f_{n-1} + f_{n-2}
  // f_0 = 1
  // f_1 = 1
  // f_2 = 2
  // f_3 = 3
  long long int j = 0;
  for (int i = 0; i <= N; i++) {
    if (a_v[j] == i) {
      j++;
    }
    else {
      if (i >= 2) {
        f[i] = (f[i-1] + f[i-2]) % 1000000007;
      }
      else if (i == 1) {
        f[i] = f[i-1] + 0;
      }
      else if (i == 0) {
        f[i] = 1;
      }
 
    }
  }
  for (int i = 0; i <= N; i++) {
    //cout << "f" << f[i] << endl;
  }
  //cout << "j:" << j << endl;
 
  cout << f[N]%1000000007 << endl;
  return 0;
}
