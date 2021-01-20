// 引用元 : https://atcoder.jp/contests/abc095/submissions/5998366
// 得点 : 300
// コード長 : 346
// 実行時間 : 1


#include <iostream>
using namespace std;
int main(){
    long kujkhk,asas,agfga,asasa,yyyy;
    cin >> kujkhk >> asas >> agfga >> asasa >> yyyy;
    long afhhgadfhgdfg = kujkhk*asasa + asas*yyyy;
    if(asasa>=yyyy){
        afhhgadfhgdfg = min(2*agfga*asasa,afhhgadfhgdfg);
        afhhgadfhgdfg = min(2*agfga*yyyy+(asasa-yyyy)*kujkhk,afhhgadfhgdfg);
    }
    else{
        afhhgadfhgdfg = min(2*agfga*asasa+(yyyy-asasa)*asas,afhhgadfhgdfg);
        afhhgadfhgdfg = min(2*agfga*yyyy,afhhgadfhgdfg);
    }
    cout << afhhgadfhgdfg << endl;
}
