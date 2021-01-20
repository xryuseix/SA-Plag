// 引用元 : https://atcoder.jp/contests/abc062/submissions/5998111
// 得点 : 400
// コード長 : 1641
// 実行時間 : 2


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    ll H,W; cin >> H >> W;

    ll ans = 1000000000000;

    ll s1, s2, s3;
    for(ll w=1; w<W; w++){
        ll res = W-w;
        s1 = w*H;
        s2 = res/2*H;
        s3 = (res-res/2)*H;
        ll tmp = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
        ans = min(ans, tmp);
    }

    for(ll w=1; w<W; w++){
        ll res = W-w;
        s1 = w*H;
        s2 = res*(H/2);
        s3 = res*(H-H/2);
        ll tmp = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
        ans = min(ans, tmp);
    }

    for(ll h=1; h<H; h++){
        ll res = H-h;
        s1 = h*W;
        s2 = W*(res/2);
        s3 = W*(res - res/2);
        ll tmp = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
        ans = min(ans, tmp);
    }

    for(ll h=1; h<H; h++){
        ll res = H-h;
        s1 = W*h;
        s2 = res*(W/2);
        s3 = res*(W - W/2);
        ll tmp = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}
