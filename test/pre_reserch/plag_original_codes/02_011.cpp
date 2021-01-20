// 引用元 : https://atcoder.jp/contests/abc137/submissions/6820829
// 得点 : 300
// コード長 : 507
// 実行時間 : 270


#include<bits/stdc++.h>
using namespace std;
int n,a[26];
long long ans;
char s[20];
map <string,long long> mapp;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		string str="";
		for(int j=0;j<=25;j++) a[j]=0;
		for(int j=0;j<10;j++) a[int(s[j]-'a')]++;
		for(int j=0;j<=25;j++)
			str=str+char(a[j]-49);
		mapp[str]++;
	}
	map <string,long long> :: iterator it;
	for(it=mapp.begin();it!=mapp.end();it++)
		ans+=(it->second)*((it->second)-1)/2;
	cout<<ans;
	return 0;
}
