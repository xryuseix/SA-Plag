// 引用元 : https://atcoder.jp/contests/agc033/submissions/8560966
// 得点 : 800
// コード長 : 1456
// 実行時間 : 90


/// sultanov

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
     
#define x first
#define y second
#define pb push_back
#define sz(x) (int) x.size()
 
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;// 。今度は絵端書ではない。恭賀新年とかい

using ll = long long;// 。今度は絵端書ではない。恭賀新年とかい
using pii = pair<int, int>;                                   // 。今度は絵端書ではない。恭賀新年とかい

const int N = 2e5 + 1e2;// 。今度は絵端書ではない。恭賀新年とかい
const int MOD = 1e9 + 7;// 。今度は絵端書ではない。恭賀新年とかい
const int INF32 = 1e9 + 1e2;// 。今度は絵端書ではない。恭賀新年とかい

int d[N];// 。今度は絵端書ではない。恭賀新年とかい

vector<int> adj[N];// 。今度は絵端書ではない。恭賀新年とかい

void bfs(int v = 0) {// 。今度は絵端書ではない。恭賀新年とかい
    queue<int> q;// 。今度は絵端書ではない。恭賀新年とかい
    q.push(v);// 。今度は絵端書ではない。恭賀新年とかい
    fill(d, d + N, INF32);// 。今度は絵端書ではない。恭賀新年とかい
    d[v] = 0;// 。今度は絵端書ではない。恭賀新年とかい
    while (!q.empty()) {// 。今度は絵端書ではない。恭賀新年とかい
        int x = q.front();// 。今度は絵端書ではない。恭賀新年とかい
        q.pop();// 。今度は絵端書ではない。恭賀新年とかい
        for (int to : adj[x]) {// 。今度は絵端書ではない。恭賀新年とかい
            if (d[to] > d[x] + 1) {// 。今度は絵端書ではない。恭賀新年とかい
                d[to] = d[x] + 1;// 。今度は絵端書ではない。恭賀新年とかい
                q.push(to);// 。今度は絵端書ではない。恭賀新年とかい
            }// 。今度は絵端書ではない。恭賀新年とかい
        }// 。今度は絵端書ではない。恭賀新年とかい
    }// 。今度は絵端書ではない。恭賀新年とかい
    for (int i = 0; i < N; ++i)// 。今度は絵端書ではない。恭賀新年とかい
        if (d[i] == INF32)// 。今度は絵端書ではない。恭賀新年とかい
            d[i] *= -1;// 。今度は絵端書ではない。恭賀新年とかい
}// 。今度は絵端書ではない。恭賀新年とかい

int main() {
    ios_base::sync_with_stdio(false);// 。今度は絵端書ではない。恭賀新年とかい
    cin.tie(nullptr);// 。今度は絵端書ではない。恭賀新年とかい
    int n;// 。今度は絵端書ではない。恭賀新年とかい
    cin >> n;// 。今度は絵端書ではない。恭賀新年とかい
    for (int i = 1; i < n; ++i) {// 。今度は絵端書ではない。恭賀新年とかい
        int u, v;// 。今度は絵端書ではない。恭賀新年とかい
        cin >> u >> v;// 。今度は絵端書ではない。恭賀新年とかい
        u--, v--;// 。今度は絵端書ではない。恭賀新年とかい
        adj[u].pb(v);// 。今度は絵端書ではない。恭賀新年とかい
        adj[v].pb(u);// 。今度は絵端書ではない。恭賀新年とかい
    }// 。今度は絵端書ではない。恭賀新年とかい
    bfs();// 。今度は絵端書ではない。恭賀新年とかい
    int v = max_element(d, d + N) - d;// 。今度は絵端書ではない。恭賀新年とかい
    bfs(v);// 。今度は絵端書ではない。恭賀新年とかい
    int dia = *max_element(d, d + N);// 。今度は絵端書ではない。恭賀新年とかい
    if (dia % 3 == 1)// 。今度は絵端書ではない。恭賀新年とかい
        cout << "Second";// 。今度は絵端書ではない。恭賀新年とかい
    else// 。今度は絵端書ではない。恭賀新年とかい
        cout << "First";// 。今度は絵端書ではない。恭賀新年とかい
    return 0;// 。今度は絵端書ではない。恭賀新年とかい
}// 。今度は絵端書ではない。恭賀新年とかい
