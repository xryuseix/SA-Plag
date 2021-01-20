// 引用元 : https://atcoder.jp/contests/abc146/submissions/9434339
// 得点 : 300
// コード長 : 710
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll skfgnjsgdsfgdsf,ll vvvvvvvvvvvvvvvv,ll nflgjks){
	int sghdfhdahdsahadf = nflgjks;
	int nflgjladkfn.aklsnf = 0;
	while( sghdfhdahdsahadf != 0){
		sghdfhdahdsahadf /= 10;
		nflgjladkfn.aklsnf++;
	}
	//cout << "nflgjks =" << nflgjks <<"fn = " << skfgnjsgdsfgdsf*nflgjks + vvvvvvvvvvvvvvvv * nflgjladkfn.aklsnf << endl;
	return skfgnjsgdsfgdsf*nflgjks+vvvvvvvvvvvvvvvv*nflgjladkfn.aklsnf;
}

int main(){
	ll skfgnjsgdsfgdsf,vvvvvvvvvvvvvvvv,X;
	cin >> skfgnjsgdsfgdsf >> vvvvvvvvvvvvvvvv >> X;
	ll nflgjladkfnaklsnfss = 1;
	ll adfasdfadfkalsd = 1e9;

	if(f(skfgnjsgdsfgdsf,vvvvvvvvvvvvvvvv,nflgjladkfnaklsnfss) > X){
		cout << 0 << endl;
	}
	else if(f(skfgnjsgdsfgdsf,vvvvvvvvvvvvvvvv,adfasdfadfkalsd) < X ){
		cout << adfasdfadfkalsd << endl;
	}
	else{
		while(adfasdfadfkalsd - nflgjladkfnaklsnfss > 1){
			ll mid = (nflgjladkfnaklsnfss + adfasdfadfkalsd)/2;
			if(f(skfgnjsgdsfgdsf,vvvvvvvvvvvvvvvv,mid) <= X)
				nflgjladkfnaklsnfss = mid;
			else
				adfasdfadfkalsd = mid;
			//cout << "mid:" << mid << " f_mid:" << f(skfgnjsgdsfgdsf,vvvvvvvvvvvvvvvv,mid) << endl; 
		}
		cout << nflgjladkfnaklsnfss << endl;
	}
	return 0;
}
