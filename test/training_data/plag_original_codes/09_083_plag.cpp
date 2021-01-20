// 引用元 : https://atcoder.jp/contests/agc003/submissions/1125175
// 得点 : 400
// コード長 : 410
// 実行時間 : 58


#include <iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n]; for(e: a) cin>>e;

    long res=a[0]/2, c=a[0]%2;
    for(int i=1; i<n; ++i) {
        if (a[i]==0) {
            c=0;
        }
        else {
            res+=c;
            a[i]-=c;
            c=0;
            res+=a[i]/2;
            c=a[i]%2;
        }
    }
    cout<<res<<endl;
}

