// 引用元 : https://atcoder.jp/contests/abc138/submissions/7664229
// 得点 : 300
// コード長 : 492
// 実行時間 : 1


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	priority_queue<double, vector<double>, greater<double>> v;
	double tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		v.push(tmp);
	}

	while (v.size() > 1)
	{
		double x = v.top();
		v.pop();
		double y = v.top();
		v.pop();
		v.push((x + y) / 2);
	}
	cout << setprecision(10) << v.top() << endl;

	return 0;
}
