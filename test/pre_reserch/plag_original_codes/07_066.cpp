// 引用元 : https://atcoder.jp/contests/abc088/submissions/5996971
// 得点 : 300
// コード長 : 671
// 実行時間 : 1


#include <iostream>
using namespace std;

int main(){
	int ar[4][4], selisih[4];
	bool ans=true;
	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			cin >> ar[i][j];
		}
	}
	for(int i=1; i<=3; i++){
		for(int j=1; j<3; j++){
			if(i == 1){
				selisih[j] = ar[i][j] - ar[i][j+1];
			}
			else {
				if(ar[i][j]-ar[i][j+1] != selisih[j]){
					ans = false;
					break;
				}
			}
		}
	}
	for(int j=1; j<=3; j++){
		for(int i=1; i<3; i++){
			if(j == 1)
				selisih[i] = ar[i][j] - ar[i+1][j];
			else {
				if(ar[i][j] - ar[i+1][j] != selisih[i]){
					ans = false;
					break;
				}
			}
		}
	}
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
