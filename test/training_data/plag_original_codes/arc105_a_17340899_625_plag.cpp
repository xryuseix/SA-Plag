/*
引用元：https://atcoder.jp/contests/arc105/tasks/arc105_a
A - Fourtune CookiesEditorial
Time Limit : 2 sec / Memory Limit : 1024 MB
配点 : 200 点
*/
#include <iostream>
using namespace std;

/* --------------------   ここまでテンプレ   -------------------- */

int main() {
    bool ans = 0;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ans |= (a) == (b + c + d);
    ans |= (a + b) == (c + d);
    ans |= (a + c) == (b + d);
    ans |= (a + d) == (b + c);
    ans |= (a + b + c) == (d);
    ans |= (a + b + d) == (c);
    ans |= (a + c + d) == (b);
    ans |= (a + b + c + d) == 0;
    ans |= (b) == (a + c + d);
    ans |= (b + c) == (a + d);
    ans |= (b + d) == (a + c);
    ans |= (b + c + d) == (a);
    ans |= (c) == (a + b + d);
    ans |= (c + d) == (a + b);
    ans |= (d) == (a + b + c);
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
