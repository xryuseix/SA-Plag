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

#define LL long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
const int MAXN = 2e5 + 5;

LL a[MAXN];
int n;

int main(){
    cin>>n;
    rep(i,n) scanf("%lld",a[i+1]);
    LL ans = 0ll,s1 = 0,s2 = 0;
    int r = 1;s1 += a[1],s2 ^= a[1];
    rep(i,n){
        while(s1 == s2 && r <= n) r++,s1 += a[r],s2 ^= a[r];
        ans += r-(i+1);
        s1 -= a[i+1];
        s2 ^= a[i+1];
    }
    cout<<ans<<endl;
    return 0;
}
