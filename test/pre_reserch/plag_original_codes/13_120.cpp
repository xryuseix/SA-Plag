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


int n,C;
int s[100001];
int t[100001];
int c[100001];
int sum[200001];
int cp[200001];

int main(){
        cin >> n >> C;
        for(int i = 0; i < n; i++){
                cin >> s[i] >> t[i] >> c[i];
        }
        for(int j = 1; j <= C; j++){
                memset(cp,0,sizeof(cp));

                for(int i = 0; i < n; i++){
                        if(c[i] == j){
                                cp[s[i]*2 - 1]++;
                                cp[t[i]*2]--;
                        }
                }
                for(int k = 1; k < 200001; k++){
                        cp[k] += cp[k-1];
                }
                for(int l = 0; l < 200001; l++){
                        if(cp[l] > 0){
                                sum[l]++;
                        }
                }
        }

        int ans = 0;
        for(int i = 0; i < 200001; i++){
                chmax(ans, sum[i]);
        }

        cout << ans << endl;
        return 0;


}