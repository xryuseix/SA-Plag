// 引用元 : https://atcoder.jp/contests/abc114/submissions/5715429
// 得点 : 400
// コード長 : 541
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int num(int m,vector<int>& v,int N){
	int res = 0;
	for(int i=2;i<=N;i++)if(v[i]>=m-1)res++;
	return res;
}

int main(void){
	int N;cin>>N;
	vector<int> v(N+1,0);
	for(int i=2;i<=N;i++){
		int cur = i;
		for(int j=2;j<=i;j++){
			while(cur %j==0){
				v[j]++;
				cur/=j;
			}
		}
	}
	int ans = 0;
	ans += num(75,v,N) + num(15,v,N)*(num(5,v,N)-1) +num(25,v,N)*(num(3,v,N)-1)
	+ num(5,v,N)*(num(5,v,N)-1)*(num(3,v,N)-2) /2 ;
	cout << ans << endl;
}
