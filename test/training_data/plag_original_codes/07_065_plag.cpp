// 引用元 : https://atcoder.jp/contests/agc015/submissions/11157603
// 得点 : 400
// コード長 : 388
// 実行時間 : 5


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
struct mint {
  ll x;
  mint(ll _x = 0) : x((_x % MOD + MOD) % MOD) {}

  /* 初期化子 */
  mint operator+() const { return mint(x); }
  mint operator-() const { return mint(-x); }

  /* 代入演算子 */
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint& operator/=(const mint a) {
    x *= modinv(a).x;
    x %= MOD;
    return (*this);
  }
  mint& operator%=(const mint a) {
    x %= a.x;
    return (*this);
  }
  mint& operator++() {
    ++x;
    if (x >= MOD) x -= MOD;
    return *this;
  }
  mint& operator--() {
    if (!x) x += MOD;
    --x;
    return *this;
  }
  mint& operator&=(const mint a) {
    x &= a.x;
    return (*this);
  }
  mint& operator|=(const mint a) {
    x |= a.x;
    return (*this);
  }
  mint& operator^=(const mint a) {
    x ^= a.x;
    return (*this);
  }
  mint& operator<<=(const mint a) {
    x *= pow(2, a).x;
    return (*this);
  }
  mint& operator>>=(const mint a) {
    x /= pow(2, a).x;
    return (*this);
  }

  /* 算術演算子 */
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
  mint operator%(const mint a) const {
    mint res(*this);
    return res %= a;
  }
  mint operator&(const mint a) const {
    mint res(*this);
    return res &= a;
  }
  mint operator|(const mint a) const {
    mint res(*this);
    return res |= a;
  }
  mint operator^(const mint a) const {
    mint res(*this);
    return res ^= a;
  }
  mint operator<<(const mint a) const {
    mint res(*this);
    return res <<= a;
  }
  mint operator>>(const mint a) const {
    mint res(*this);
    return res >>= a;
  }

  /* 条件演算子 */
  bool operator==(const mint a) const noexcept { return x == a.x; }
  bool operator!=(const mint a) const noexcept { return x != a.x; }
  bool operator<(const mint a) const noexcept { return x < a.x; }
  bool operator>(const mint a) const noexcept { return x > a.x; }
  bool operator<=(const mint a) const noexcept { return x <= a.x; }
  bool operator>=(const mint a) const noexcept { return x >= a.x; }

  /* ストリーム挿入演算子 */
  friend istream& operator>>(istream& is, mint& m) {
    is >> m.x;
    m.x = (m.x % MOD + MOD) % MOD;
    return is;
  }
  friend ostream& operator<<(ostream& os, const mint& m) {
    os << m.x;
    return os;
  }

  /* その他の関数 */
  mint modinv(mint a) { return pow(a, MOD - 2); }
  mint pow(mint x, mint n) {
    mint res = 1;
    while (n.x > 0) {
      if ((n % 2).x) res *= x;
      x *= x;
      n.x /= 2;
    }
    return res;
  }
};
int main(){
  string S;
  cin>>S;
  ll N=S.size(),ans=0;
  for(ll i=0;i<N;i++){
    if(S[i]=='U'){
      ans+=N-i-1;
      ans+=i*2;
    }else{
      ans+=(N-i-1)*2;
      ans+=i;
    }
  }
  cout<<ans<<endl;
}
