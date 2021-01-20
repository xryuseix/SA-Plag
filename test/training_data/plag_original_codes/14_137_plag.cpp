// 引用元 : https://atcoder.jp/contests/agc033/submissions/9513336
// 得点 : 300
// コード長 : 1130
// 実行時間 : 75


#include <iostream>

using namespace std;

int n, m, a[1019][1034];
pair<int,int> Q[1000005];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int maxim = 1, in, sf;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void bordare()
{
    rep(i,n+2)
        a[i][0] = a[i][m+1] = 1;
    rep(i,m+2)
        a[0][i] = a[n+1][i] = 1;
}

void lee()
{
    while (in < sf)
    {
        auto aux = Q[in];
        in++;
        rep(i,4)
        {
            int l9 = aux.first+dx[i];
            int c9 = aux.second+dy[i];
            if (a[l9][c9]==0)
            {
                a[l9][c9] = a[aux.first][aux.second]+1;
                Q[sf] = {l9,c9};
                sf++;
                if (a[l9][c9] > maxim)
                    maxim = a[l9][c9];
            }
        }
    }
}

int main()
{
    int i, j;
    char c;

    cin >> n >> m;
    rep(i,n){
        rep(j,m){
            cin >> c;
            if (c == '#'){
                a[i+1][j+1] = 1;
            }
        }
    }
    bordare();
    rep(i,n){
        rep(j,m){
            if (a[i+1][j+1] == 1){
                Q[sf] = {i+1,j+1};
                sf++;
            }
        }
    }
    lee();
    cout << maxim-1;
    return 0;
}

