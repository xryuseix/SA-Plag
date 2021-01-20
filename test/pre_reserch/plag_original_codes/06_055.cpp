// 引用元 : https://atcoder.jp/contests/abc114/submissions/5704655
// 得点 : 300
// コード長 : 461
// 実行時間 : 1


#include <iostream>
using namespace std;

long long N;


void func(long long cur, int use, long long &counter){


    if(cur > N)return;
    if(use == 0b111) ++counter;
    
    
    func(cur*10+7, use | 0b001, counter);
    
    func(cur*10+5, use | 0b010, counter);
    
    func(cur*10+3, use | 0b100, counter);
    
    
}

int main(void){
    cin >> N;
    long long res = 0;
    func(0,0,res);
    cout << res << endl;
    
}
