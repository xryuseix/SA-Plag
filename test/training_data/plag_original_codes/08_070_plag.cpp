// 引用元 : https://atcoder.jp/contests/abc090/submissions/5996681
// 得点 : 400
// コード長 : 601
// 実行時間 : 2


#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	ll n, k;
	cin >> n;
	cin >> k;
	if(k==0){
		cout << n*n << endl;
		return 0;
	}

	ll ans;
	ans=0;
	for(int i=k+1; i<=n; i++){
		ans+=(n/i)*(i-k);
		ans+=max(0ll, n%i-k+1);
	}
	cout << ans << endl;
	return 0;
}
