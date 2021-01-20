// 引用元 : https://atcoder.jp/contests/abc103/submissions/5997904
// 得点 : 300
// コード長 : 480
// 実行時間 : 2


#include <iostream>

#include <vector>

#include <cassert>

#include <algorithm>

#include <functional>

#include <cmath>

#include <iomanip>

#include <limits>
#include <bits/stdc++.h>
#include<queue>
#include<type_traits>
#include<cstdint>
using namespace std;
using ll=long long;
int main(){
    int n;
    cin >> n;
    ll count=0;
    for(int i=0;i<n;i++){
        ll x;
        cin >>x;
        count += x;
    }
    cout << count-n << endl;
}
