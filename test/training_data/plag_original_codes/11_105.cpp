// 引用元 : https://atcoder.jp/contests/abc146/submissions/10701424
// 得点 : 500
// コード長 : 1107
// 実行時間 : 249


#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007

int N,K;
int A[200005];
int S[200005];
map<int,int> M;
signed main(){
    scanf("%lld %lld",&N,&K);
    rep(i,N){
        scanf("%lld",&A[i]);
        if(i==0){
            S[i]=0;
        }
        S[i+1]=S[i]+A[i];
    }
    int ans=0;
    for(int j=1;j<N+1;j++){
        int i=j-1;
        auto it=M.find((S[i]-i)%K);
        if(it!=M.end()){
            it->second++;
        }else{
            M[(S[i]-i)%K]=1;
        }
        if(j>=K){
            i=j-K;
            auto it=M.find((S[i]-i)%K);
            if(it!=M.end()){
                it->second--;
            }
        }
        it=M.find((S[j]-j)%K);
        ans+=it->second;
    }
    printf("%lld",ans);

    return 0;
}
