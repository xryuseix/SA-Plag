/*
引用元：https://atcoder.jp/contests/cf17-final/tasks/cf17_final_a
A - AKIBAEditorial
// ソースコードの引用元 :
https://atcoder.jp/contests/cf17-final/submissions/5868399
// 提出ID : 5868399
// 問題ID : cf17_final_a
// コンテストID : cf17-final
// ユーザID : xryuseix
// コード長 : 1767
// 実行時間 : 1



*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
#define vi vector<int>
using namespace std;

string STR = "KIHBR";

int main(void) {
    string s, kib = "";
    cin >> s;
    rep(i, s.length()) if (s[i] != 'A') kib += s[i];
    if (kib != STR) {
        fin("NO");
        return 0;
    } else {
        rep(i, s.length() - 1) if (s[i] == s[i + 1] && s[i] == 'A') {
            fin("NO");
            return 0;
        }
        rep(i, s.length()) {
            if (s[i] == 'I' && s[i + 1] != 'H') {
                fin("NO");
                return 0;
            }
            if (s[i] == 'K' && s[i + 1] != 'I') {
                fin("NO");
                return 0;
            }
        }
        fin("YES");
    }
}
