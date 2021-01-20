// 引用元 : https://atcoder.jp/contests/agc033/submissions/9436477
// 得点 : 300
// コード長 : 1044
// 実行時間 : 128


#include <bits/stdc++.h>
using namespace std;

int R, C;
char G[1005][1005];
queue<pair<int, pair<int, int> > > Q;
int dist[1005][1005];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {

  cin >> R >> C;
  int i=0,j=0;
  while(i<R){
    while(j<C){
      cin >> G[i][j];
      if (G[i][j] == '#') {
        Q.push(make_pair(0, make_pair(i, j)));
      }
      j++;
    }
    i++;
  }

  memset(dist, -1, sizeof(dist));
  while (!Q.empty()) {
    int d = Q.front().first, r = Q.front().second.first, c = Q.front().second.second;
    Q.pop();
    if (dist[r][c] != -1) continue;
    dist[r][c] = d;
    i=0;
    while(i < 4) {
      switch (r + dx[i] >= 0 && r + dx[i] < R && c + dy[i] >= 0 && c + dy[i] < C)
      {
      case 1:
        Q.push(make_pair(d + 1, make_pair(r + dx[i], c + dy[i])));
        break;
      i++;
    } 
  }

  int big = -1;
  i=j=0;
  while (i < R) {
    while (j < C) {
      switch (dist[i][j] > big)
      {
      case 1:
        big = dist[i][j];
        break;
      }
      j++;
    }
    i++;
  }
  cout << big;

}
