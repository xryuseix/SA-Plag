// 引用元 : https://atcoder.jp/contests/abc138/submissions/7713596
// 得点 : 300
// コード長 : 328
// 実行時間 : 1


# include <bits/stdc++.h>
// # define INF 1e9
using namespace std;


int main(){

  int N;
  cin >> N;
  int v[N];
  for(int i=0; i<N; i++){
    cin >> v[i];
  }
  sort(v, v+N);
  double ans = v[0];
  for(int i=1; i<N; i++){
    ans = (ans + v[i]) / 2;
  }

  cout << setprecision(20) << ans << endl;


}
