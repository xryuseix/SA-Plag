// 引用元 : https://atcoder.jp/contests/abc076/submissions/9437312
// 得点 : 300
// コード長 : 732
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;

int main() {
  string d, o;
  vector<string> a;
  cin >> d >> o;
  for(int i = 0; i < d.size() + 1 - o.size(); i++) {
    int h = 1;
    for(int j = 0; j < o.size(); j++)
      if(d.at(i + j) != o.at(j) && d.at(i + j) != '?')
        h = 0;
    if(h) {
      string q;
      for(int k = 0; k < d.size(); k++) {
        if(i <= k && k < i + o.size())
          q.push_back(o.at(k - i));
        else if(d.at(k) == '?')
          q.push_back('a');
        else
          q.push_back(d.at(k));
      }
      a.push_back(q);
    }
  }
  if(a.size()) {
    sort(a.begin(), a.end());
    cout << a.front() << endl;
  } else
    cout << "UNRESTORABLE" << endl;
}
