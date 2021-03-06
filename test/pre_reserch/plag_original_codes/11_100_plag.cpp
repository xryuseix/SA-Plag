// 引用元 : https://atcoder.jp/contests/agc009/submissions/7713431
// 得点 : 1100
// コード長 : 1004
// 実行時間 : 18


//Love and Freedom.
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define inf 20021225
#define N 100010
#define mdn 1000000007
using namespace std;
int read()
{
	int s=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return f*s;
}
void upd(int &x,int y){x+=x+y>=mdn?y-mdn:y;}
int pre[N],n,f[N]; ll a[N],A,B;
int get(int l,int r)
{
	if(l>r)	return 0;
	return !l?pre[r]:(pre[r]-pre[l-1]+mdn)%mdn;
}
int main()
{
	int n=read(); scanf("%lld%lld",&A,&B);
	if(A<B)	swap(A,B);
	
	{
		int i;	
		while(i<=n){
			scanf("%lld",&a[i]);
			i++;	
		}
	}
	pre[0]=f[0]=1; int l=0,r=0;
	a[0]=-1e18; a[n+1]=(2e18)+1;
	{
		int i=1;
		while(i<=n+1)
		{
			while(r<i&&a[i]>=a[r]+A)	r++; r--;
			switch (a[i]-a[i-1]>=A)
			{
			case 1:
				f[i]=f[i-1];
				break;
			default:
				break;
			}
			
			upd(f[i],get(l,min(r,i-2)));
			pre[i]=pre[i-1];
			switch (a[i+1]-a[i-1]>=B)
			{
			case 1:
				upd(pre[i],f[i]);
				break;
			default:
				break;
			}
			switch (a[i]-a[i-1]<B)
			{
			case 1:
				l=i-1;
				break;
			default:
				break;
			}
		}
	}
	printf("%d\n",f[n+1]);
	return 0;
}
