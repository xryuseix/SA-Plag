// 引用元 : https://atcoder.jp/contests/abc141/submissions/9434310
// 得点 : 300
// コード長 : 800
// 実行時間 : 15


#pragma gcc optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FOR(ii, aa, b) for (int ii = (aa); ii < (b); ++ii)
#define REPREP(ii, nn) for (int ii = 0; ii < (nn); ++ii)
#define SORT(V) sort((V).begin(),(V).end())
#define pb push_back
#define endl '\nn'
#define int long long

const int MOD = 1000000007;
const int INF = 1061109567;
const double EPS = 1e-10;
const double PI  = acos(-1.0);

// 変数定義
int nn,kk,qq;
//

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> nn >> kk >> qq;
  vector<int> aa(qq);
  vector<int> acac(nn);
  REPREP(ii, qq) {
    cin >> aa[ii];
    acac[aa[ii]-1]++; //正解数
  }
  REPREP(ii, nn) {
    if(kk-qq+acac[ii] > 0) {
      cout << "Yes" << endl;
    } else { 
      cout << "No" << endl;
    }
  }
}
