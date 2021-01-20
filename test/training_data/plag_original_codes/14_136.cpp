// 引用元 : https://atcoder.jp/contests/abc126/submissions/8645414
// 得点 : 300
// コード長 : 421
// 実行時間 : 5


#include <bits/stdc++.h>
using namespace std;
int main(){
  long double N;
  int K;
  cin >> N >> K;
  vector<double> A(N);
  long double prob;
  for (int i = 1; i <= N; i++){
    int coin = 0;
    while (i * pow(2, coin) < K){
      coin ++;
    }
    prob = 1 / N;
    A.at(i-1) = prob * pow(0.5, coin);
  }
  cout << fixed << setprecision(15);
  cout << accumulate(A.begin(), A.end(), 0.0) << endl;
}
