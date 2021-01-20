// 引用元 : https://atcoder.jp/contests/abc115/submissions/11159358
// 得点 : 400
// コード長 : 1006
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

ull Len[60] = {};

ull all_eat(ull L) {
    ull num_p;
    if (L == 0) num_p = 1ULL;
    else num_p = 2*all_eat(L-1) + 1;
    return num_p;
}

ull eat_p(ull X, ull L) {
    ull num_p;
    if (L==0){
       if (X==0) num_p = 0ULL;
       else num_p = 1ULL; 
    } else {
        if (X<=1) {
            num_p = 0ULL;
        } else if (X<=Len[L-1]+1) {
            num_p = eat_p(X-1, L-1);
        } else if (X==Len[L-1]+2) {
            num_p = all_eat(L-1) + 1;
        } else {
            num_p = all_eat(L-1) + 1;
            num_p += eat_p(X-(Len[L-1]+2), L-1);
        }
    }
    return num_p;
}

int main() {
    ull N, X;
    cin >> N >> X;

    Len[0] = 1;
    for (int i=1; i<=(N+2); i++) Len[i] = 2*Len[i-1] + 3;

    cout << eat_p(X, N) << endl;

    return 0;
}

 
