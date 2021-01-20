// 引用元 : https://atcoder.jp/contests/abc049/submissions/7713560
// 得点 : 300
// コード長 : 1347
// 実行時間 : 28


#include<iostream>
#include<regex>
using namespace std;

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
