// 引用元 : https://atcoder.jp/contests/abc076/submissions/9437312
// 得点 : 300
// コード長 : 732
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  vector<string> o;
  cin >> s >> t;
  for(int i = 0; i < s.size() + 1 - t.size(); i++) {
    int f = 1;
    for(int j = 0; j < t.size(); j++)
      if(s.at(i + j) != t.at(j) && s.at(i + j) != '?')
        f = 0;
    if(f) {
      string u;
      for(int k = 0; k < s.size(); k++) {
        if(i <= k && k < i + t.size())
          u.push_back(t.at(k - i));
        else if(s.at(k) == '?')
          u.push_back('a');
        else
          u.push_back(s.at(k));
      }
      o.push_back(u);
    }
  }
  if(o.size()) {
    sort(o.begin(), o.end());
    cout << o.front() << endl;
  } else
    cout << "UNRESTORABLE" << endl;
}
