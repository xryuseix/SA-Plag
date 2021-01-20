// 引用元 : https://atcoder.jp/contests/abc143/submissions/10047125
// 得点 : 400
// コード長 : 676
// 実行時間 : 72


#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;
int n;
int l[2009];
int memo[2009][9][2009];

int dp(int i,int cnt,int sum){
  if(memo[i][cnt][sum]!=-1)return memo[i][cnt][sum];
  if(i==n)return 0;
  int rec=dp(i+1,cnt,sum);
  if(cnt==2){
    if(l[i]<sum)rec++;
  }
  else{
    rec+=dp(i+1,cnt+1,sum+l[i]);
  }
  return memo[i][cnt][sum]=rec;
}

int main(){
  memset(memo,-1,sizeof(memo));
  cin>>n;
  rep(i,n){
    cin>>l[i];
  }
  sort(l,l+n);

  cout<<dp(0,0,0)<<endl;

  return(0);
}
