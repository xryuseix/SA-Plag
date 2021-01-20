// 引用元 : https://atcoder.jp/contests/abc130/submissions/10702971
// 得点 : 300
// コード長 : 324
// 実行時間 : 1


#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

typedef long long ll;

int MOD=1000000007;


int main(){
    int W,H,x,y;
    cin >> W >> H >> x >> y;
    cout << (double)(W)*(double)(H) / 2 << " " << (x+x == W && y+y == H) << endl;
}
