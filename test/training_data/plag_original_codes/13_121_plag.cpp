// 引用元 : https://atcoder.jp/contests/abc064/submissions/5997823
// 得点 : 300
// コード長 : 478
// 実行時間 : 1


#include<bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int,int>P;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define F first
#define S second
     
int main(){
  int n, a,ans=0,free=0;
  vector<int> color(8);
  scanf("%d",&n);
  rep(i,n){
    scanf("%d",&a);
    if(a>=3200) free++;
    else color[a/400]++;
  }

  rep(i,8){
    if(color[i]) ans++;
  }
  
  printf("%d %d\n",max(1,ans),ans+free);
  
  return 0;
}
