// 引用元 : https://atcoder.jp/contests/abc125/submissions/5996653
// 得点 : 300
// コード長 : 532
// 実行時間 : 45


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main(){
    int n, ans=0; cin >> n;
    vector<int> a(n), l(n+1), r(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        if(i) l[i+1] = gcd(l[i], a[i-1]);
        r[n-1-i] = gcd(r[n-i], a[n-1-i]);
    }
    for(int i = 0; i < n; i++) ans = max(ans, gcd(l[i+1], r[i+1]));
    cout << ans << endl;
    return 0;
}
