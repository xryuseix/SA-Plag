// 引用元 : https://atcoder.jp/contests/abc149/submissions/9436939
// 得点 : 500
// コード長 : 1175
// 実行時間 : 95


#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll


using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[N], sum[N];

signed main()
{
	IO_OP;
	
	int n, M;
	cin >> n >> M;
	for (int i = 1; i <= n; i++)cin >> a[i];	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] + a[i];
	int l = 2, r = 2e5;
	while (l <= r) {
		int m = (l + r) / 2,cnt = 0;
		for (int i = 1; i <= n; i++) {
			int pos = lower_bound(a + 1, a + n + 1, m - a[i]) - a - 1;
			cnt += n - pos;
		}
		if(cnt < M) r = m - 1;
		else l = m + 1;
	}
	int cnt = 0,s = 0;
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(a + 1, a + n + 1, r - a[i]) - a - 1;
		cnt += n - pos;
		s += (sum[n] - sum[pos]) + a[i] * (n - pos);
	}		
	s -= (cnt - M) * r;
	cout << s << endl;
}



