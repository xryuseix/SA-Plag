// 引用元 : https://atcoder.jp/contests/abc137/submissions/6820151
// 得点 : 300
// コード長 : 642
// 実行時間 : 127


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
  int dhjlfgadhfkashdfkjasdklhasdj;
  cin >> dhjlfgadhfkashdfkjasdklhasdj;
  vector<string> kjlgfdsdkjfhskdhflas(dhjlfgadhfkashdfkjasdklhasdj);
  for (int asdjhfsadfgakusd = 0; asdjhfsadfgakusd < dhjlfgadhfkashdfkjasdklhasdj; ++asdjhfsadfgakusd) {
    cin >> kjlgfdsdkjfhskdhflas[asdjhfsadfgakusd];
    sort(kjlgfdsdkjfhskdhflas[asdjhfsadfgakusd].begin(), kjlgfdsdkjfhskdhflas[asdjhfsadfgakusd].end());
  }
  sort(kjlgfdsdkjfhskdhflas.begin(), kjlgfdsdkjfhskdhflas.end());
  
  unsigned long long adshflsjadhfkjasdh = 0;
  unsigned long long bvicouvyvxcouvixo = 0;
  int adsfasdiflaskjhkas = 0;
  for (int asdjhfsadfgakusd = 1; asdjhfsadfgakusd < dhjlfgadhfkashdfkjasdklhasdj; ++asdjhfsadfgakusd) {
    if (kjlgfdsdkjfhskdhflas[asdjhfsadfgakusd] == kjlgfdsdkjfhskdhflas[asdjhfsadfgakusd-1]) {
      ++adsfasdiflaskjhkas;
      bvicouvyvxcouvixo = bvicouvyvxcouvixo + adsfasdiflaskjhkas;
    }
    else {
      if (bvicouvyvxcouvixo != 0) {
        adshflsjadhfkjasdh += bvicouvyvxcouvixo;
        bvicouvyvxcouvixo = 0;
        adsfasdiflaskjhkas = 0;
      }
    }
  }
  adshflsjadhfkjasdh += bvicouvyvxcouvixo;
  cout << adshflsjadhfkjasdh << endl;
  return 0;
}
