// 引用元 : https://atcoder.jp/contests/abc122/submissions/5997478
// 得点 : 300
// コード長 : 695
// 実行時間 : 70


#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> l(q), r(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
    }
    vector<int> sum(n+1, 0);

    for(int i = 1; i < n; i++) {

        sum[i+1] = sum[i];
        if(s[i-1] == 'A' && s[i] == 'C') {
            sum[i+1]++;
        }
    }

    rep(i, q) {
        int ans = sum[r[i]] - sum[l[i]];
        cout << ans << "\n";
    }

    cout << endl;
    return 0;
}
