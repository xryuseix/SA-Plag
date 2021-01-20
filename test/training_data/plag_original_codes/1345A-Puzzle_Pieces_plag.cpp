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
#define fin(ans) cout << (ans) << '\n'

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == 1 || b == 2) {
            fin("YES");
            continue;
        } else {
            fin("NO");
        }
    }
}