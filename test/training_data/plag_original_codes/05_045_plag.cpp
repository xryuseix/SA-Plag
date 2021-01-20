// 引用元 : https://atcoder.jp/contests/abc121/submissions/12412105
// 得点 : 300
// コード長 : 553
// 実行時間 : 77


#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using ll = long long ;
using ld=long double;
using d= double;

int main() {
	int n,m;
	cin>>n>>m;
	vector<pair<ll,ll>> p(n);
	for(int i=0;i<n;i++){
	    cin>>p[i].first>>p[i].second;
	}
    sort(p.begin(),p.end());
	lli ans=0;
	for(int i=0;i<n;i++){
	    if(m>=p[i].second){
	        ans+=p[i].first*p[i].second;
	        m-=p[i].second;
	    }
	    else if(m<p[i].second){
	        ans+=m*p[i].first;
	        m=0;
	    }
	}
	cout<<ans; 
	return 0;
}
