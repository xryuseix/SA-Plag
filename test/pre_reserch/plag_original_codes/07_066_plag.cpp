// 引用元 : https://atcoder.jp/contests/abc088/submissions/5996971
// 得点 : 300
// コード長 : 671
// 実行時間 : 1


#include <iostream>
using namespace std;
using ll=long;
template <typename T>
class WAR_FLY {
public:
	vector<vector<T>> d; // 辺の数
	int V; // 頂点の数
	
	WAR_FLY(int n) {
		V = n;
		d = vector<vector<T> > (n,vector<T>(n));
		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				if(i == j) {
					d[i][j] = 0;
				}
				else {
					d[i][j] = 1LL<<60;
				}
			}
		}
	}

	void warshall_floyd(void) {
		for(int k = 0; k < V; k++) {
			for(int i = 0; i < V; i++) {
				for(int j = 0; j < V; j++) {
					d[i][j] = min((ll)d[i][j], (ll)d[i][k] + (ll)d[k][j]);
				}
			}
		}
	}

	void add(int from, int to, T cost) {
		d[from][to] = cost;
	}

	bool is_negative_loop(void) {
		for(int i = 0; i < V; i++) {
			if(d[i][i] < 0) return true;
		}
		return false;
	}

	void show(void) {
		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				cout << d[i][j] << " ";
			}
			cout << endl;
		}
	}
};
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
