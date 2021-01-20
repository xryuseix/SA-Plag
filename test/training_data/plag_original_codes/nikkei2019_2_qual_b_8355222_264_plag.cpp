/*
引用元：https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b
B - Counting of TreesEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/nikkei2019-2-qual/submissions/8355222
// 提出ID : 8355222
// 問題ID : nikkei2019_2_qual_b
// コンテストID : nikkei2019-2-qual
// ユーザID : xryuseix
// コード長 : 2312
// 実行時間 : 32



*/
#include <algorithm>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long double ld;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<long long int> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<long long int>> vvll;
#define rep(i, n) for (int i = 0; i < (n); ++i)


// xのn乗%modを計算
long long int mod_pow(long long int x, long long int n, long long int mod = 998244353) {
    long long int res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main(void) {
    int n;
    cin >> n;
    vll d(n);
    rep(i, n) cin >> d[i];
    long long int maxd = 0;
    for (int i = 0; i < n; i++) maxd = max(maxd, d[i]);
    vll distance(maxd + 1, 0);
    for (int i = 0; i < n; i++) {
        distance[d[i]]++;
    }

    long long int ans = 1;
    if (d[0] != 0 || distance[0] != 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < maxd; i++) {
        ans *= mod_pow(distance[i], distance[i + 1]);
        ans %= 998244353;
    }
    cout << ans << endl;
}
