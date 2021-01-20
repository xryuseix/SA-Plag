// 引用元 : https://atcoder.jp/contests/abc126/submissions/9431235
// 得点 : 300
// コード長 : 1035
// 実行時間 : 2


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cout << setprecision(11) << fixed;
	
	const int maxn = 1e5 + 7;
	
	vector<double> p(maxn);
	p[0] = 1.0;
	for(int i = 1; i < maxn; i++)
		p[i] = p[i - 1] * 0.5;
	
	int n, k;
	cin >> n >> k;
	
	double ans = 0.0;
	
	double prob = 1.0 / n;

	for(int i = 1; i <= n; i++){
		int cur = i;
		int steps = 0;
		while(cur < k){
			cur *= 2;
			steps++;
		}
		ans += prob * p[steps];
	}
	
	cout << ans << endl;

	return 0;
}
