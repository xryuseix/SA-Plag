// 引用元 : https://atcoder.jp/contests/abc138/submissions/7482946
// 得点 : 400
// コード長 : 710
// 実行時間 : 370


#include<bits/stdc++.h>
using                               namespace std;
vector<int>                              AdjList[200001];
unsigned long long cost[200001];
int                               flag[200001];
void DFS(int u){flag[u]=1;
                                  for(int i=0;i<                              AdjList[u].size();i++){
        int v=AdjList[u][i];
        if(flag[v]==0){cost[v]+=cost[u];
            DFS(v);}}
}
int main(){int n,q;cin>>n>>q;
    for(int i=1;i<n;i++){
        int                               a,b;cin                              >>a>>b;
                                      AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }for(int i=1;i<=q;i++){                   
        int a,b;        cin>>a>>b;                
        cost[a]+=b;
    }DFS(1);    for(int i=1;i<=                                      n;i++){
        cout<<cost[i]<<" ";    }
    cout                              <<endl;
}
