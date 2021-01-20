// 引用元 : https://atcoder.jp/contests/abc132/submissions/6477860
// 得点 : 500
// コード長 : 1133
// 実行時間 : 61


#include <bits/stdc++.h>
using namespace std;

const int kn = 2e5 + 5, N = 1e5+5;

#define x first
#define y second

#define ff(i,n) for(int i=1;i<=n;i++)

int n, m, s, t;
vector<int> G[N];

int dis[3][N];

priority_queue< pair< pair<int,int>, int>, vector<pair< pair<int,int>, int> >, greater< pair< pair<int,int>, int> > > pq; //dis, remainder, vertex

int main() {
	scanf("%d %d", &n, &m);
	ff(i,m)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}
	ff(i,n) dis[0][i] = dis[1][i] = dis[2][i] = 3*m + 1;
	scanf("%d %d", &s, &t);
	dis[0][s] = 0;
	pq.push({{0,0},s});
	while(pq.size())
	{
		int dist = pq.top().x.x, rem = pq.top().x.y, u = pq.top().y;
		pq.pop();
		if(dist == 3*m || dist != dis[rem][u]) continue;
		int nxt = (rem+1)%3;
		for(int p : G[u])
		{
			if(dis[nxt][p] > dist + (!nxt))
			{
				dis[nxt][p] = dist + (!nxt);
				pq.push({{dist+(!nxt),nxt},p});
			}
		}
	}
	if(dis[0][t] == 3*m+1) printf("-1");
	else printf("%d",dis[0][t]);
}
