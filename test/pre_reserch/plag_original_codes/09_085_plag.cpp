// 引用元 : https://atcoder.jp/contests/abc154/submissions/11735656
// 得点 : 300
// コード長 : 414
// 実行時間 : 152


#include <bits/stdc++.h>
using namespace std;
const int INF = 2100100100;
using ll = long long;

int main() {
    int n;
    cin >> n;
    set<int> input;
    for (int i=0;i<n;i++){
        int n;
        cin >> n;
        input.insert(n);
    }
    if (input.size() == n){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}

