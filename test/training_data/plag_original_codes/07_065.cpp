// 引用元 : https://atcoder.jp/contests/agc015/submissions/11157603
// 得点 : 400
// コード長 : 388
// 実行時間 : 5


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
  string S;
  cin>>S;
  ll N=S.size(),ans=0;
  for(ll i=0;i<N;i++){
    if(S[i]=='U'){
      ans+=N-i-1;
      ans+=i*2;
    }else{
      ans+=(N-i-1)*2;
      ans+=i;
    }
  }
  cout<<ans<<endl;
}
