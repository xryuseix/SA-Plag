// 引用元 : https://atcoder.jp/contests/agc012/submissions/5997909
// 得点 : 700
// コード長 : 1174
// 実行時間 : 94


#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)1e5 + 1;
const int D = 11;
int col[N][D];

vector<int> T[N];

void dfs(int u, int di, int co){
    if(col[u][di] > 0){
        return;
    }
    col[u][di] = co;
    if(di>0){
        dfs(u,di-1,co);
        for(auto x : T[u]){
            dfs(x,di-1,co);
        }
    }
}

int main(){
    fastIO;
    int n, m, q;
    cin >> n >> m;
    int u, v;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    cin >> q;
    int vr[q], di[q], cl[q];
    for(int i = 0 ; i < q; i ++ ){
        cin >> vr[i] >> di[i] >> cl[i];
    }
    for(int i = q - 1 ;i >= 0 ; i -- ){
        dfs(vr[i], di[i], cl[i]);
    }
    for(int i = 1; i <= n; i ++ )
        cout << col[i][0] << "\n";
    return 0;
}
