// 引用元 : https://atcoder.jp/contests/abc130/submissions/5962060
// 得点 : 300
// コード長 : 304
// 実行時間 : 1


#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(){
  double W,H,x,y;
  cin >> W >> H >> x >> y;
  double ans=W/2.0*H;
  int f;
  if(W/x==2.0 and H/y==2.0) f=1;
  else f=0;
  cout << ans << " " << f << endl;
  return 0;
}
