// 引用元 : https://atcoder.jp/contests/abc122/submissions/5996591
// 得点 : 300
// コード長 : 786
// 実行時間 : 26


#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-7
#define inf 0x3f3f3f3f
#define mod 1000000007ll
using namespace std;

int main() {
	speed;
	int n, q, l, r;
	string s;
	cin >> n >> q >> s;
	vector<int>v(n), p(n);
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == 'A' && s[i + 1] == 'C')
			v[i] = 1;
		p[i] = (i ? p[i - 1] : 0) + v[i];
	}
	for (int i = 0; i < q; ++i) {
		cin >> l >> r;
		--l, --r;
		cout << p[r - 1] - (l - 1 >= 0 ? p[l - 1] : 0) << '\n';
	}
}
