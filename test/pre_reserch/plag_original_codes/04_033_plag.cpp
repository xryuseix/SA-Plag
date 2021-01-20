// 引用元 : https://atcoder.jp/contests/abc137/submissions/6827284
// 得点 : 400
// コード長 : 1246
// 実行時間 : 55


#include <bits/stdc++.h>
#define ll long long
#define all(aaaaaaaaaaaa) (aaaaaaaaaaaa).begin(), (aaaaaaaaaaaa).end()
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

const int aaaaaaaaaaaaaaaaaaa=1e3+5;
const int aaaaaaaaaaaaaaaaaaaa=1e9+7;
const int aaaaaaaaaaaaaaaaaaaaa=998244353;

int aaaaaaaaaa,aaaaaaaaaaa,aaaaaaaaaaaaaaaaaa;
pair<int,int>aaaaaaaaaaaa[100005];
vector<int>aaaaaaaaaaaaa[100005];
multiset<int>aaaaaaaaaaaaaa;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> aaaaaaaaaa >> aaaaaaaaaaa;
	for(int aaaaaaaaaaaaaaa=1;aaaaaaaaaaaaaaa<=aaaaaaaaaa;aaaaaaaaaaaaaaa++){
        cin >> aaaaaaaaaaaa[aaaaaaaaaaaaaaa].fr >> aaaaaaaaaaaa[aaaaaaaaaaaaaaa].sc;
        aaaaaaaaaaaaa[aaaaaaaaaaaa[aaaaaaaaaaaaaaa].fr].push_back(aaaaaaaaaaaa[aaaaaaaaaaaaaaa].sc);
	}
	for(int aaaaaaaaaaaaaaa=aaaaaaaaaaa-1;aaaaaaaaaaaaaaa>=0;aaaaaaaaaaaaaaa--){
        for(int aaaaaaaaaaaaaaaa=0;aaaaaaaaaaaaaaaa<aaaaaaaaaaaaa[aaaaaaaaaaa-aaaaaaaaaaaaaaa].size();aaaaaaaaaaaaaaaa++) aaaaaaaaaaaaaa.insert(aaaaaaaaaaaaa[aaaaaaaaaaa-aaaaaaaaaaaaaaa][aaaaaaaaaaaaaaaa]);
        if(aaaaaaaaaaaaaa.size()>=1){
            auto aaaaaaaaaaaaaaaaa=aaaaaaaaaaaaaa.end();
            aaaaaaaaaaaaaaaaa--;
            aaaaaaaaaaaaaaaaaa+=(*aaaaaaaaaaaaaaaaa);
            aaaaaaaaaaaaaa.erase(aaaaaaaaaaaaaaaaa);
        }
	}
	rc(aaaaaaaaaaaaaaaaaa);
}
