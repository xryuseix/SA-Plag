#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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
#include <vector>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;

// vector vの中のn以下の数で最大のものを返す
int bs(vector<int> &v, int x) {
    int ok = -1;        //これがx以下
    int ng = v.size();  // x以上
    // 問題によってokとngを入れ替える
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (v[mid] <= x)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    vi v;
    for (ll i = 1;; i++) {
        ll ans = (i) * (i + 1) / 2;
        if (ans > 2e9)
            break;
        else
            v.push_back(ans);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int n, k;
        cin >> n >> k;
        int pos = bs(v, k - 1);
        int b2 = (pos < 0) ? 0 : k - v[pos] - 1;
        int b1 = pos + 2;
        string s;
        for (int i = 0; i < n; i++) {
            if (i == b1 || i == b2)
                s += 'b';
            else
                s += 'a';
        }
        reverse(s.begin(), s.end());
        cout << (s) << endl;
    }
}