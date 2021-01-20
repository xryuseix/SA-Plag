// 引用元 : https://atcoder.jp/contests/abc137/submissions/6827191
// 得点 : 400
// コード長 : 596
// 実行時間 : 68


#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
#define all(v) (v).begin(),(v).end()
#define vsort(v) sort(all(v))
using data=pair<ll,ll>;

int main(){
  ll i,j=0,N,M,ans=0,a,b,x;
  cin>>N>>M;
  vector<data> v(N);
  priority_queue<ll> que;

  rep(i,N){
    cin>>a>>b;
    v[i]=data(a,b);
  }
  vsort(v);

  rep(i,M){
    while(j<N&&v[j].first<=i+1){
      que.push(v[j].second);
      j++;
    }

    if(!que.empty()){
      ans+=que.top();
      que.pop();
    }
  }
  cout<<ans<<endl;
  return 0;
}
