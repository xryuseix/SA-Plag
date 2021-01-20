// 引用元 : https://atcoder.jp/contests/agc009/submissions/5785919
// 得点 : 1100
// コード長 : 1411
// 実行時間 : 29


#include<bits/stdc++.h>

using namespace std;

const int N = 123456, mod = 1e9 + 7;

void add(int& x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
}

void sub(int& x, int y) {
  x -= y;
  if (x < 0) {
    x += mod;
  }
}

int n, f[N], g[N];
long long a, b, s[N];

class bit {
  int a[N];

 public:
  void modify(int x, int y) {
    while (x <= n) {
      add(a[x], y);
      x += x & -x;
    }
  }

  int sum(int x) {
    int result = 0;
    while (x) {
      add(result, a[x]);
      x -= x & -x;
    }
    return result;
  }

  int sum(int l, int r) {
    return (!l ? sum(r) + 1 : sum(r) - sum(l - 1) + mod) % mod;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  s[n + 1] = 2e18;
  bit ftree, gtree;
  for (int i = 1, j1 = 1, j2 = 1, k1 = 1, k2 = 1; i <= n; ++i) {
    if (i != 1 && s[i] - s[i - 1] < a) {
      j1 = i;
    }
    while (k2 < i && s[i + 1] - s[k2] >= b) {
      gtree.modify(k2, g[k2]);
      ++k2;
    }
    f[i] = gtree.sum(j1 - 1, i - 1);
    if (i != 1 && s[i] - s[i - 1] < b) {
      j2 = i;
    }
    while (k1 < i && s[i + 1] - s[k1] >= a) {
      ftree.modify(k1, f[k1]);
      ++k1;
    }
    g[i] = ftree.sum(j2 - 1, i - 1);
  }
  cout << ((f[n] + g[n]) % mod) << '\n';
  return 0;
}
