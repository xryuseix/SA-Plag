// 引用元 : https://atcoder.jp/contests/abc146/submissions/9434339
// 得点 : 300
// コード長 : 710
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll A,ll B,ll N){
	int n_sub = N;
	int dn = 0;
	while( n_sub != 0){
		n_sub /= 10;
		dn++;
	}
	//cout << "N =" << N <<"fn = " << A*N + B * dn << endl;
	return A*N+B*dn;
}

int main(){
	ll A,B,X;
	cin >> A >> B >> X;
	ll n_low = 1;
	ll n_high = 1e9;

	if(f(A,B,n_low) > X){
		cout << 0 << endl;
	}
	else if(f(A,B,n_high) < X ){
		cout << n_high << endl;
	}
	else{
		while(n_high - n_low > 1){
			ll mid = (n_low + n_high)/2;
			if(f(A,B,mid) <= X)
				n_low = mid;
			else
				n_high = mid;
			//cout << "mid:" << mid << " f_mid:" << f(A,B,mid) << endl; 
		}
		cout << n_low << endl;
	}
	return 0;
}
