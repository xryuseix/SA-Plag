// 引用元 : https://atcoder.jp/contests/abc080/submissions/5997900
// 得点 : 400
// コード長 : 1970
// 実行時間 : 125


#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = ((ll)(x) - 1); i >= 0; i--)

#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define chmin(x,y) (x=min(x,y))
#define chmax(x,y) (x=max(x,y))

//ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

const ll mod = 1e9 + 7;
const ll IMF = 1LL<<29;
const double PI = 3.14159265358979323846;


// ***************************CODE**********************//



int main(){
        int n,C;
        cin >> n >> C;
        vector<int> s(n),t(n),c(n),sum(2*n+1),cp(2*n+1);
        for(int i = 0; i < n; i++){
                cin >> s[i] >> t[i] >> c[i];
        }
        for(int j = 1; j <= C; j++){
                cp=vector<int>(2*n+1,0);

                for(int i = 0; i < n; i++){
                        if(c[i] == j){
                                cp[s[i]*2 - 1]++;
                                cp[t[i]*2]--;
                        }
                }
                for(int k = 1; k < 2*n+1; k++){
                        cp[k] += cp[k-1];
                }
                for(int l = 0; l < 2*n+1; l++){
                        if(cp[l] > 0){
                                sum[l]++;
                        }
                }
        }

        int ans = 0;
        for(int i = 0; i < 2*n+1; i++){
                chmax(ans, sum[i]);
        }

        cout << ans << endl;
        return 0;


}

