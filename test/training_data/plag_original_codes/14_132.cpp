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


ll gcd(ll a, ll b) {
		if (b == 0) return a;
		gcd(b, a%b);
}

ll lcm(ll a, ll b) {
		ll g = gcd(a, b);
		return a / g * b;
}

int main() {
		int N;
		cin >> N;
		ll T[N];
		for (int i = 0; i < N; i++) {
				cin >> T[i];
		}

		ll ans = 1LL;
		for (int i = 0; i < N; i++) {
				ans = lcm(ans, T[i]);	
		}

		cout << ans << endl;

		return 0;
}
