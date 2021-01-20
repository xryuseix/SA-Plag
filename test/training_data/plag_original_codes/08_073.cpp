// 引用元 : https://atcoder.jp/contests/abc138/submissions/7498183
// 得点 : 500
// コード長 : 694
// 実行時間 : 22


#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    
    map<char, vector<int>> pos;
    for(int i=0; i<s.size(); ++i) {
        pos[s[i]].push_back(i);
    }

    int cur = -1;
    int back = 0;
    for(int i=0; i<t.size(); ++i) {
        char c = t[i];
        if(pos[c].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        auto itr = upper_bound(begin(pos[c]), end(pos[c]), cur);
        if(itr != end(pos[c])) {
            cur = *itr;
        } else {
            ++back;
            cur = pos[c][0];
        }
    }

    cout << (long long)back * s.size() + cur + 1 << endl;
}
