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
void hutei(int a, int b, int c, bool minus) {
    vector<int> arr;

    // A / B = div...mod
    int A = max(a, b);
    int B = min(a, b);
    int div, mod;

    while(1) {
        div = A/B;
        mod = A%B;
        arr.push_back(div);

        A = B;
        B = mod;

        if(mod == 1) {
            break;
        }
    }

    vector<vector<int> > calc(2, vector<int> (arr.size() + 1, INF));

    for(int i = 0; i < arr.size() - 1; i++) {
        calc[0][i] = -arr[i];
    }
    calc[1][arr.size() - 1] = -arr[arr.size() - 1];
    calc[1][arr.size()] = 1;

    for(int i = arr.size()-2; i >= 0; i--) {
        calc[1][i] = calc[0][i]*calc[1][i + 1] + calc[1][i + 2];
    }

    int x = calc[1][0]*c;
    int y = calc[1][1]*c;

    if(minus) {
        y *= -1;
    }
    cout << a << "(" << b << "m + " << x << ")";
    if(minus) {
        cout << " - ";
    } else {
        cout << " + ";
    }
    cout << b << "(" << a << "m + " << y << ")" << " = " << c << endl;
}
int main(void){
    //////////////////////////

    solve();

    //////////////////////////
    return 0;
}
