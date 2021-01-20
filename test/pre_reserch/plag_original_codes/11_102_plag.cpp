// 引用元 : https://atcoder.jp/contests/abc103/submissions/5997069
// 得点 : 400
// コード長 : 1461
// 実行時間 : 74


//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <iterator>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(v) reverse((v).begin(),(v).end())
#define ANS(ans) cout<<(ans)<<endl;
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
typedef vector<int> VI;
typedef pair<int, int> P;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)

struct MyStruct {
	int a, b;
};

bool comp(const MyStruct& s, const MyStruct& t) {
	switch (s.a != t.a)
	{
	case 1:
		return s.a > t.a;
	default:
		return s.b > t.b;;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<MyStruct> v(m);
	REP(i, m) {
		cin >> v[i].a >> v[i].b;
	}

	sort(v.begin(), v.end(), comp);

	int ans = 1;
	int tmp = v[0].a + 1;;
	REP(i, m) {
		switch (tmp >= v[i].a && tmp<=v[i].b)
		{
			case 1:
				/* code */
				break;
			
			default:
				tmp = v[i].a + 1;
				ans++;
				break;
		}
	}

	ANS(ans);
	

	return 0;
}
