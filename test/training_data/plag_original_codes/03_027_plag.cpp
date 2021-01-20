// 引用元 : https://atcoder.jp/contests/abc092/submissions/5997377
// 得点 : 300
// コード長 : 837
// 実行時間 : 183


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#include <numeric>
#include <bitset>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
	int N;
	cin >> N;
	vector<int> A(N + 2, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i + 1];
	}

	//okwana
	int okwana = 0;
	for (int i = 0; i < N + 1; i++) {
		okwana += abs(A[i + 1] - A[i]);
	}

	for (int i = 1; i < N + 1; i++) {
		cout << okwana + abs(A[i - 1] - A[i + 1]) - (abs(A[i - 1] - A[i]) + abs(A[i] - A[i + 1])) << endl;
	}

	return 0;
}
