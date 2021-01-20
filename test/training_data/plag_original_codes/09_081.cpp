// 引用元 : https://atcoder.jp/contests/abc130/submissions/5963165
// 得点 : 300
// コード長 : 867
// 実行時間 : 1


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <string>
#include <random>
#include <stack>
#include <set>
#include <unordered_set>

#define bug(x) cout<<"zdongdebug: "<<x<<endl;
#define bug2(x, y) cout<<"zdongdebug: "<<x<<" "<<y<<endl;
using namespace std;
typedef unsigned long long ll;
const int maxn = 105;

int a[maxn];

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
  //freopen("/Users/suiyuan2009/CLionProjects/icpc/output.txt", "w", stdout);
#endif
  int w,h,x,y;
  cin>>w>>h>>x>>y;
  cout<<w*(double)h/2<<" ";
  bool f = (!(w&1))&&(!(h&1))&&(x==w/2)&&y==(h/2);
  cout<<f<<endl;
  return 0;
}
