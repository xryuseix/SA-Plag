// 引用元 : https://atcoder.jp/contests/abc130/submissions/5963309
// 得点 : 300
// コード長 : 470
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    if(x*2 == w && y*2 == h)
        cout << std::setprecision(7) <<float(w)*h/2 << ' '<< 1;
    else
        cout << std::setprecision(7) <<float(w)*h/2<< ' '<< 0;
    return 0;
}
