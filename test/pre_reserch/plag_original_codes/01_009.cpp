// 引用元 : https://atcoder.jp/contests/abc061/submissions/5997462
// 得点 : 300
// コード長 : 427
// 実行時間 : 90


#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<long long int,long long int> cnt;
  	long long int n,q;
  	cin>>n>>q;
  	long long int x,y;
  	for(long long int i=0 ; i<n ; ++i)
    {
    	cin>>x>>y;
    	cnt[x]+=y;
    }
  	for(auto &i:cnt)
    {
    	if(i.second>=q)
        {
        	cout<<i.first<<endl;
            return 0;
        }  
      	q-=i.second;
    }
  	return 0;
}
 
