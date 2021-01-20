// 引用元 : https://atcoder.jp/contests/abc126/submissions/8645414
// 得点 : 300
// コード長 : 421
// 実行時間 : 5


#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
int main(){
  long double N;
  int K;
  cin >> N >> K;
  vector<double> A(N);
  long double prob;
  rep(i,N){
    int coin = 0;
    while ((i+1) * pow(2, coin) < K){
      coin++;
    }
    prob = 1 / N;
    A[i] = prob * pow(0.5, coin);
  }
  printf("%.15lf\n",accumulate(A.begin(), A.end(), 0.0));
}
