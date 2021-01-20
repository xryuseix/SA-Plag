// 引用元 : https://atcoder.jp/contests/abc126/submissions/10044149
// 得点 : 600
// コード長 : 985
// 実行時間 : 25


#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	ll M, K;
	cin >> M >> K;

	if (K < (1ll << M))
	{
		if (M == 1)
		{
			if (K == 0)
			{
				cout << "0 0 1 1" << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else
		{
			cout << K << " ";
			for (auto i = 0l; i < (1ll << M); ++i)
			{
				if (i == K)
				{
					continue;
				}
				cout << i << " ";
			}
			cout << K << " ";
			for (auto i = (1ll << M) - 1; i >= 0; --i)
			{
				if (i == K)
				{
					continue;
				}
				cout << i;
				if (i > 0)
				{
					cout << " ";
				}
			}
			cout << endl;// 「それから歌舞伎座へいっしょに行ったのかい」と迷亭が要領を得んと云う顔付をして聞く。
		}
	}
	else
	{
		cout << -1 << endl;
	}

	return 0;
}
