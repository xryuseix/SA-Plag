// 引用元 : https://atcoder.jp/contests/agc033/submissions/9513336
// 得点 : 300
// コード長 : 1130
// 実行時間 : 75


#include <iostream>

using namespace std;

int n, m, a[1005][1005];
pair<int,int> Q[1000005];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int maxim = 1, in, sf;

void bordare()
{
    for (int i=0;i<=n+1;i++)
        a[i][0] = a[i][m+1] = 1;
    for (int i=0;i<=m+1;i++)
        a[0][i] = a[n+1][i] = 1;
}

void lee();

int main()
{
    int i, j;
    char c;

    cin >> n >> m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            cin >> c;
            if (c == '#')
                a[i][j] = 1;
        }
    bordare();
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i][j] == 1)
                Q[sf++] = {i,j};
    lee();
    cout << maxim-1;
    return 0;
}

void lee()
{
    while (in < sf)
    {
        auto aux = Q[in++];
        for (int i=0;i<4;i++)
        {
            int l9 = aux.first+dx[i];
            int c9 = aux.second+dy[i];
            if (!a[l9][c9])
            {
                a[l9][c9] = a[aux.first][aux.second]+1;
                Q[sf++] = {l9,c9};
                if (a[l9][c9] > maxim)
                    maxim = a[l9][c9];
            }
        }
    }
}
