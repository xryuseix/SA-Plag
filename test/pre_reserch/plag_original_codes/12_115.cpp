// 引用元 : https://atcoder.jp/contests/abc138/submissions/7564421
// 得点 : 400
// コード長 : 746
// 実行時間 : 132


#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
#define ll long long
#define out(a) cout<<a<<" "

const int INF = 1e9+7;
const int inf = 1e5*2;

vector<vector<int>> tr;
int val[inf], ans[inf];
int add;

void dfs(int l, int v){
  add += val[l];
  ans[l] += add;
  for(auto e : tr[l]){
    if (e == v) continue;
    dfs(e, l);
  }
  add -= val[l];
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  add = 0;

  int n,q; cin>>n>>q;
  tr.resize(n);
  rep(i,n-1){
    int a,b; cin>>a>>b;
    a--, b--;
    tr[a].push_back(b);
    tr[b].push_back(a);
  }
  rep(i,q){
    int p,x; cin>>p>>x; p--;
    val[p] += x;
  }
  rep(i,inf) ans[i] = 0;
  dfs(0, -1);
  rep(i,n) cout<<ans[i]<<" ";

  
  return 0;
}
