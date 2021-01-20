// 引用元 : https://atcoder.jp/contests/abc126/submissions/10044118
// 得点 : 300
// コード長 : 410
// 実行時間 : 3


#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	double N,K;
	cin >> N >> K;
	
	double ans = 0;
	
	REP(i,N){
		int temp = i;
		int count = 0;
		while(temp<K){
			count++;
			temp*=2;
		}
		ans += pow(0.5,count)/N;
	}
	
	printf("%.13f", ans);
	puts("");
	
    return 0;
}

