// 引用元 : https://atcoder.jp/contests/agc023/submissions/5996664
// 得点 : 500
// コード長 : 687
// 実行時間 : 86


#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

int main(){
    int n;
    scanf("%d", &n);
    string s[n];
    rep(i, n) cin >> s[i];
    int cnt = 0;
    string t[n];
    rep(i, n){
        rep(j, n) t[j] = s[(i+j)%n];
        rep(j, n)rep(k, n){
            if(t[j][k] != t[k][j]) goto con;
        }
        ++cnt;
        con:
            continue;
    }
    printf("%d\n", cnt*n);
}
