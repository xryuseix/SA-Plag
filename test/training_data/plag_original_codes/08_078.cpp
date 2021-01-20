// 引用元 : https://atcoder.jp/contests/abc080/submissions/11159293
// 得点 : 300
// コード長 : 1025
// 実行時間 : 3


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  ll N;
  cin>>N;
  VVL F(N,VL(10));
  rep(i,N) rep(j,10) cin>>F[i][j];
  VVL P(N,VL(11));
  rep(i,N) rep(j,11) cin>>P[i][j];
  ll ans=-1001001001;
  rep(i,1<<10){
    if(i){
      VL B(10);
      rep(j,10) B[j]=(i>>j)&1;
      VL C(N);
      rep(j,10){
        if(B[j]) rep(k,N) if(F[k][j]) C[k]++;
      }
      ll tmp=0;
      rep(j,N) tmp+=P[j][C[j]];
      ans=max(ans,tmp);
    }
  }
  cout<<ans<<endl;
}
