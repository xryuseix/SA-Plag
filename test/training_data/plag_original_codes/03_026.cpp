// 引用元 : https://atcoder.jp/contests/abc148/submissions/9434367
// 得点 : 400
// コード長 : 363
// 実行時間 : 81


#include<bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	int deleted = 0;
	int counter = 1;
	for(int i = 0; i < N; i++){
		int number; 
		cin >> number;
		if(number != counter){
			deleted++;
			continue;
		}
		counter++;
	}
	
	if(deleted == N)
		cout << "-1";
	else
		cout << deleted;
	cout << '\n';
	return 0;
}
