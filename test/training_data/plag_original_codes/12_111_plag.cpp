// 引用元 : https://atcoder.jp/contests/abc138/submissions/7482995
// 得点 : 300
// コード長 : 538
// 実行時間 : 4


#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	double result = 0;
	cin >> n;
	vector<double> materials(n);
	
	for (int i = 0; i < n; i++) {
		cin >> materials.at(i);
	}
	sort(materials.begin(), materials.end());
	if (n == 1) {
		result = materials[0];
	}
	else {
		result = (materials[0] + materials[1]) / 2;
		for (int i = 2; i < n; i++) {
			result = (result + materials[i]) / 2;
		}
	}
	
	cout << result << endl;
}