// 引用元 : https://atcoder.jp/contests/abc077/submissions/5997212
// 得点 : 300
// コード長 : 920
// 実行時間 : 148


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll =  long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i=0;i<n;++i){
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for(int i=0;i<n;++i){
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    

    vector<ll> ab(n), bc(n), bc_count(n, 0);
    for(int i=0;i<n;++i) {
        ab[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        ++bc_count[ab[i]];
    }
    for(int i=1;i<n;++i) bc_count[i] += bc_count[i-1];
    for(int i=0;i<n;++i) {
        bc[i] = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
    }

    ll ans = 0LL;
    for(int i=0;i<n;++i) {
        ans += bc_count[i] * (n-bc[i]);
    }

    cout << ans << endl;
}
