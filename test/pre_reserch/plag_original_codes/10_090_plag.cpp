// 引用元 : https://atcoder.jp/contests/abc064/submissions/9437384
// 得点 : 400
// コード長 : 948
// 実行時間 : 1


#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 9999999999;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return a;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }


int n;
int parL=0, parR=0;
string s;
int main() {
  cin >>n;
  cin >>s;

  for (int i=0; i<n; i++){
    if (s.at(i) == '('){
      ++parR;
    }else if (s.at(i) == ')'){
      if (parR == 0) ++parL;
      else --parR;
    }
  }
  for (int i=0; i<parL; i++) cout <<'(';
  cout <<s;
  for (int i=0; i<parR; i++) cout <<')';
  cout <<endl;
}
