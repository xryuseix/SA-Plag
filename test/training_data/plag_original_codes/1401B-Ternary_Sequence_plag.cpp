#include <algorithm>
#include <iostream>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int a[3], b[3];
        rep(i, 3) cin >> a[i];
        rep(i, 3) cin >> b[i];
        ll ans = 0;
        ans += min(a[2], b[1]) << 1;
        b[1] -= ans >> 1;
        a[2] -= ans >> 1;

        int t = min(a[0], b[2]);
        b[2] -= t;
        a[0] -= t;

        t = min(a[2], b[2]);
        b[2] -= t;
        a[2] -= t;

        t = min(a[1], b[2]);
        ans -= 2 * t;
        b[2] -= t;
        a[1] -= t;

        cout << ans << endl;
    }
}
