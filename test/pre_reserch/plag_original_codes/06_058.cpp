// 引用元 : https://atcoder.jp/contests/abc138/submissions/7489378
// 得点 : 300
// コード長 : 446
// 実行時間 : 1


//  ROAD TO GREEN
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
typedef long long ll;
const ll MAXN = 45;

int main(){
    int n; cin >> n;
    double a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    double cur = (a[0]+a[1])/2;
    for(int i = 2; i < n; i++){
        cur = (cur+a[i])/2;
    }
    cout << cur << endl;
    return 0;
}
