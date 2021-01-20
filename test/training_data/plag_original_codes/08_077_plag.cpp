// 引用元 : https://atcoder.jp/contests/agc002/submissions/5997422
// 得点 : 1600
// コード長 : 879
// 実行時間 : 122


#include <iostream>
#include <cstdio>

#define MAX_N 2010
#define MX 4000010
#define MOD 1000000007

using std::cerr;
using std::endl;

int N;
int K;
int f[MAX_N][MAX_N];
int fac[MX];
int ifac[MX];
int inv[MX];

int C(int x, int y){
	long long int ans = 1;
	ans *= fac[x];
	ans *= ifac[y];
	ans %= MOD;
	ans *= ifac[x-y];
	ans %= MOD;
	return ans;
}

int main(){
	fac[0] = 1;
	ifac[0] = 1;
	inv[1] = 1;
	for(int i = 2; i < MX; i++) 
		inv[i] = (MOD-MOD/i);
		inv[i] = 1ll * inv[i] * inv[MOD%i] % MOD;
	for(int i = 1; i < MX; i++){
		fac[i] = 1ll * fac[i-1] * i % MOD;
		ifac[i] = 1ll * ifac[i-1] * inv[i] % MOD;
	}
	scanf("%d%d", &N, &K);
	if(K == 1){
		puts("1"); return 0;
	}
	for(int i = 0; i <= N; i++) f[i][0] = 1;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= i; j++)
			long t = f[i-1][j];
			int s = (N-j+1)*(K-1)+(N-i)-1;
			t += 1ll * f[i][j-1] * C(s, K-2) % MOD
			f[i][j] = (t) % MOD;
	f[N][N] = 1ll * f[N][N] * fac[N] % MOD;
	printf("%d\n", f[N][N]);
	return 0;
}
