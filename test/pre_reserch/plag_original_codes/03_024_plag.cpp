// 引用元 : https://atcoder.jp/contests/abc126/submissions/10483524
// 得点 : 400
// コード長 : 771
// 実行時間 : 280


#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin >> n;
  vector<vector<P>> grafu(n);
  rep(i,n-1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    grafu[u].emplace_back(make_pair(v, w));
    grafu[v].emplace_back(make_pair(u, w));
  }
  vector<int> mhinduro(n,-1);
  auto dfs = [&](auto& f, int p, int u, int c)->void{
    mhinduro[u] = c;
    for (auto v : grafu[u]) {
      if (p == v.first) continue;
      if (mhinduro[v.first] != -1) continue;
      if (v.second & 1) f(f, u, v.first, 1-c);
      else f(f, u, v.first, c);
    }
  };
  dfs(dfs, -1, 0, 0);
  for (auto e : mhinduro) cout << e << endl;
  return 0;
}
