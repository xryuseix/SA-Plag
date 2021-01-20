// 引用元 : https://atcoder.jp/contests/agc024/submissions/5998080
// 得点 : 300
// コード長 : 2122
// 実行時間 : 6


#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(long long i=0;i<n;i++)
#define rp(i,n) for(long long i=1;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
long long p = 1000000007;
vel rui(19, 1);
vel kai(1000007, 1);
vel ink(1000007, 1);
vel par;
int root(int ser) {
	if (par[ser] == -1) { return ser; }
	int ans = root(par[ser]);
	par[ser] = ans;
	return ans;
}
bool marge(pin a) {
	int x = root(a.first);
	int y = root(a.second);
	if (x != y) { par[x] = y; }
	return x != y;
}
int gcd(int a, int b) {
	if (a < b) { swap(a, b); }
	if (b == 0) { return a; }
	return gcd(b, a%b);
}
int ru(int a, int r) {
	if (r == 0) { return 1; }
	int ans = ru(a, r / 2);
	ans *= ans; ans %= p;
	if (r % 2 == 1) { ans *= a; ans %= p; }
	return ans;
}
int inv(int a) {
	return ru(a, p - 2);
}
void make_kai() {
	rep(i, 1000006) { kai[i + 1] = (kai[i] * (i + 1)) % p; }
	rep(i, 1000007) { ink[i] = inv(kai[i]); }
}
int com(int n, int r) {
	int ans = kai[n] * ink[r];
	ans %= p;
	return ans;
}
int nap(int n, vel napw, vel napv) {
	if (napw.size() == 0) { return 0; }
	if (napw.size() == 1) {
		return (n / napw[0])*napv[0];
	}
	if (napw.size() == 2) {
		int ans = 0;
		int lim = n / napw[0];
		rep(c0, lim + 1) {
			int c1 = (n - c0 * napw[0]) / napw[1];
			mmax(ans, c0*napv[0] + c1 * napv[1]);
		}
		return ans;
	}
	int ans = 0;
	int ex;
	int lim = n / napw[0];
	int nlim;
	rep(c0, lim + 1) {
		ex = n - c0 * napw[0];
		nlim = ex / napw[1];
		rep(c1, nlim + 1) {
			int c2 = (ex - c1 * napw[1]) / napw[2];
			mmax(ans, c0*napv[0] + c1 * napv[1] + c2 * napv[2]);
		}
	}
	return ans;
}
signed main() {
	int a, b, c, k; cin >> a >> b >> c >> k;
	if (k % 2 == 0) { cout << a - b << endl; }
	else { cout << b - a << endl; }
	return 0;
}
