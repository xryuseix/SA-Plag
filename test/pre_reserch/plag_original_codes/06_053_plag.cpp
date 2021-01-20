// 引用元 : https://atcoder.jp/contests/abc057/submissions/9437398
// 得点 : 300
// コード長 : 1319
// 実行時間 : 2


#include <bits/stdc++.h>

using namespace std;
#define chmax(x, y) x = max(x, y)
vector<pair<ll, ll>> primes;
#define chmin(x, y) x = min(x, y)
typedef long long ll;
ll ans = 1LL << 60;
vector<int> cnt;
#define rep(i, n) for(int i = 0; i<(n); i++)



void rec(int i) {
    if (i == primes.size()) {
        ll num2 = 1;
        ll num1 = 1;
        rep(i, cnt.size()) {
            rep(j, primes[i].second - cnt[i]) num2 *= primes[i].first;
            rep(j, cnt[i]) num1 *= primes[i].first;
        }
        chmin(ans, f(max(num1, num2)));
        return;
    }

    rep(j, primes[i].second + 1) {
        cnt[i] = j;
        rec(i + 1);
    }
}
ll f(ll n) {
    ll cnt = 1;
    while (n / 10) {
        cnt++;
        n /= 10;
    }
    return cnt;
}


vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) {
            n /= p;
            num++;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));

    return res;
}
int main() {
    ll N;
    cin >> N;
    primes = prime_factorize(N);
    cnt.resize(primes.size());
    rec(0);
    cout << ans << endl;
}
