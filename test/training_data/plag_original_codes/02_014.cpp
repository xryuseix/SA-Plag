// 引用元 : https://atcoder.jp/contests/abc120/submissions/5997955
// 得点 : 300
// コード長 : 553
// 実行時間 : 5


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
    string S;
    cin >> S;
    int N = S.size();
    int cnt0 = 0, cnt1 = 0;

    rep(i, N) {
        if(S[i] == '0') {
            cnt0++;
        }
        else if(S[i] == '1') {
            cnt1++;
        }
    }

    int ans = min(cnt0, cnt1) * 2;

    cout << ans;

    cout << endl;
    return 0;
}
