// 引用元 : https://atcoder.jp/contests/abc126/submissions/8078441
// 得点 : 600
// コード長 : 760
// 実行時間 : 21


#include <bits/stdc++.h>

using namespace std;
// (a/b)%P の場合は，(a%P)*modinv(b)%P とする
ll modinv(ll a) {
    ll b = MOD, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, k;
    cin >> m >> k;
    if (m == 1) {
        if (k == 0) {
            cout << "0 0 1 1" << endl;
        } else {
            cout << "-1" << endl;
        }
        return 0;
    }
    if (k < (1 << m)) {
        cout << k;
        for (int i = 0; i < (1 << m); ++i) {
            if (i != k) {
                cout << " " << i;
            }
        }
        cout << " " << k;
        for (int i = (1 << m)-1; i >= 0; --i) {
            if (i != k) {
                cout << " " << i;
            }
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}
