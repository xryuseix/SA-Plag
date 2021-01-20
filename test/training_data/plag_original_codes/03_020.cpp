// 引用元 : https://atcoder.jp/contests/abc130/submissions/5960548
// 得点 : 300
// コード長 : 675
// 実行時間 : 1


#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = (long long)1e9 + 7; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}

#define MAX

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(12);
	
	int W, H, x, y;
	
	cin>>W>>H>>x>>y;
	
	cout<<(((long  double)W*H/2))<<" ";
	if(H-y == y && W-x == x) cout<<1;
	else cout<<0;
	cout<<endl;
	
	return 0;
}
