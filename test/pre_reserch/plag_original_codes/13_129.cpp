// 引用元 : https://atcoder.jp/contests/abc126/submissions/6478077
// 得点 : 400
// コード長 : 967
// 実行時間 : 272


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stack>
#include <list>

using namespace std;

typedef pair<int, int> P;

void dfs(vector<vector<P>> &tree, vector<char> &color, int now, int dis) {
  for (auto e : tree[now]) {
    if (color[e.first]) continue;
    if ((dis + e.second) % 2 == 0) {
      color[e.first] = '0';
    } else {
      color[e.first] = '1';
    }
    dfs(tree, color, e.first, dis + e.second);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<P>> tree(n);
  int u, v, w;
  vector<char> color(n);
  for (int i = 0; i < n-1; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    P p1 = make_pair(v, w);
    P p2 = make_pair(u, w);
    tree[u].push_back(p1);
    tree[v].push_back(p2);
  }
  color[0] = '0';
  dfs(tree, color, 0, 0);
  for (auto c : color) {
    cout << c << endl;
  }
}
