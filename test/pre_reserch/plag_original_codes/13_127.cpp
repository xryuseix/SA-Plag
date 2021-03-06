// 引用元 : https://atcoder.jp/contests/abc057/submissions/11149544
// 得点 : 300
// コード長 : 1586
// 実行時間 : 2


#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)

int count(int N)
{

        int cnt = 0;
        while (N)
        {
                cnt++;
                N /= 10;
        }
        return cnt;
}

int main()
{
        ll N;
        cin >> N;
        int ans = count(N);
        for (ll A = 1LL; A*A <=N; A++)
        {
                if (N % A != 0)
                        continue;
                ll B = N / A;

                int tmp = max(count(A), count(B));
                ans = min(ans, tmp);
        }

        cout << ans << endl;

        return 0;
}
