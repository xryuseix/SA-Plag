#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long double ld;
typedef long long int ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 61;
constexpr ll MOD = 1000000007;  // 998244353;
constexpr ld EPS = 1e-11;

/* --------------------   ここまでテンプレ   -------------------- */

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        ll ans = 0;
        ll a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int l = 0;
        int r = s.size() - 1;
        while (l < s.size() && s[l] == '0') l++;
        while (r >= 0 && s[r] == '0') r--;
        if (r < 0) {
            cout << 0 << endl;
            continue;
        }
        s = s.substr(l, r - l + 1);
        rep(i, s.size()) {
            if (s[i] == '1') continue;
            int j = i;
            while (s[j] == '0') {
                j++;
            }
            if ((j - i) * b <= a) {
                ans += (j - i) * b;
                for (int k = i; k < j; k++) s[k] = '1';
            }
            i = j - 1;
        }
        s += '0';
        rep(i, s.size()) {
            if (s[i] == '0') continue;
            int j = i;
            while (s[j] == '1') {
                j++;
            }
            ans += a;
            i = j - 1;
        }

        cout << ans << endl;
    }
}
