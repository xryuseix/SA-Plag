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

int N, K, f[MAX_N][MAX_N];
int fac[MX], ifac[MX], inv[MX];

int C(int x, int y){
	return 1ll * fac[x] * ifac[y] % MOD* ifac[x-y] % MOD;
}

int main(){
	fac[0] = ifac[0] = inv[1] = 1;
	for(int i = 2; i < MX; i++) 
		inv[i] = 1ll * (MOD-MOD/i) * inv[MOD%i] % MOD;
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
			f[i][j] = (f[i-1][j] + 1ll * f[i][j-1] * C((N-j+1)*(K-1)+(N-i)-1, K-2) % MOD) % MOD;
	f[N][N] = 1ll * f[N][N] * fac[N] % MOD;
	printf("%d\n", f[N][N]);
	return 0;
}
