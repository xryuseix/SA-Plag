// 引用元 : https://atcoder.jp/contests/abc093/submissions/5996740
// 得点 : 300
// コード長 : 785
// 実行時間 : 1


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
int main() {int A, B, C;cin >> A >> B >> C;vector<int> li(3);li[0] = A; li[1] = B; li[2] = C;sort(li.begin(), li.end());int count = 0;count += (li[1] - li[0]) / 2;if ((li[1] - li[0]) % 2 == 0) {count += li[2] - li[1];}else {count += li[2] - li[1] + 2;}cout << count;return 0;}