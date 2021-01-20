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
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
// #define endl '\n';
#define fi first
#define se second
#define NONVOID [[nodiscard]]
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline void dump(T &v) {
    irep(i, v) { cout << *i << ((i == --v.end()) ? '\n' : ' '); }
}
inline string getline() {
    string s;
    getline(cin, s);
    return s;
}
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
struct io {
    io() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
class Sum {
   public:
    // 単位元
    T unit;

    Sum(void) {
        // 単位元
        unit = 0;
    }

    // 演算関数
    T calc(T a, T b) { return a + b; }
};

template <typename T>
struct Min {
   public:
    // 単位元
    T unit;

    Min(void) {
        // 単位元
        unit = INF;
    }

    // 演算関数
    T calc(T a, T b) { return min(a, b); }
};

template <typename T, class MONOID>
class SegmentTree {
   public:
    // セグメント木の葉の要素数
    int n;

    // セグメント木
    vector<T> tree;

    // モノイド
    MONOID mono;

    SegmentTree(vector<T> &v)
        : n(1 << (int)ceil(log2(v.size()))), tree(vector<T>(n << 1)) {
        for (int i = 0; i < v.size(); ++i) {
            update(i, v[i]);
        }
        for (int i = v.size(); i < n; ++i) {
            update(i, mono.unit);
        }
    }

    // k番目の値(0-indexed)をxに変更
    void update(int k, T x) {
        k += n;
        tree[k] = x;
        for (k = k >> 1; k > 0; k >>= 1) {
            tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
        }
    }

    // [l, r)の最小値(0-indexed)を求める．
    T query(int l, int r) {
        T res = mono.unit;
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) {
                res = mono.calc(res, tree[l++]);
            }
            if (r & 1) {
                res = mono.calc(res, tree[--r]);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

    T operator[](int k) {
        // st[i]で添字iの要素の値を返す
        if (k - n >= 0 || k < 0) {
            return -INF;
        }
        return tree[tree.size() - n + k];
    }

    void show(void) {
        int ret = 2;
        for (int i = 1; i < 2 * n; ++i) {
            if (tree[i] == mono.unit)
                cout << "UNIT ";
            else
                cout << tree[i] << " ";
            if (i == ret - 1) {
                cout << endl;
                ret <<= 1;
            }
        }
        cout << endl;
    }
};

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int n, k;
        cin >> n >> k;
        k -= 2;
        vi v(n), w(n);
        rep(i, n) cin >> w[i];
        v[0] = 0;
        v[n - 1] = 0;
        for (int i = 1; i < n - 1; i++) {
            v[i] = (w[i - 1] < w[i]) && (w[i] > w[i + 1]);
        }
        rep(i, n - 1) { v[i + 1] += v[i]; }
        int pos = 0, ans = 0;
        for (int i = 1; i < n - k + 1; i++) {
            int div = v[i + k - 1] - ((i == 0) ? 0 : v[i - 1]);
            if (div + 1 > ans) {
                ans = div + 1;
                pos = i;
            }
        }
        cout << ans << " " << pos << endl;
    }
}