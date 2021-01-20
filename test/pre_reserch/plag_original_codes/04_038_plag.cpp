// 引用元 : https://atcoder.jp/contests/abc114/submissions/5715429
// 得点 : 400
// コード長 : 541
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int num(int m,vector<int>& w,int M){
	int res = 0;
	for(int j=2;j<=M;j++)if(w[j]>=m-1)res++;
	return res;
}

int main(void){
	int M;cin>>M;
	vector<int> w(M+1,0);
	for(int j=2;j<=M;j++){
		int c = j;
		for(int i=2;i<=j;i++){
			while(c %i==0){
				w[i]++;
				c/=i;
			}
		}
	}
	int ans = 0;
	ans += num(75,w,M) + num(15,w,M)*(num(5,w,M)-1) +num(25,w,M)*(num(3,w,M)-1)
	+ num(5,w,M)*(num(5,w,M)-1)*(num(3,w,M)-2) /2 ;
	cout << ans << endl;
}
