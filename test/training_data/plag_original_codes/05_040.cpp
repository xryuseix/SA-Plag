// 引用元 : https://atcoder.jp/contests/abc127/submissions/6433544
// 得点 : 300
// コード長 : 525
// 実行時間 : 17


#include<bits/stdc++.h>
using namespace std;

#define int  long long
#define pb emplace_back
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define F first
#define S second
#define fast ios:: sync_with_stdio(false),cin.tie(0);

int32_t main(){
	fast;
	int n,m;
	cin >> n >> m;
	int gate = m;
	int a[100005]= {0};
	
	while(m--)
	{
		int x,y;
		cin >> x >> y;
		a[x]++;
		a[y+1]--;
	}
	f(i,1,100005)   a[i] += a[i-1];
	int ans = 0;
	f(i,0,100005)   ans += (a[i] == gate);
	
	cout << ans;

}





