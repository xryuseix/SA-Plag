// 引用元 : https://atcoder.jp/contests/abc137/submissions/6820151
// 得点 : 300
// コード長 : 642
// 実行時間 : 127


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  sort(s.begin(), s.end());
  
  unsigned long long count = 0;
  unsigned long long buf = 0;
  int c = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      ++c;
      buf = buf + c;
    }
    else {
      if (buf != 0) {
        count += buf;
        buf = 0;
        c = 0;
      }
    }
  }
  count += buf;
  cout << count << endl;
  return 0;
}
