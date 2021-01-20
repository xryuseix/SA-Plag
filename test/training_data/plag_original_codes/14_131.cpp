// 引用元 : https://atcoder.jp/contests/abc130/submissions/5961808
// 得点 : 400
// コード長 : 2030
// 実行時間 : 66


#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

template<typename T>
class DST {
public:
  int n;
  function<T(T, T)> f;
  vector<T> v;
  vector<pair<vector<T>, vector<T>>> table[32];

  DST(vector<T> &_v, function<T(T, T)> f) : v(_v), f(f) {
    n = 1;
    while (n < v.size()) {
      n <<= 1;
    }
    v.resize(n);
    int m = n >> 1;
    for (int k = 0; m; k++, m >>= 1) {
      table[k].resize(m);
      int kshift = 1 << k;
      int piv = kshift;
      for (int i = 0; i < m; i++) {
        table[k][i].first.resize(kshift);
        table[k][i].second.resize(kshift);
        table[k][i].first[0] = v[piv - 1];
        table[k][i].second[0] = v[piv];
        for (int j = 1; j < kshift; j++) {
          table[k][i].first[j] = f(table[k][i].first[j - 1], v[piv - 1 - j]);
          table[k][i].second[j] = f(table[k][i].second[j - 1], v[piv + j]);
        }
        piv += 2 << k;
      }
    }
  }

  T query(int l, int r) {
    if (r - l <= 1)
      return v[l];
    r--;
    int k = 31 - __builtin_clz(l ^ r);
    int index = l >> (k + 1);
    int piv = index * (2 << k) + (1 << k);
    return f(table[k][index].first[piv - l - 1],
             table[k][index].second[r - piv]);
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  DST<ll> d(a, [](ll a, ll b) {
    return a + b;
  });
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll l = i, r = n;
    if (d.query(i, i + 1) >= k) {
      ans += n - i;
      continue;
    }
    if (d.query(i, r) < k) {
      continue;
    }
    while (r - l > 1) {
      ll m = (r + l) / 2;
      if (d.query(i, m) >= k) {
        r = m;
      } else {
        l = m;
      }
    }
    ans += n - r + 1;
  }
  cout << ans << endl;
  return 0;
}
