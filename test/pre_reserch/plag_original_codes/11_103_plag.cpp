// 引用元 : https://atcoder.jp/contests/abc138/submissions/7497754
// 得点 : 500
// コード長 : 996
// 実行時間 : 8


#include <bits/stdc++.h>
     
using namespace std;

vector <long long int> idx[26];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s,t;
	long long int res = 0;
	long long int count = 0;
	int pos = 0;
	cin >> s;
	cin >> t;
	{
		int i=0;
		while(i<t.length()){
			idx[s[i]-'a'].push_back(i+1);
			i++;
		}
	}
	
	int i=0;
	while(i<t.length())
	{
		switch (idx[t[i]-'a'].size()==0)
		{
		case 1:
			cout << -1 << '\n';
			return 0;
			break;
		}
		int index = lower_bound(idx[t[i]-'a'].begin(),idx[t[i]-'a'].end(),pos+1) - idx[t[i]-'a'].begin();
		switch (index==idx[t[i]-'a'].size())
		{
		case 1:
			count++;
			index = lower_bound(idx[t[i]-'a'].begin(),idx[t[i]-'a'].end(),1) - idx[t[i]-'a'].begin();
			res = (s.length()*count) + idx[t[i]-'a'][index];
			pos = idx[t[i]-'a'][index];
			break;
		default:
			res = (s.length()*count) + idx[t[i]-'a'][index];
			pos = idx[t[i]-'a'][index];
		}
		//cout << count << ' ' << pos << ' ' << res << '\n';
		i++;
	}

	cout << res << '\n';

	return 0;
}
