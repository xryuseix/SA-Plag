// 引用元 : https://atcoder.jp/contests/agc025/submissions/6479154
// 得点 : 700
// コード長 : 1574
// 実行時間 : 57


#include <bits/stdc++.h>
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define vii vector<pii>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
const double pi = acos(-1);
const int MOD = 998244353;
const int INF = 1e9 + 7;
const int MAXN = 3e5 + 5;
const double eps = 1e-9;
using namespace std;
ll fac[MAXN], inv[MAXN];

ll bin(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b /= 2ll;
    }
    return ret;
}

ll ncr(int n, int k) {
    if (k > n || k < 0) return 0;
    return (fac[n] * inv[k] % MOD) * inv[n-k] % MOD;
}

int main() {
    fac[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        inv[i] = bin(fac[i], MOD - 2);
    ll n, a, b, k;
    nl(n), nl(a), nl(b), nl(k);
    ll ans = 0;
    if (k % __gcd(a, b) != 0)
        return !pri(0);
    for (ll x = 0; x <= n; x++) {
        if ((k - x * a) % b != 0)
            continue;
        ll y = (k - x * a) / b;
        ans = (ans + ncr(n, x) * ncr(n, y) % MOD) % MOD;
    }
    prl(ans);
    return 0;
}
