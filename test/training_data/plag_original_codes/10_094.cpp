// 引用元 : https://atcoder.jp/contests/abc124/submissions/5996642
// 得点 : 300
// コード長 : 950
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
    int cnt0 = 0;
    int cnt1 = 0;

    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            if(S[i] != '0') {
                cnt0++;
            }
        }
        else {
            if(S[i] != '1') {
                cnt0++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            if(S[i] != '1') {
                cnt1++;
            }
        }
        else {
            if(S[i] != '0') {
                cnt1++;
            }
        }
    }

    if(cnt0 < cnt1) {
        cout << cnt0;
    }
    else {
        cout << cnt1;
    }

    cout << endl;
    return 0;
}
