// 引用元 : https://atcoder.jp/contests/abc155/submissions/10701509
// 得点 : 400
// コード長 : 2178
// 実行時間 : 501


#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

vector<int>neg;
vector<int>pos;
int zeros = 0;

ll count(ll mid)
{
	ll result = 0;
	if(mid >= 0)
	{
		result = 1ll * pos.size() * neg.size() + 1ll * zeros * (pos.size() + neg.size()) + 1ll * zeros * (zeros - 1) / 2;
	}
	else
	{
		if(neg.size() > 0 && pos.size() > 0)
		for(int i = 0; i < neg.size(); i++)
		{
			int lo = 0, hi = pos.size() - 1;
			while(lo + 1 < hi)
			{
				int m = (lo + hi) / 2;
				ll p = 1ll * pos[m] * neg[i];
				if(p > mid) lo = m + 1;
				else hi = m;
			}
			if(1ll * neg[i] * pos[lo] <= mid) result += pos.size() - lo;
			else if(1ll * neg[i] * pos[hi] <= mid) result += pos.size() - hi;
		}
	}
	if(mid > 0)
	{
		if(neg.size() > 1)
		for(int i = 0; i < neg.size() - 1; i++)
		{
			int lo = i + 1, hi = neg.size() - 1;
			while(lo + 1 < hi)
			{
				int m = (lo + hi) / 2;
				ll p = 1ll * neg[i] * neg[m];
				if(p > mid) hi = m - 1;
				else lo = m; 
			}
			if(1ll * neg[hi] * neg[i] <= mid) result += hi - i;
			else if(1ll * neg[lo] * neg[i] <= mid) result += lo - i;
		}
		if(pos.size() > 1)
        for(int i = 0; i < pos.size() - 1; i++)
        {
            int lo = i + 1, hi = pos.size() - 1;
            while(lo + 1 < hi)
            {
                int m = (lo + hi) / 2;
                ll p = 1ll * pos[i] * pos[m];
                if(p > mid) hi = m - 1;
                else lo = m;
            }
			if(1ll * pos[hi] * pos[i] <= mid) result += hi - i;
			else if(1ll * pos[lo] * pos[i] <= mid) result += lo - i;
        }
	}
	return result;	
}

int main()
{
	int N, x;
	ll K;	
	scanf("%d%lld", &N, &K);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		if(x < 0) neg.push_back(x);
		else if(x == 0) zeros++;
		else pos.push_back(x);
	}
	sort(neg.begin(), neg.end(), greater<int>());
	sort(pos.begin(), pos.end());
	ll lo = -1e18, hi = 1e18;
	while(lo < hi)
	{
		ll mid = lo < 0 ? (lo + hi - 1) / 2 : (lo + hi) / 2;
		ll cnt = count(mid);
		if(cnt >= K) hi = mid;
		else lo = mid + 1;	 
	}
	cout << lo << endl;
}
