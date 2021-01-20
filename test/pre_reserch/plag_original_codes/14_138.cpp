// 引用元 : https://atcoder.jp/contests/abc098/submissions/5996279
// 得点 : 500
// コード長 : 1042
// 実行時間 : 21


#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;

LL a[MAXN];
int n;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lld",a+i);
    LL ans = 0ll,s1 = 0,s2 = 0;
    int r = 1;s1 += a[1],s2 ^= a[1];
    FOR(l,1,n){
        //s1 += a[l],s2 ^= a[l];
        while(s1 == s2 && r <= n) r++,s1 += a[r],s2 ^= a[r];
        ans += r-l;
        s1 -= a[l];s2 ^= a[l];
        //DEBUG(l);DEBUG(r);
    }
    printf("%lld\n",ans);
    return 0;
}
