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
    int i=0;
    while(i<N){
        scanf("%lld",&A[i]);
        switch (!i)
        {
        case 1:
            S[i]=0;
            break;
        }
        S[i+1]=S[i]+A[i];
        i++;
    }
    int ans=0;
    int j=1;
    while(j<N+1){
        int i=j-1;
        auto it=M.find((S[i]-i)%K);
        switch (it!=M.end())
        {
        case 1:
            it->second++;
            break;
        
        default:
            M[(S[i]-i)%K]=1;
            break;
        }
        switch (j>=K)
        {
        case 1:
            i=j-K;
            auto it=M.find((S[i]-i)%K);
            switch (it!=M.end())
            {
            case 1:
                it->second--;
                break;
            }
            break;
        }
        it=M.find((S[j]-j)%K);
        ans+=it->second;
        j++;
    }
    printf("%lld",ans);

    return 0;
}
