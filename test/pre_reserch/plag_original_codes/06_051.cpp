// 引用元 : https://atcoder.jp/contests/abc126/submissions/8549418
// 得点 : 600
// コード長 : 849
// 実行時間 : 25


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
        v = v ^ i;
        a.push_back(i);
    }
    if(v != K){
        cout << -1 << endl;
        return 0;
    }
    for(int a_val: a){
        cout << a_val << " ";
    }
    cout << K << " ";
    reverse(a.begin(), a.end());
    for(int a_val: a){
        cout << a_val << " ";
    }
    cout << K << endl;
    return 0;
}

