// 引用元 : https://atcoder.jp/contests/abc114/submissions/4881690
// 得点 : 300
// コード長 : 1313
// 実行時間 : 177


#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

void print(){ std::cout << std::endl; }
template <typename H> void print(H head) { std::cout << head << std::endl; }
template <typename H, typename... T> void print(H head, T... tail){ std::cout << head << " ", print(tail...); }

char get(ll x) {
  if (x == 0) return '0';
  if (x == 1) return '3';
  if (x == 2) return '5';
  return '7';
}

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll N;
  std::cin >> N;

  ll ans = 0LL;
  std::map<ll, bool> mused;
  for (ll S = 1; S < std::pow(4, 9); S++) {
    std::string str;
    ll status = S;
    while (status > 0) {
      ll x = status % 4;
      str += get(x);
      status /= 4;
    }
    ll num = atoi(str.c_str());
    if (num > N) continue;
    if (mused[num]) continue;
    if (str.find("3") == std::string::npos) continue;
    if (str.find("5") == std::string::npos) continue;
    if (str.find("7") == std::string::npos) continue;
    if (std::to_string(num).find("0") != std::string::npos) continue;
    mused[num] = true;
    ans++;
  }

  print(ans);
  return 0;
}
