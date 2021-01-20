// 引用元 : https://atcoder.jp/contests/abc124/submissions/6478373
// 得点 : 400
// コード長 : 1021
// 実行時間 : 6


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  vector<char> digarr;
  vector<int> numarr;
  char prevc = -1;
  int cur = -1;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] != prevc) {
      digarr.push_back(S[i]);
      numarr.push_back(0);
      cur++;
      prevc = S[i];
    }
    numarr[cur]++;
  }
  vector<int> sumarr(numarr.size());
  sumarr[0] = numarr[0];
  for (int i = 1; i < numarr.size(); i++) {
    sumarr[i] = sumarr[i-1] + numarr[i];
  }
  int res = -1;
  for (int i = 0; i < digarr.size(); i++) {
    if (digarr[i] == '0') {
      int sum = sumarr[min({i + 2*K-1, (int)numarr.size()-1})];
      if (i - 2 >= 0) {
        sum -= sumarr[i-2];
      }
      res = max({res, sum});
    }
  }
  if (res == -1) {
    res = S.length();
  }
  cout << res << endl;
  return 0;
}
