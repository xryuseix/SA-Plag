// 引用元 : https://atcoder.jp/contests/abc081/submissions/11159313
// 得点 : 300
// コード長 : 695
// 実行時間 : 650


#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main() {
    int N,K; cin>>N>>K;
    vector<int>a(N);
    map<int,int>mp;
    rep(i,N){
        cin>>a[i];
        mp[a[i]]++;
    }
    int cnt=0;
    int ans =0;
    vector<int>data(0);
    for(auto p:mp){
        data.emplace_back(p.second);
        cnt++;
    }
    sort(data.begin(),data.end());
    reverse(data.begin(),data.end());
    int cnt1=0;
    for(int i=0;i<cnt;i++){
        cnt1++;
        if(cnt1>K){
            ans +=data[i];
        }
    }
    cout<<ans<<endl;
}
