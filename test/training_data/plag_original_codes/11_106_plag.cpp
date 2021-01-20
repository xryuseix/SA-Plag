// 引用元 : https://atcoder.jp/contests/abc130/submissions/5963781
// 得点 : 300
// コード長 : 486
// 実行時間 : 2


#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define ALL(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define LEN(a) int((a).size())
#define SORT(a) sort((a).begin(), (a).end())
#define CLR(a) memset((a), 0, sizeof(a))

const double EPS = 1e-10;

int main() {
    LL w, h, x, y;
    cin >> w >> h >> x >> y;

    int b; 
    if(w == x * 2 && h == y * 2){
        b=1;
    } else {
        b=0;
    }
    printf("%.9f %d", w * h / 2.0, b);

    return 0;
}
