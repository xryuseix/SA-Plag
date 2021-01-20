// 引用元 : https://atcoder.jp/contests/abc114/submissions/3710213
// 得点 : 300
// コード長 : 460
// 実行時間 : 2


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ans;
ll n;

void dfs(ll cur) {
	if (cur<=n) {
		ll tmp=cur;
		int ok1=0, ok2=0, ok3=0;
		while(tmp) {
			int t=tmp%10;
			ok1|=(t==3);
			ok2|=(t==5);
			ok3|=(t==7);
			tmp/=10;
		}
		if (ok1&&ok2&&ok3) ans++;
	}
	else return; 
	dfs(cur*10+3);
	dfs(cur*10+5);
	dfs(cur*10+7);
}

int main() {
	scanf("%lld", &n);
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
