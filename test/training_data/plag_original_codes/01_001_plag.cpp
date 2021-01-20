// 引用元 : https://atcoder.jp/contests/abc087/submissions/5998009
// 得点 : 400
// コード長 : 1575
// 実行時間 : 205


#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
using ll = long long;
using ld =long double;
#define int ll
#define INF 100000000000000
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<int,pii> piii;
#define mp make_pair
vector<bool>used;
vector<vector<pii>>edge;
vector<int>d;
bool judge=true;
void dfs(int v,int val){
    used[v]=true;
    rep(i,edge[v].size()){                   int next=edge[v][i].first;
        int cost=edge[v][i].second;                 if(d[next]==INF){
d[next]=val+cost;
if(!used[next])dfs(next,val+cost);            continue;
        }
        else{
            if(d[next]!=INF&&d[next]!=cost+val)judge=false;
        }
    }
}       
signed main(){
    int n,m; cin>>n>>m;
edge.resize(n);    used.resize(n);
d.resize(n);rep(i,n)d[i]=INF,   used[i]=               false;
rep(i,m){       
        int a,b,c;cin>>a>>b>>c;
        --a,--b;
                edge[a].push_back(mp(b,c));        edge[b].push_back(mp(a,-c));
                }        rep(i,n)if(!used[i])dfs(i,0);
            if(judge)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
