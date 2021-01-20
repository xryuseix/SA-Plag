// 引用元 : https://atcoder.jp/contests/agc024/submissions/5998080
// 得点 : 300
// コード長 : 2122
// 実行時間 : 6


#include<iostream>
using namespace std;

signed main() {
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	if (!(k % 2)) { cout << a - b << endl; }
	else { cout << b - a << endl; }
	return 0;
}
