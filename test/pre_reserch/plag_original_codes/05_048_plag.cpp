// 引用元 : https://atcoder.jp/contests/agc032/submissions/10044171
// 得点 : 400
// コード長 : 1118
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

static const int MAX = 1e6+15;
static const int NIL = -10192;
static const ll INF = 1<<20;
static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

int main(void) {
    int N;
    cin >> N;

    list<int> L;
    vector<int> ans(N);
    int b;
    for(int i=0;i<N;i++) {
        cin >> b;
        L.push_back(b);
    }

    int now_val, j;
    auto now_itr = L.begin();
    for(int i=0;i<N;i++) {
        j = 1;
        now_val = 0;
        now_itr = L.begin();
        for(auto itr=L.begin();itr!=L.end();++itr) {
            if(*itr==j) { 
                now_val = *itr;
                now_itr = itr;
            }
            j++;
        }
        if(now_val) {
            ans.at(i) = now_val;
            L.erase(now_itr);
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i=N-1;i>=0;i--) {
        cout << ans.at(i) << endl;
    }

    return 0;
}
