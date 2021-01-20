// 引用元 : https://atcoder.jp/contests/abc137/submissions/6822524
// 得点 : 400
// コード長 : 816
// 実行時間 : 741


#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef  pair<int,int> pii;
const int N = 10010;
int n,m;
int vis[N];
priority_queue<pii> q;
vector<int> ve;
int main(){
    int a,b;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&a,&b);
        q.push(pii(b,a));
    }
    for(int i=1;i<=m;++i)   ve.push_back(i);
//for(auto i:ve){
//    printf("%d ",i);
//}
    int ans = 0;
    while(!q.empty()){
        pii cur = q.top();
        q.pop();
        if(cur.second>m)    continue;
//printf("%d ",m-cur.second);
        auto pos = lower_bound(ve.begin(),ve.end(),cur.second);
        if(pos==ve.end())   continue;
//printf("find! %d\n",*pos);
        ve.erase(pos);
        ans += cur.first;
    }
    printf("%d\n",ans);
    return 0;
}
