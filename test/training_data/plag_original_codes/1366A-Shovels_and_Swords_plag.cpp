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

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int ans = 0, a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);

        int diff = a - b;
        int red = min(min(diff, b), a / 2);
        b -= red;
        ans += red;
        a -= red * 2;

        ans += b / 3 * 2;
        a -= b / 3 * 3;
        b %= 3;
        for (int i = 0; i < 2; i++) {
            if (a >= 2 && b >= 1) {
                ans++;
                b--;
                a -= 2;
            }
        }
        cout << ans << endl;
    }
}
