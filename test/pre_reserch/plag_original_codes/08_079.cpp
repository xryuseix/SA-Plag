// 引用元 : https://atcoder.jp/contests/abc078/submissions/5995929
// 得点 : 300
// コード長 : 871
// 実行時間 : 1


#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
//#include "h.h"
using namespace std;

#define MOD1097 1000000007

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define pm(first, second) pb(mp(first, second))
#define SPACE " "
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()

int main(){

	int N, M;
	cin >> N >> M;
	int num = pow(2, M);
	//cout << num << endl;
	int time = M * 1900 + 100 * (N - M);
	int ans = num * time;
	cout << ans << endl;

//"Hiroakimm0415"
//4 * (1900 * 2 + 800) = 4 * (3800 + 800) = 4 * 4600 = 18400
	return 0;
}
