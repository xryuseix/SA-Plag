// 引用元 : https://atcoder.jp/contests/abc127/submissions/6438124
// 得点 : 600
// コード長 : 2022
// 実行時間 : 148


//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pil pair<int, long long>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vil vector<pil>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e6 + 5;
const double eps = 1e-9;
multiset<ll> med1, med2;

int main() {
	int q, cnt=0; ni(q);
	ll bsm = 0, lo = 0, hi = 0;
	while (q--) {
		int t; ni(t);
		if (t == 1) {
			ll a, b; scanf("%lld %lld", &a, &b);
			cnt++;
			bsm += b;
			if (med1.empty() || a <= *med1.rbegin()) {
				lo += a;
				med1.insert(a);
			} else {
				hi += a;
				med2.insert(a);
			}
			while (med1.size() > med2.size() + 1) {
				lo -= *med1.rbegin();
				hi += *med1.rbegin();
				med2.insert(*med1.rbegin());
				med1.erase(--med1.end());
			}
			while (med2.size() > med1.size()) {
				lo += *med2.begin();
				hi -= *med2.begin();
				med1.insert(*med2.begin());
				med2.erase(med2.begin());
			}
		} else {
			printf("%lld %lld\n", *med1.rbegin(), bsm + hi - lo + (ll)((ll)med1.size() - (ll)med2.size()) * *med1.rbegin());
		}
	}
    return 0;
}
