// 引用元 : https://atcoder.jp/contests/abc137/submissions/6827284
// 得点 : 400
// コード長 : 1246
// 実行時間 : 55


#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz() size()
#define fr first
#define sc second
#define pb push_back
#define er erase
#define in insert
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define mp make_pair
#define int long long
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
//#define cin fin
//#define cout fout
using namespace std;

//ifstream fin("file.in");
//ofstream fout("file.out");

const int nmax=1e3+5;
const int mod=1e9+7;
const int mod1=998244353;

int n,m,ans;
pair<int,int>a[100005];
vector<int>acc[100005];
multiset<int>st;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
        cin >> a[i].fr >> a[i].sc;
        acc[a[i].fr].push_back(a[i].sc);
	}
	for(int i=m-1;i>=0;i--){
        for(int j=0;j<acc[m-i].size();j++) st.insert(acc[m-i][j]);
        if(st.size()>=1){
            auto it=st.end();
            it--;
            ans+=(*it);
            st.erase(it);
        }
	}
	rc(ans);
}
