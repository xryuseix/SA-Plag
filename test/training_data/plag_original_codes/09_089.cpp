// 引用元 : https://atcoder.jp/contests/abc057/submissions/9437365
// 得点 : 300
// コード長 : 1424
// 実行時間 : 2


#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> primes;
vector<int> cnt;
ll ans = 1LL << 60;

vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) {
            num++;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));

    return res;
}

ll f(ll a, ll b) {
    ll cnt_a = 1;
    while (a / 10) {
        cnt_a++;
        a /= 10;
    }

    ll cnt_b = 1;
    while (b / 10) {
        cnt_b++;
        b /= 10;
    }
    return max(cnt_a, cnt_b);
}

void rec(int i) {
    if (i == primes.size()) {
        ll num1 = 1;
        ll num2 = 1;
        rep(i, cnt.size()) {
            rep(j, cnt[i]) num1 *= primes[i].first;
            rep(j, primes[i].second - cnt[i]) num2 *= primes[i].first;
        }
        chmin(ans, f(num1, num2));
        return;
    }

    rep(j, primes[i].second + 1) {
        cnt[i] = j;
        rec(i + 1);
    }
}

int main() {
    ll N;
    cin >> N;
    primes = prime_factorize(N);
    cnt.resize(primes.size());
    rec(0);
    cout << ans << endl;
}
