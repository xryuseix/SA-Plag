// 引用元 : https://atcoder.jp/contests/abc128/submissions/5996654
// 得点 : 400
// コード長 : 1373
// 実行時間 : 3


#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;

ll v[55];

ll dp[55][55][105];

ll solve(int l, int r, int x){
	if(x < 0) return -1e9;
	if(x == 0 || l > r) return 0;
	if(dp[l][r][x] != -1) return dp[l][r][x];
	ll op1 = solve(l + 1, r, x - 1) + v[l];
	ll op2 = solve(l, r - 1, x - 1) + v[r];
	ll op3 = solve(l + 1, r, x - 2);
	ll op4 = solve(l, r - 1, x - 2);
	ll op5 = 0;
	ll ret = max({op1, op2, op3, op4, op5});
	return dp[l][r][x] = ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	rep(i, n) cin >> v[i];
	cout << solve(0, n - 1, k) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
