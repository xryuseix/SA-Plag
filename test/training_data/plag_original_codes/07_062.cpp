// 引用元 : https://atcoder.jp/contests/agc003/submissions/1125179
// 得点 : 400
// コード長 : 361
// 実行時間 : 58


#include <iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n]; for(e: a) cin>>e;

    long res=0;
    int c=0;
    for(int e: a) {
        if (e==0) {
            c=0;
        }
        else {
            res+=c;
            e-=c;
            res+=e/2;
            c=e%2;
        }
    }
    cout<<res<<endl;
}

