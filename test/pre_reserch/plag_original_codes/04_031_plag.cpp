// 引用元 : https://atcoder.jp/contests/abc085/submissions/10044065
// 得点 : 300
// コード長 : 385
// 実行時間 : 3


#include <iostream>
using namespace std;

int main(){
  int NNNNNNNNNNNNNNNNNNN, YYYYYYYYYYYYYYYY;
  cin >> NNNNNNNNNNNNNNNNNNN >> YYYYYYYYYYYYYYYY;
  
  for(int xxxxxxxxxxxxxxxxxxxxxxx = 0; xxxxxxxxxxxxxxxxxxxxxxx <= NNNNNNNNNNNNNNNNNNN; xxxxxxxxxxxxxxxxxxxxxxx++){
    for(int yyyyyyyyyyyyyyyyyyy = 0; yyyyyyyyyyyyyyyyyyy <= NNNNNNNNNNNNNNNNNNN-xxxxxxxxxxxxxxxxxxxxxxx; yyyyyyyyyyyyyyyyyyy++){
      int zzzzzzzzzzzzzzzzzzz = NNNNNNNNNNNNNNNNNNN - xxxxxxxxxxxxxxxxxxxxxxx - yyyyyyyyyyyyyyyyyyy;
      if(10000*xxxxxxxxxxxxxxxxxxxxxxx + 5000*yyyyyyyyyyyyyyyyyyy + 1000*zzzzzzzzzzzzzzzzzzz == YYYYYYYYYYYYYYYY){
        cout << xxxxxxxxxxxxxxxxxxxxxxx << ' ' << yyyyyyyyyyyyyyyyyyy << ' ' << zzzzzzzzzzzzzzzzzzz << endl;
        return 0;
      }
    }
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  return 0;
}
