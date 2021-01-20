// 引用元 : https://atcoder.jp/contests/abc064/submissions/5997823
// 得点 : 300
// コード長 : 478
// 実行時間 : 1


#include<bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int,int>P;
     
#define F first
#define S second
     
int main(){
  int n;
  int a,ans=0;
  int free=0;
  int color[8]={};
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    if(a>=3200) free++;
    else color[a/400]++;
  }

  for(int i=0;i<8;i++){
    if(color[i]>0) ans++;
  }
  
  printf("%d %d\n",max(1,ans),ans+free);
  
  return 0;
}