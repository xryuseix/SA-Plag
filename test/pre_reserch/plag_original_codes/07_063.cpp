// 引用元 : https://atcoder.jp/contests/abc126/submissions/8712883
// 得点 : 600
// コード長 : 1420
// 実行時間 : 21


#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;

int main(){
  prep();
  int n, k;
  cin >> n >> k;
  int lim = pow(2, n);
  if (k > lim-1){
      cout << -1;
      return 0;
  }
  if (k == 0){
      for (int i=0; i<lim; i++){
          cout << i << " ";
      }
      for (int i=lim-1; i>=0; i--){
          cout << i << " ";
      }
  }else if (n == 1 && k == 1){
      cout << -1;
  }else{
      cout << "0 ";
      cout << k << " 0 ";
      for (int i=1; i<lim; i++){
          if (i == k){
              continue;
          }
          cout << i << " ";
      }
      cout << k << " ";
      for (int i=lim-1; i>=1; i--){
          if (i == k){
              continue;
          }
          cout << i << " ";
      }
  }
  return 0; 
}
