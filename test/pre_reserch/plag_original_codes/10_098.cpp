// 引用元 : https://atcoder.jp/contests/abc047/submissions/6478408
// 得点 : 300
// コード長 : 423
// 実行時間 : 3


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> v(1, 1);
    for (int i = 1; i < sz(s); i++) {
        if (s[i] == s[i - 1]) {
            v.back()++;
        } else {
            v.push_back(1);
        }
    }
    cout << sz(v) - 1 << "\n";
}
