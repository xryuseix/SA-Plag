// 引用元 : https://atcoder.jp/contests/abc085/submissions/10044065
// 得点 : 300
// コード長 : 385
// 実行時間 : 3


#include <iostream>
using namespace std;

int main(){
  int N, Y;
  cin >> N >> Y;
  
  for(int x = 0; x <= N; x++){
    for(int y = 0; y <= N-x; y++){
      int z = N - x - y;
      if(10000*x + 5000*y + 1000*z == Y){
        cout << x << ' ' << y << ' ' << z << endl;
        return 0;
      }
    }
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  return 0;
}
