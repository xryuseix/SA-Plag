// 引用元 : https://atcoder.jp/contests/abc070/submissions/5998435
// 得点 : 300
// コード長 : 560
// 実行時間 : 1


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define ALL(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a,   b) * b;}

int main() {
		int N;
		cin >> N;
		vector<ll> T(N);
		rep(i,N)cin >> T[i];

		ll ans = 1LL;
		rep(i,N){
			ans = lcm(ans, T[i]);	
		}

		cout << ans << endl;

		return 0;
}
