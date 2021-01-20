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

	for(int i=0;i<s.length();i++)
	{
		idx[s[i]-'a'].push_back(i+1);
	}

	for(int i=0;i<t.length();i++)
	{
		if(idx[t[i]-'a'].size()==0)
		{
			cout << -1 << '\n';
			return 0;
		}
		int index = lower_bound(idx[t[i]-'a'].begin(),idx[t[i]-'a'].end(),pos+1) - idx[t[i]-'a'].begin();
		if(index==idx[t[i]-'a'].size())
		{
			count++;
			index = lower_bound(idx[t[i]-'a'].begin(),idx[t[i]-'a'].end(),1) - idx[t[i]-'a'].begin();
			res = (s.length()*count) + idx[t[i]-'a'][index];
			pos = idx[t[i]-'a'][index];
		}
		else
		{
			res = (s.length()*count) + idx[t[i]-'a'][index];
			pos = idx[t[i]-'a'][index];
		}
		//cout << count << ' ' << pos << ' ' << res << '\n';
	}

	cout << res << '\n';

	return 0;
}
