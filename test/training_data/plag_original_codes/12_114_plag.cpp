// 引用元 : https://atcoder.jp/contests/abc063/submissions/5998767
// 得点 : 300
// コード長 : 476
// 実行時間 : 1


#include <bits/stdc++.h>
#define rep(i,a,b) for (int64_t i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;

int main()
{
    int n,sum=0;
    cin>>n;
    vector<int>s(n);
    REP(i,n){cin>>s[i];sum+=s[i];}
    sort(s.begin(),s.end());
    int j=0;
    while(sum%10==0)
    {
        if(j==n&&!(sum%10)){sum=0;break;}
        if(!(s[j]%10)){j++;continue;}
        
        sum-=s.at(j);
        j++;
    }
    cout<<sum<<endl;
}
