// 引用元 : https://atcoder.jp/contests/abc130/submissions/5963309
// 得点 : 300
// コード長 : 470
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
int main() {
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    if(x*2 == w && y*2 == h)
        printf("%.7f 1\n",float(w)*h/2);
    else
        printf("%.7f 0\n",float(w)*h/2);
    return 0;
}
