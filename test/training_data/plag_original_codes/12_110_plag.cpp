// 引用元 : https://atcoder.jp/contests/abc086/submissions/5998318
// 得点 : 300
// コード長 : 660
// 実行時間 : 74


#include <bits/stdc++.h>

using namespace std;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)


int main(void){

	int N; cin >> N;
	vector<int> t(N+1),x(N+1),y(N+1);
	t[0] = x[0] = y[0] = 0;
	FOR(i,1,N+1) cin >> t[i] >> x[i] >> y[i];


	FOR(i,1,N+1){
		int dt = t[i] - t[i-1];
		int dx = abs(x[i] - x[i-1]);
		int dy = abs(y[i] - y[i-1]);

		if(dx+dy <= dt and (dx+dy)%2 == dt %2) continue;
		else{ 
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
