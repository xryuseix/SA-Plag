#include <iostream>
#include <queue>
using namespace std;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl

struct Corr {
  int x;
  int y;
  int depth;
};

queue<Corr> q;
Corr co;
void bfs(vvc &v, int k, int r, int c) {
  while (!q.empty()) {
    Corr now = q.front();
    q.pop();
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      if (now.x + dx[i] >= 0 && now.y + dy[i] >= 0 && now.x + dx[i] < c &&
          now.y + dy[i] < r && v[now.y + dy[i]][now.x + dx[i]] == 'o' &&
          now.depth < k - 1) {
        co = {now.x + dx[i], now.y + dy[i], now.depth + 1};
        v[now.y + dy[i]][now.x + dx[i]] = 'x';
        q.push(co);
      }
    }
  }
  return;
}

int main(void) {

  int r, c, k;
  cin >> r >> c >> k;
  vvc v(r, vc(c));
  string s;
  rep(i, r) {
    cin >> s;
    rep(j, c) {
      v[i][j] = s[j];
      if (v[i][j] == 'x') {
        co = {j, i, 0};
        q.push(co);
      }
    }
  }

  bfs(v, k, r, c);
  for (int i = 0; i < k - 1; i++) {
    for (int j = 0; j < c; j++) {
      v[i][j] = 'x';
    }
  }
  for (int i = r - 1; i >= r - k + 1; i--) {
    for (int j = 0; j < c; j++) {
      v[i][j] = 'x';
    }
  }
  for (int i = 0; i < k - 1; i++) {
    for (int j = 0; j < r; j++) {
      v[j][i] = 'x';
    }
  }
  for (int i = c - 1; i >= c - k + 1; i--) {
    for (int j = 0; j < r; j++) {
      v[j][i] = 'x';
    }
  }
  int ans = 0;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      // cout<<v[i][j]<<" ";
      if (v[i][j] == 'o')
        ans++;
    }
    // cout<<endl;
  }
  fin(ans);
}
