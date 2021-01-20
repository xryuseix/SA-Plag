// 引用元 : https://atcoder.jp/contests/abc126/submissions/9417319
// 得点 : 300
// コード長 : 363
// 実行時間 : 4


#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  double prob = 0;
  
  for(int i=0; i<n; i++) {
    int d = 0;
    for(int j=0; j<100000; j++) {
      if(pow(2, j) * (i + 1) >= k) {
        d = j;
        break;
      }
    }
    prob += 1.0 / (n * pow(2, d));
  }
  
  printf("%.12lf\n", prob);
}
