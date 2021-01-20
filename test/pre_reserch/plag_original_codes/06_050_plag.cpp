// 引用元 : https://atcoder.jp/contests/abc156/submissions/11735540
// 得点 : 500
// コード長 : 2179
// 実行時間 : 50


#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker, "/stack:200000000"]
 
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <chrono>
#include <set>
using namespace std;
#include <map>
#include <queue>
#include <deque>
#define fl(i, l, n) for (int i = l; i < n; ++i)
#define ld long double
#include <random>
#define sz(a) (int)a.size()
#include <sstream>

#define se second
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define hm unordered_map 


#ifdef __LOCAL
	#define dbg(x) cerr << #x << " : " << x << '\n'
	const int maxn = 20;
#else 
	#define dbg(x)
	const int maxn = 2e5 + 20;
#endif
#define ll long long
#include <unordered_map>
#include <bitset>
const ll inf = (ll) 2e9;
const ld pi = asin (1) * 2;
const ld eps = 1e-8;
const ll mod = (ll)1e9 + 7;
#define cinv(v) for (auto& x: v) cin >> x
#include <stack>
#define pii pair<int, int>
#include <fstream>
#define all(a) a.begin(), a.end()
#define fi first

#define int ll

//tg: @galebickosikasa
 

const ll ns = 97;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());


ll inv (int a) {
	return powmod (a, mod - 2);
}
ll powmod (ll a, ll n) {
	if (n == 0) return 1;
	if (n % 2) return mult (a, powmod (a, n - 1));
	ll b = powmod (a, n / 2);
	return mult (b, b);
}

ll mult (ll a, ll b) {
	return a * b % mod;
}


int f[maxn], rev[maxn];

int C (int n, int k) {
	if (k == 0 || n == k) return 1;
	return mult (f[n], mult (rev[k], rev[n - k]));
}

ll add (ll a, ll b) {
	int c = a + b;
	if (c >= mod) c -= mod;
	return c;
}


signed main () {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	f[0] = 1;
	fl (i, 1, maxn) {
		f[i] = mult (f[i - 1], i);
		rev[i] = inv (f[i]);
	}
	int n, k;
	cin >> n >> k;
	k = min (k, n - 1);
	int ans = 0;
	fr (i, k + 1) {
		ans = add (ans, mult (C (n, i), C (n - 1, n - i - 1)));
		dbg (ans);
	}
	cout << ans;







}
