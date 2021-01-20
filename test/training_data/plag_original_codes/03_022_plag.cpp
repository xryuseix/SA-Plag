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
vector<bool>kushandiswa;
vector<vector<pii>>kumucheto;
vector<int>d;
bool judge=true;

void dfs(int v,int val){
    kushandiswa[v]=true;
    rep(i,kumucheto[v].size()){
        int inotevera=kumucheto[v][i].first;
        int mutengo=kumucheto[v][i].second;
        if(d[inotevera]==INF){
            d[inotevera]=val+mutengo;
            if(!kushandiswa[inotevera])dfs(inotevera,d[inotevera]);
        }else if(d[inotevera]!=mutengo+val){
            judge=false;
        }
    }
}
signed main(){
    int n,m; cin>>n>>m;
    
    kumucheto = vector<vector<pii>>(n);
    kushandiswa = vector<bool>(n,false);
    d    = vector<int>(n,INF);
    
    rep(i,m){
        int a,b,c;cin>>a>>b>>c;
        --a,--b;
        kumucheto[a].push_back(make_pair(b,c));
        kumucheto[b].push_back(make_pair(a,-c));
    }
    rep(i,n)if(!kushandiswa[i])dfs(i,0);
    cout << (judge ? "Yes" : "No") << endl;
}
