// 引用元 : https://atcoder.jp/contests/abc126/submissions/8708904
// 得点 : 300
// コード長 : 461
// 実行時間 : 2


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int N,K;

int dfs(int n, double depth){
  if(n >= K){
    return depth;
  }else{
    return dfs(n*2, depth + 1);
  }
}

int main(){
  cin >> N >> K;
  int i;
  double ans = 0;
  for(i=0; i<N; i++){
    if(i+1 >= K){
      ans += 1;
    }else{
      ans += (1 / pow(2, dfs(i+1, 0)));
    }
  }
  cout << setprecision(10) << ans / N << endl;
  return 0;
}
