// 引用元 : https://atcoder.jp/contests/abc071/submissions/11157337
// 得点 : 300
// コード長 : 649
// 実行時間 : 17


#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
const int N=2e5+2;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int i,n,l=-1,r=-1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    for(i=0;i<(n-1);i++)
    {
        if(a[i]==a[i+1])
        {
            if(l==-1)
            {
                l=a[i];
                i++;
            }
            else
            {
                r=a[i];
                break;
            }
        }
    }
    if(l==-1 || r==-1)
    {
        l=0;
    }
    cout<<((ll)l*(ll)r)<<"\n";
    return 0;
}
