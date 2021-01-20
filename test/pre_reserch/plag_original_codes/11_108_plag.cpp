// 引用元 : https://atcoder.jp/contests/abc130/submissions/5962917
// 得点 : 400
// コード長 : 1948
// 実行時間 : 32


#include <bits/stdc++.h>
using namespace std;
using LL  = long long;
using VI  = vector<LL>;
using VVI = vector<VI>;
using VB  = vector<bool>;
using VS  = vector<string>;
using PII = pair<LL, LL>;
using VP  = vector<PII>;
#define PB           push_back
#define MP           make_pair
#define SZ(a)        LL((a).size())
#define EACH(x, c)   for (auto x : (c))
#define ALL(c)       (c).begin(), (c).end()
#define REVERSE(c)   reverse(ALL(c))
#define SORT(c)      stable_sort(ALL(c))
#define RSORT(c)     stable_sort((c).rbegin(), (c).rend())
#define FSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first < y.first;});
#define FRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first > y.first;});
#define SSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second < y.second;});
#define SRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second > y.second;});
#define FOR(i, a, b) for (LL i = (a); i < (b); ++i)
#define REP(i, n)    FOR(i, 0, n)
#define $(x) {cout << #x << " = " << (x) << endl;}


int main() {
    LL N, K;
    cin >> N >> K;
    VI a(N);
    int i=1;
    while(i<N){
        cin >> a[i];
        i++;
    } 

    LL ans = 0;

    LL right = 0;
    LL sum = 0;
    for (LL left = 0; left < N; ++left) {
        while (right < N && sum < K) {
            /* 実際に right を 1 進める */
            // ex: sum += a[right];
            sum += a[right];
            ++right;
        }
        if (sum < K) break;
        
        ans += N - right + 1;
        switch (right == left)
        {
        case 1:
            ++right;
            break;
        
        default:
            sum -= a[left];
            break;
        } 
        
        /* break した状態で right は条件を満たす最大なので、何かする */
        // ex: res += (right - left);
        
        /* left をインクリメントする準備 */
        // ex: if (right == left) ++right;
        // ex: else sum -= a[left];
    }

    cout << ans << endl;
	
    return 0;
}
