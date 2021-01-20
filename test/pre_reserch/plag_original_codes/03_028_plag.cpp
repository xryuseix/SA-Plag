// 引用元 : https://atcoder.jp/contests/agc037/submissions/7713625
// 得点 : 300
// コード長 : 427
// 実行時間 : 27


#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
using ll = long long;
using namespace std;
int main() {
  	string s;
    string p = "";
    string n = "";
  	cin >> s;
  
  	ll kuwerenga = 0;
  	REP(i, s.length()) {
      	n += s[i];
      	if (p != n) {
          	kuwerenga++;
          	p = n;
          	n = "";
        }
    }
  	cout << kuwerenga << endl;
  	return 0;
}
