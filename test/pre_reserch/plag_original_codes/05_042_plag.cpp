// 引用元 : https://atcoder.jp/contests/abc124/submissions/5996524
// 得点 : 400
// コード長 : 830
// 実行時間 : 604


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;

  vector<int> v;
  bool iszero = false;
  int count = 0;
  for (int i=0; i<N; i++) {
    if (S[i] == '0' && iszero || S[i] =='1' && !iszero) {
      count++;
    } else {
      v.push_back(count);
      count = 1;
      iszero = !iszero;
    }
  }
  v.push_back(count);
  if (iszero) v.push_back(0);

  int max_person = 0, sum; 
  if (2*K+1 > v.size()) {
    for (int i=0; i<v.size(); i++) {
      max_person += v[i];
    }
  } else {
    for (int i=0; i+2*K+1 <= v.size(); i+=2) {
      sum = 0;
      for (int j=0; j<2*K+1; j++) {
        sum += v[j+i];
      }
      if (sum > max_person) max_person = sum;
    }
  }
  cout << max_person << endl;
}
