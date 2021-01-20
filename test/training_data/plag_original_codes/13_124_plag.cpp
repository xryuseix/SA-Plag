// 引用元 : https://atcoder.jp/contests/abc126/submissions/8559867
// 得点 : 600
// コード長 : 2243
// 実行時間 : 22


//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define ub upper_bound
#define lb lower_bound

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int ll


int m, k;
main() {
    cin >> m >> k;
    if ((1 << m) - 1 < k) return !(cout << -1);
    if (!k) {
        for (int mask = 0; mask < (1 << m); ++mask) {
            cout << mask << " " << mask << " ";
        }
        return 0;
    }
    vector <int> v;
    int x = 0;
    for (int mask = 0; mask < (1 << m); ++mask) {
        v.eb(mask);
        if (mask != k) x ^= mask;
    }
    if (x != k) return !(cout << -1);
    for (int it : v) if (it != k) cout << it << " ";
    cout << k << " ";
    reverse(all(v));
    for (int it : v) if (it != k) cout << it << " ";
    cout << k;
    return 0;
}