// 引用元 : https://atcoder.jp/contests/abc126/submissions/8078441
// 得点 : 600
// コード長 : 760
// 実行時間 : 21


#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, k;
    cin >> m >> k;
    if (m == 1) {
        if (k == 0) {
            cout << "0 0 1 1" << endl;
        } else {
            cout << "-1" << endl;
        }
        return 0;
    }
    if (k < (1 << m)) {
        cout << k;
        for (int i = 0; i < (1 << m); ++i) {
            if (i != k) {
                cout << " " << i;
            }
        }
        cout << " " << k;
        for (int i = (1 << m)-1; i >= 0; --i) {
            if (i != k) {
                cout << " " << i;
            }
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}
