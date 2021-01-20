// 引用元 : https://atcoder.jp/contests/agc014/submissions/5997975
// 得点 : 300
// コード長 : 400
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  int AA,BB,CC;
  int sum=0;
  cin >> A >> B >> C;
  if(A==B && B==C){
    if(A%2==0)cout << -1;
    else cout << 0;
  }
  else{
    while(A%2==0 && B%2==0 && C%2==0){
      AA=(B+C)/2;
      BB=(A+C)/2;
      CC=(A+B)/2;
      A=AA;
      B=BB;
      C=CC;
      sum++;
    }
    cout << sum;
  }
}

