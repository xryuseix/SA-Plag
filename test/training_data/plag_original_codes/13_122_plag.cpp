// 引用元 : https://atcoder.jp/contests/agc035/submissions/6378646
// 得点 : 700
// コード長 : 829
// 実行時間 : 21


#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n,i, t;
	
	scanf("%d", &n);
	
	if(n <= 2 || ((~n & 1) && (n & n - 1) == 0)){
		printf("No\n");
		return 0;
	}
	
	printf("Yes\n");
	
	if(n % 2){
		printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n", n + 1, n + 1, n + 2, n + 2, n + 3);
		
		for(i=4; i<n; i+=2){
			printf("1 %d\n%d %d\n1 %d\n%d %d\n", i, i, i + 1, n + i + 1, n + i + 1, n + i);
		}
	}
	
	if(~n & 1){
		t = (n & -n);
		
		for(i=2; i<n; i+=2){
			if(i == t){
				printf("1 %d\n%d %d\n%d %d\n%d %d\n%d %d\n", i, i, i + 1, i + 1, n + 1, n + 1, n + i, n + i, n + i + 1);
			}
			else{
				printf("1 %d\n%d %d\n1 %d\n%d %d\n", i, i, i + 1, n + i + 1, n + i + 1, n + i);
			}
		}
		
		printf("%d %d\n%d %d\n", n, n * 2 - t + 1, t, n * 2);
	}
	
	return 0;
}
