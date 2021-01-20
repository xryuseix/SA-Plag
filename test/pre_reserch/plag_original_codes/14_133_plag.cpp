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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a,   b) * b;}
#define rep(i, n) for (ll i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    vector<int> T(N), A(N);
    rep(i, N){
        cin >> T[i] >> A[i];
    }
    
    ll t_vote = 0, a_vote = 0;
    
    rep(i, N){
        if(i == 0){
            t_vote = (ll)T[i];
            a_vote = (ll)A[i];
            continue;
        }
        
        ll temp, t_option, a_option;
        if(!(t_vote % T[i])){
            t_option = t_vote / T[i];
        }
        else{
            t_option = t_vote / T[i] + 1;
        }
        if(!(a_vote % A[i])){
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
