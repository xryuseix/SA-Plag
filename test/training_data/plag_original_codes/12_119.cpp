// 引用元 : https://atcoder.jp/contests/agc013/submissions/6478475
// 得点 : 300
// コード長 : 1127
// 実行時間 : 55


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;

int main(){

    int n; cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int ans = 1;

    bool start = true;
    bool increasing = true;
    for(int i=1; i<n; i++){
        if(start){
            if(a[i] == a[i-1]){
                continue;
            }
            else if(a[i] > a[i-1]){
                start = false;
                increasing = true;
            }
            else{
                start = false;
                increasing = false;
            }
        }
        else{
            if(increasing && a[i] < a[i-1]){
                start = true;
                ans++;
            }
            else if(!increasing && a[i] > a[i-1]){
                start = true;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
