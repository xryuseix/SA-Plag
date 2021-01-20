// 引用元 : https://atcoder.jp/contests/abc161/submissions/12412137
// 得点 : 600
// コード長 : 1109
// 実行時間 : 22


#include<iomanip>
#include<utility>

constexpr long long MOD = 1'000'000'007; 
using namespace std;

#define int long long
#define endl "\n"
constexpr long long INF = (long long)1e18;
#include<algorithm>
#include<cmath>
struct fast_io {
	fast_io(){
		std::cin.tie(nullptr);
		std::ios::sync_with_stdio(false);
	};
} fio;

#include<vector>
#include<iostream>
#include<string>


signed main(){
	cout<<fixed<<setprecision(10);
	
	int N;
	int con = 0;
	
	cin>>N;
	
	for(int i = 2; i * i <= N; i++){
		if(N%i == 0) {
			if(i * i == N) {
				{
					int n = N, j = i;
					
					while(n%j == 0){
						n /= j;
					}
					if(n%j == 1) con++;
				}
			} else {
				{
					int n = N, j = i;
					
					while(n%j == 0){
						n /= j;
					}
					if(n%j == 1) con++;
				}
				
				{
					int n = N, j = N/i;
					
					while(n%j == 0){
						n /= j;
					}
					if(n%j == 1) con++;
				}
			}
		}
		
		
	}
	
	
	for(int i = 1; i * i <= N-1; i++){
		if((N-1)%i == 0) {
			if(i * i != N-1) con++;
			con++;
		}
	}
	cout<<con<<endl;
	
	return 0;
}
