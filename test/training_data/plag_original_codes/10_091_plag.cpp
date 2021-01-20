// 引用元 : https://atcoder.jp/contests/abc126/submissions/9417319
// 得点 : 300
// コード長 : 363
// 実行時間 : 4


#include <bits/stdc++.h>
using namespace std;

int n, k;
float prob = 0;
int main() {
  cin >> n >> k;
  
  
  for(int i=0; i<n; i++) {
    int d = 0;
    for(int j=0; j<100000; j++) {
      if((i + 1) * pow(2, j) - k >= 0) {
        d = j;
        break;
      }
    }
    prob += 1.0 / (pow(2, d) * n);
  }
  
  printf("%.12lf\n", prob);
}
