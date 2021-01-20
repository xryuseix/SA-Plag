// 引用元 : https://atcoder.jp/contests/abc103/submissions/10044172
// 得点 : 400
// コード長 : 849
// 実行時間 : 28


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<long long , long long > P;

void solve(){
    ll N, M; cin >> N >> M;
    vector<pair<ll, ll>> ab(M);
    for (ll i = 0; i < M; ++i){
        ll a, b; 
        scanf("%lld", &a);
        scanf("%lld", &b);
        --a; --b;
        ab[i].first = a;
        ab[i].second = b;
    }
    sort(ab.begin(), ab.end(),
         [](const pair<ll ,ll>& x, const pair<ll, ll>& y){return x.second < y.second;});
    
    float right = -1;
    ll ans = 0;
    for (ll i = 0; i < M; ++i){
        if (right < ab[i].first) {
            ans++;
            right = ab[i].second - 0.1;
        }
    }
    printf("%lld\n", ans);


}
int main(void){
    //////////////////////////

    solve();

    //////////////////////////
    return 0;
}
