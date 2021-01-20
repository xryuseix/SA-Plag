// 引用元 : https://atcoder.jp/contests/abc068/submissions/6479118
// 得点 : 300
// コード長 : 705
// 実行時間 : 151


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;

    bool f = false;

int main() {
    cin >> N >> M;
    bool from_one[N], to_N[N];
    for (int i = 0; i < N; i++) {
        from_one[i] = false;
        to_N[i] = false;
    }
    for (int i = 0; i < M; i++) {
        int a_in, b_in;
        cin >> a_in >> b_in;
        if (!(a_in - 1)) from_one[b_in - 1] = true;
        if (b_in -N == 0) to_N[a_in - 1] = true;
    }
    for (int i = 0; i < N; i++) {
        if (from_one[i] && to_N[i] == 1) {
            f = true;
            break;
        }
    }

    if (f == 1) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}
