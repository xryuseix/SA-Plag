// 引用元 : https://atcoder.jp/contests/abc138/submissions/7487281
// 得点 : 600
// コード長 : 1323
// 実行時間 : 1


#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD (ll)(1e9+7)
ll L, R,bL[90], bR[90], mk[90][2][2][2];,i, j, k,l, ans;


ll solve(ll p,ll a,ll b,ll c){
    if(p==-1){
        return 1;
    }
    if(mk[p][a][b][c]!=-1)
        return mk[p][a][b][c];

    ll ret = 0;
    // 0 0
    if(a==1||bL[p]==0){
        ret += solve(p - 1, a, bR[p] == 1 ? 1 : b, c);

        // 0 1
        if(c==1&&(b==1||bR[p]==1))ret += solve(p - 1, a, b, c);
    }
    
    // 1 1 
    if(b==1||bR[p]==1)ret += solve(p - 1, bL[p] == 0 ? 1 : a, b, 1);

    mk[p][a][b][c] = ret % MOD;
    return ret % MOD;
}

int main(){
    scanf("%lld%lld", &L,&R);
    fornum(i,0,70)fornum(j,0,2)fornum(k,0,2)fornum(l,0,2)mk[i][j][k][l] = -1;

    fornum(i,0,62){
        if(R&(1ll<<i))bR[i] = 1;
        if(L&(1ll<<i))bL[i] = 1;
    }

    printf("%lld", solve(60,0,0,0));
    return 0;
}
