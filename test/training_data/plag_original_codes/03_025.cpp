// 引用元 : https://atcoder.jp/contests/abc113/submissions/5997099
// 得点 : 400
// コード長 : 1750
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;
vector <string> patterns;
using ll = long long;
void create_patterns(int n, string s){
    if(s.size()>n) return ;
    if(s.size()==n) {
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'&&s[i+1] == '1') return ;
            
        }
        if(!binary_search(patterns.begin(), patterns.end(), s))patterns.push_back(s);
    }
    create_patterns(n, s+"0");
    create_patterns(n, s+"1");
    return ;
}
int main(void){
    int h,w,k; cin>>h>>w>>k;
    k--;
    if(w==1) {cout<<1<<endl; return 0;}
    create_patterns(w-1, "");
    vector <vector<int>> itoj(w ,vector <int>(w ));
    for(int i=0;i<patterns.size();i++){
        //cout<<patterns[i]<<endl;
        string s = patterns[i];
        if(s[0]=='0') itoj[0][0]++;
        //if(s[w-1]=='0') itoj[w-1][w-1]++;
        for(int j=1;j<w-1;j++){
            if(s[j-1]=='0'&&s[j]=='0') itoj[j][j]++;
        }
        for(int i=0;i<w-1;i++){
            if(s[i]=='1') {itoj[i][i+1]++; itoj[i+1][i]++;}
        }
    }
    itoj[w-1][w-1] = itoj[0][0];
    for(int i=0;i<w;i++){
        for(int j=0;j<w;j++){
            if(abs(i-j)>1) continue;
            //cout<<i<<"to"<<j<<' '<<itoj[i][j]<<endl;
        }
    }
    vector <vector<ll>> dp(h+5 ,vector <ll>(w));
    dp[0][0]=1;
    for(int i=0;i<h+1;i++){
        for(int j=0;j<w;j++){
            dp[i+1][j]+= dp[i][j]*itoj[j][j];
            if(j+1<w)
            dp[i+1][j+1] += dp[i][j]*itoj[j][j+1];
            if(j-1>=0)
            dp[i+1][j-1] += dp[i][j]*itoj[j][j-1];
            dp[i+1][j]%=1000000007;
            dp[i+1][j+1]%=1000000007;
            dp[i+1][j-1]%=1000000007;
        }
    }
    cout<<dp[h][k]<<endl;
}
