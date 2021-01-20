// 引用元 : https://atcoder.jp/contests/abc046/submissions/5998101
// 得点 : 300
// コード長 : 1207
// 実行時間 : 2


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

typedef long long ll;

int gcd(int a, int b);
int lcm(int a, int b);

int main(){
    int N;
    cin >> N;
    vector<int> T(N), A(N);
    for(int i = 0; i < N; i++){
        cin >> T[i] >> A[i];
    }
    
    ll t_vote = 0, a_vote = 0;
    
    for(int i = 0; i < N; i++){
        if(i == 0){
            t_vote = (ll)T[i];
            a_vote = (ll)A[i];
            continue;
        }
        
        ll temp, t_option, a_option;
        if(t_vote % T[i] == 0){
            t_option = t_vote / T[i];
        }
        else{
            t_option = t_vote / T[i] + 1;
        }
        if(a_vote % A[i] == 0){
            a_option = a_vote / A[i];
        }
        else{
            a_option = a_vote / A[i] + 1;
        }
        temp = max(t_option, a_option);
        
        t_vote = temp * T[i];
        a_vote = temp * A[i];
    }
    
    cout << t_vote + a_vote << endl;
}

int gcd(int a, int b){
    if(b == 0)      return 0;
    
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}
