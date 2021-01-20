// 引用元 : https://atcoder.jp/contests/agc033/submissions/8565208
// 得点 : 800
// コード長 : 1285
// 実行時間 : 78


// copied by Nurstan Duisengaliev
// skatal
#include <bits/stdc++.h>
 
#define ll long long
#define all(x) x.begin(), x.end()
#define in insert
#define mp make_pair
#define F first
#define S second
#define ppf pop_front
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair <int, int>
#define boost() ios_base::sync_with_stdio(0), cin.tie(0)
#define sz(x) x.size()
 
using namespace std;
 
const int N = (int)2e5 + 123;
const int mod = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;	
int d[N], maxi = 0, dp[N];
vector <int> g[N];
void dfs (int v, int p) {
	for (auto to : g[v]) {
		if (to != p) {
			dfs (to, v);
			maxi = max (maxi, d[v] + d[to] + 1);
			d[v] = max (d[v], d[to] + 1);            
		}
	}	
}
void solve () {
	int n;
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int l, r;
		cin >> l >> r;
		g[l].pb (r);
		g[r].pb (l);
	}
	dfs (1, -1);
	maxi ++;
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 2; i <= maxi; i ++) {
		if (dp[i - 1] == 0 || dp[i - 2] == 0) {
			dp[i] = 1;
		}	
		else {
			dp[i] = 0;
		}
	}
	if (dp[maxi] == 1) cout << "First";
	else cout << "Second";
}                         	
 
main () {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
	boost ();
	int TT = 1;
//	cin >> TT;
	while (TT --) {
		solve ();
	}
	return 0;	
}
