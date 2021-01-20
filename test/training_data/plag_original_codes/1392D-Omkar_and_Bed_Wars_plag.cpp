#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
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
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define pb(n) push_back(n)

int solve1(int n, string s) {
    if (s == string(n, 'L') || s == string(n, 'R')) return ((2 + n) / 3);

    int ans = 0;
    vi num;
    rep(i, n) {
        int j = i;
        while (s[i] == s[j]) j++;
        num.pb(j - i);
        i = j - 1;
    }
    if (num.size() > 2 && s[0] == s[n - 1]) {
        num[0] += num[num.size() - 1];
        num.pop_back();
    }
    rep(i, num.size()) ans += (num[i]) / 3;
    return ans;
}
int main() {
    int Q = 10;
    cin >> Q;
    while (Q--) {
        int n;
        string s;
        cin >> n >> s;
        fin(solve1(s.size(), s));

        // fin(ans2);
        // if(ans1 == ans2)continue;
        // else {
        //     cout << s.size() <<endl;
        //     cout << s << endl;
        //     cout << "ans1 " << ans1 << endl;
        //     cout << "ans2 " << ans2 << endl << endl;
        // }
        // fin(ans2);
        // if(ans1 == ans2)continue;
        // else {
        //     cout << s.size() <<endl;
        //     cout << s << endl;
        //     cout << "ans1 " << ans1 << endl;
        //     cout << "ans2 " << ans2 << endl << endl;
        // }
        // fin(ans2);
        // if(ans1 == ans2)continue;
        // else {
        //     cout << s.size() <<endl;
        //     cout << s << endl;
        //     cout << "ans1 " << ans1 << endl;
        //     cout << "ans2 " << ans2 << endl << endl;
        // }
        // fin(ans2);
        // if(ans1 == ans2)continue;
        // else {
        //     cout << s.size() <<endl;
        //     cout << s << endl;
        //     cout << "ans1 " << ans1 << endl;
        //     cout << "ans2 " << ans2 << endl << endl;
        // }
    }
}