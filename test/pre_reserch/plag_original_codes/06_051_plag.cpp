// 引用元 : https://atcoder.jp/contests/abc126/submissions/8549418
// 得点 : 600
// コード長 : 849
// 実行時間 : 25


#include <algorithm>
using namespace std;
#include <vector>
#include <iostream>


int main(){
    int M, K;
    cin >> M >> K;
    if(K == 0){
        for(int i = 0; i < (1<<M); ++i){
            cout << i << " " << i;
            if(i+1 == (1<<M)){
                cout << endl;
            }else{
                cout << " ";
            }
        }
        return 0;
    }
    vector<int> a;
    int v = 0;
    for(int i = 0; i < (1<<M); ++i){
        if(i == K) continue;
        a.push_back(i);
        v = v ^ i;
    }
    if(v != K){
        cout << -1 << endl;
        return 0;
    }
    for(int a_val: a){
        cout << a_val << " ";
    }
    reverse(a.begin(), a.end());
    cout << K << " ";
    for(int a_val: a){
        cout << a_val << " ";
    }
    cout << K << endl;
    return 0;
}

