// 引用元 : https://atcoder.jp/contests/agc035/submissions/6378695
// 得点 : 700
// コード長 : 943
// 実行時間 : 38


#include<cstdio>
using namespace std;
int tot,m,n,TT;
int wz[234234],rdt[234234],rd[234234],pd[234234],b[234234],sz[234234],dfn[234234];

void cnct(int x,int y)
{
	rd[++tot]=x,rdt[tot]=wz[y],wz[y]=tot;
	rd[++tot]=y,rdt[tot]=wz[x],wz[x]=tot;
}

void dfs(int x,int from)
{
  int t=wz[x];
  b[x]=1,dfn[x]=++TT;
  while(t)
    {
    	if(rd[t]!=from)
    	{
      if(b[rd[t]])
      {
      	if(dfn[rd[t]]<dfn[x])
	    sz[x]++,pd[t]=1;
	  }
	else
	{
		dfs(rd[t],x);
	  if(sz[rd[t]]%2!=0) 
	   {
	   	if(t%2==0) pd[t-1]=1;
	    else pd[t+1]=1;
	   }
	  else sz[x]++,pd[t]=1;
	  }
	}
	  t=rdt[t];
	}
}

int main()
{
int i,x,y;
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++) 
    {
	  scanf("%d%d",&x,&y);
	  cnct(x,y);
	}
  dfs(1,0); 
  if(sz[1]%2!=0) {printf("-1\n");return 0;}
  for(i=1;i<=m*2;i+=2)
    {
	  if(pd[i]) printf("%d %d\n",rd[i+1],rd[i]);
	  else printf("%d %d\n",rd[i],rd[i+1]);
	}
}
