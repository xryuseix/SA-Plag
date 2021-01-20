// 引用元 : https://atcoder.jp/contests/agc033/submissions/7715396
// 得点 : 300
// コード長 : 1992
// 実行時間 : 90


#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define fi first
#define se second
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = 1; i < (n); ++i)
#define drep(i,n) for (int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define all(x) (x).begin(), (x).end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define pb push_back
#define sz(x) (int)(x).size()
#define PQ(T) priority_queue<T, v(T), greater<T> >

#define v(T) vector<T>
#define vv(T) v(v(T))

using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;

const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

const int mod = 1000000007;

char field[1010][1010];
int d[1010][1010];

int H, W;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<P> que;

void bfs() {
    while(!que.empty()) {
        P p = que.front(); que.pop();
        int x = p.fi;
        int y = p.se;
        field[y][x] = '#';
        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>=W || ny<0 || ny>=H) continue;
            if (field[ny][nx]=='#') continue;
            if (d[ny][nx]!=INF) continue;
            d[ny][nx] = d[y][x] + 1;
            que.push(P(nx,ny));
        }
    }
}

int main() {
    cin >> H >> W;
    rep(y,H)rep(x,W) {
        cin >> field[y][x];
        d[y][x] = INF;
    }
    rep(y,H)rep(x,W) {
        if (field[y][x] == '#') {
            que.push(P(x,y));
            d[y][x] = 0;
        }
    }
    bfs();
    int ans = 0;
    rep(y,H)rep(x,W) ans = max(ans, d[y][x]);
    cout << ans << endl;
    return 0;
}


