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
        ans = min(ans, max( w*H, max((W-w)/2*H, ((W-w)-(W-w)/2)*H)) - min( w*H, min((W-w)/2*H, ((W-w)-(W-w)/2)*H)));
    }

    for(ll w=1; w<W; w++){
        ans = min(ans, max(w*H, max((W-w)*(H/2), (W-w)*(H-H/2))) - min(w*H, min((W-w)*(H/2), (W-w)*(H-H/2))));
    }

    for(ll h=1; h<H; h++){
        ans = min(ans, max(h*W, max(W*((H-h)/2), W*((H-h)- (H-h)/2))) - min(h*W, min(W*((H-h)/2), W*((H-h) - (H-h)/2))));
    }

    for(ll h=1; h<H; h++){
        ans = min(ans,  max(W*h, max((H-h)*(W/2), (H-h)*(W - W/2))) - min(W*h, min((H-h)*(W/2), (H-h)*(W - W/2))));
    }

    cout << ans << endl;
}
