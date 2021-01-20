// 引用元 : https://atcoder.jp/contests/abc095/submissions/5997679
// 得点 : 500
// コード長 : 1233
// 実行時間 : 26


#include <bits/stdc++.h>
using namespace std;
//---define tricks---
#define ALL(v) v.begin(),v.end()
#define UN(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(x,y) memset(x,y,sizeof(x))
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define revsort(b,e) sort(b,e),reverse(b,e)
//---define types---
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
//---define variables---
ll n,c,x[100005],v[100005];
ll a[100005],b[100005],ans=0;
//---define function---

//---main code---
int main()
{
	FIO;
	cin>>n>>c;
	for(ll i=1;i<=n;++i)
	{
		cin>>x[i]>>v[i];
	}
	x[n+1]=c;
	for(ll i=1;i<=n;++i)
	{
		a[i]=a[i-1]+v[i]-(x[i]-x[i-1]);
	}
	for(ll i=1;i<=n;++i)
	{
		a[i]=max(a[i-1],a[i]);
	}
	for(ll i=n;i>=1;--i)
	{
		b[i]=b[i+1]+v[i]-(x[i+1]-x[i]);
	}
	for(ll i=n;i>=1;--i)
	{
		b[i]=max(b[i+1],b[i]);
	}
	for(ll i=1;i<=n;++i)
	{
		ans=max(ans,a[i]);
		ans=max(ans,a[i]-x[i]+b[i+1]);
		ans=max(ans,b[i]);
		ans=max(ans,b[i]-(c-x[i])+a[i-1]);
	}
	cout<<ans<<'\n';
	return 0;
}

