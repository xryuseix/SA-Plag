// 引用元 : https://atcoder.jp/contests/abc148/submissions/9434367
// 得点 : 400
// コード長 : 363
// 実行時間 : 81


#include<bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	int dileu = 0;
	int cownter = 1;
	for(int i = 0; i < N; i++){
		int rhif; 
		cin >> rhif;
		if(rhif != cownter){
			dileu++;
			continue;
		}
		cownter++;
	}
	
	if(dileu == N)
		cout << "-1";
	else
		cout << dileu;
	cout << '\n';
	return 0;
}
