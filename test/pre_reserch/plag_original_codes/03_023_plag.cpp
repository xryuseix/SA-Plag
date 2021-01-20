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
  vector<char> manhambaakarongeka;
  vector<int> nhambayakarongeka;
  char prevc = -1;
  int cur = -1;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] != prevc) {
      manhambaakarongeka.push_back(S[i]);
      nhambayakarongeka.push_back(0);
      cur++;
      prevc = S[i];
    }
    nhambayakarongeka[cur]++;
  }
  vector<int> Mariyakarongeka(nhambayakarongeka.size());
  Mariyakarongeka[0] = nhambayakarongeka[0];
  for (int i = 1; i < nhambayakarongeka.size(); i++) {
    Mariyakarongeka[i] = Mariyakarongeka[i-1] + nhambayakarongeka[i];
  }
  int mhinduro = -1;
  for (int i = 0; i < manhambaakarongeka.size(); i++) {
    if (manhambaakarongeka[i] == '0') {
      int uwandu = Mariyakarongeka[min({i + 2*K-1, (int)nhambayakarongeka.size()-1})];
      if (i - 2 >= 0) {
        uwandu -= Mariyakarongeka[i-2];
      }
      mhinduro = max({mhinduro, uwandu});
    }
  }
  if (mhinduro == -1) {
    mhinduro = S.length();
  }
  cout << mhinduro << endl;
  return 0;
}
