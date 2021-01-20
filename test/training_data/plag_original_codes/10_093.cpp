// 引用元 : https://atcoder.jp/contests/agc031/submissions/7713443
// 得点 : 700
// コード長 : 896
// 実行時間 : 776


#include	<bits/stdc++.h>
using	namespace	std;

bool	CMP1(vector<int> A, vector<int> B) {
	if (A.at(1)==B.at(1))
		return (A.at(0)<=B.at(0));
	return (A.at(1)<=B.at(1));
}

int	main() {
	const long MOD=1000000007;
	int N;
	cin >>N;
	vector<vector<int>> C(N, vector<int> (3, 0));
	for (int i=0; i<N; i++) {
		C.at(i).at(0)=i;
		cin >>C.at(i).at(1);
	}
	sort(C.begin(), C.end(), CMP1);
	C.at(0).at(2)=-1;
	for (int i=1; i<N; i++) {
		if(C.at(i).at(1)==C.at(i-1).at(1))
			C.at(i).at(2)=C.at(i-1).at(0);
		else
			C.at(i).at(2)=-1;
	}
	sort(C.begin(), C.end());
	vector<long> S0(N, 0);
	S0.at(0)=1;
	for (int i=1; i<N; i++) {
		if (-1==C.at(i).at(2)) {
			S0.at(i)=S0.at(i-1);
		} else if (i-1==C.at(i).at(2)) {
			S0.at(i)=S0.at(i-1);
		} else {
			S0.at(i)=S0.at(i-1)+S0.at(C.at(i).at(2));
			S0.at(i) %=MOD;
		}
	}
	cout <<S0.at(N-1) <<endl;
	return 0;
}
