// 引用元 : https://atcoder.jp/contests/agc043/submissions/11160310
// 得点 : 700
// コード長 : 637
// 実行時間 : 38


#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define F first
#define S second

const int maxn = 1e6 + 12;
int a[maxn], n, C = 0, ans;
string s;

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0' - 1;
		if(!C && a[i] == 1) C = 1;
	}
	for (int i = 0; i < n; i++) if(C) a[i] %= 2;
	for (int i = 0; i < n; i++) if(((n - 1) & i) == i) ans ^= a[i];
	cout << ans;
	return 0;
}	
