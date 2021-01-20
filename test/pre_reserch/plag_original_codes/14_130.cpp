// 引用元 : https://atcoder.jp/contests/abc049/submissions/7713560
// 得点 : 300
// コード長 : 1347
// 実行時間 : 28


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
#include<map>
#include<set>
#include<bitset>
#include<regex>
using namespace std;
#define REP(i,m,n) for(int i = m; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define dup(x,y) (((x)+(y)-1) / (y)) //整数型のまま切り上げ演算する
#define PI 3.14159265359
typedef long long LL;
template<class T> inline void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> inline void chmin(T& a, T b) { if (a > b) { a = b; } }
template<class T> inline T gcd(T x, T y) { if (y == 0) { return x; } else if (x == 0) { return y; }return gcd(y, x % y); }
template<class T> inline T lcm(T x, T y) { return (x * y) / gcd(x, y); }
template<class T> inline void print_vector(vector<T> vec) { for (int i = 0; i < vec.size(); i++) { cout << vec[i] << " "; } cout << endl; }
const LL MOD = 1e9 + 7;
const LL LLINF = 1LL << 60;
const int INF = 1 << 30;

int main(void) {
	string S;
	cin >> S;

	regex re("(dream|dreamer|erase|eraser)+");

	if (regex_match(S,re)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
