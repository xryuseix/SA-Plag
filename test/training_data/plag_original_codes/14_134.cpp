// 引用元 : https://atcoder.jp/contests/abc132/submissions/12412128
// 得点 : 300
// コード長 : 239
// 実行時間 : 35


#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> d(N);
    for(int i=0;i<N;i++)cin >> d[i];
    sort(d.begin(),d.end());
    int ans = d[N/2] - d[N/2-1];
    cout << ans << endl;

}
