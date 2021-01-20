// 引用元 : https://atcoder.jp/contests/abc087/submissions/5998090
// 得点 : 400
// コード長 : 1193
// 実行時間 : 213


#include<bits/stdc++.h>
using ll = long long;
#define int ll
#define INF 100000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
using namespace std;
using pii = pair<int,int>;
vector<bool>used;
vector<vector<pii>>edge;
vector<int>d;
bool judge=true;

void dfs(int v,int val){
    used[v]=true;
    rep(i,edge[v].size()){
        int next=edge[v][i].first;
        int cost=edge[v][i].second;
        if(d[next]==INF){
            d[next]=val+cost;
            if(!used[next])dfs(next,d[next]);
        }else if(d[next]!=cost+val){
            judge=false;
        }
    }
}
signed main(){
    int n,m; cin>>n>>m;
    
    edge = vector<vector<pii>>(n);
    used = vector<bool>(n,false);
    d    = vector<int>(n,INF);
    
    rep(i,m){
        int a,b,c;cin>>a>>b>>c;
        --a,--b;
        edge[a].push_back(make_pair(b,c));
        edge[b].push_back(make_pair(a,-c));
    }
    rep(i,n)if(!used[i])dfs(i,0);
    cout << (judge ? "Yes" : "No") << endl;
}
