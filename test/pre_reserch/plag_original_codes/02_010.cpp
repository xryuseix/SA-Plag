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
tree_order_statistics_node_update>;

using ll = long long;
using pii = pair<int, int>;                                   

const int N = 2e5 + 1e2;
const int MOD = 1e9 + 7;
const int INF32 = 1e9 + 1e2;

int d[N];

vector<int> adj[N];

void bfs(int v = 0) {
    queue<int> q;
    q.push(v);
    fill(d, d + N, INF32);
    d[v] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int to : adj[x]) {
            if (d[to] > d[x] + 1) {
                d[to] = d[x] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 0; i < N; ++i)
        if (d[i] == INF32)
            d[i] *= -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs();
    int v = max_element(d, d + N) - d;
    bfs(v);
    int dia = *max_element(d, d + N);
    if (dia % 3 == 1)
        cout << "Second";
    else
        cout << "First";
    return 0;
}
