// 引用元 : https://atcoder.jp/contests/abc085/submissions/11158762
// 得点 : 400
// コード長 : 676
// 実行時間 : 87


#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    vector<long long>dmg;
    long long maxdmg = 0, garbo = 0;
    for(long long i = 0; i < n; ++i){
        long long tmp, tmp1; cin >> tmp >> tmp1;
        dmg.push_back(tmp1);
        if(tmp > maxdmg)maxdmg = tmp;
    }
    long long i = 0;
    sort(dmg.begin(), dmg.end(), greater<long long>());
    for(auto x:dmg){
        if(x > maxdmg){
         garbo += x, ++i;
         if(garbo >= m){
            cout << i;
            return 0;
         }
        }
    }
    cout << i + (int)ceil((double)(m - garbo) / (double)maxdmg);
    return 0;
}
