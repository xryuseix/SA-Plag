// 引用元 : https://atcoder.jp/contests/abc138/submissions/7497813
// 得点 : 300
// コード長 : 352
// 実行時間 : 11


#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; ++i) cin >> v[i];
    sort(begin(v), end(v));

    double res = (v[0] + v[1]) / 2.0;
    for(int i=2; i<N; ++i) {
        res = (res + v[i]) / 2.0;
    }
    cout << fixed << setprecision(6) << res << endl;
}
