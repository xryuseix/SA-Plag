// 引用元 : https://atcoder.jp/contests/abc099/submissions/5997146
// 得点 : 300
// コード長 : 531
// 実行時間 : 3


#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int N;
    cin >> N;
    int ans = N;
    
    rep(i, N+1){
        int res = 0;
        int t = i;
        while(t > 0){
             res += t%9;
             t = t/9;
        }
        t = N - i;
        while(t > 0){
            res += t%6;
            t = t/6;
        }
        if(res < ans)ans = res;
    }
    cout << int(ans);
}
