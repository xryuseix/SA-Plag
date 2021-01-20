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
#pragma GCC optimize("Ofast")
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int n;
        cin >> n;
        vi v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            m[v[i]] = i;
        }
        vi use(n, 0);
        bool ch = 1;
        for (int i = -100; i < n; i++) {
            if (i < 1) continue;
            int nowPos = m[i], nextPos = m[i + 1];
            use[nowPos] = 1;
            if (use[nowPos + 1] || nowPos == n - 1 || nowPos + 1 == nextPos)
                continue;
            ch = 0;
        }
        if (ch) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}