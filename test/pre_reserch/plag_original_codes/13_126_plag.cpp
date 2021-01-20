// 引用元 : https://atcoder.jp/contests/abc120/submissions/6476871
// 得点 : 400
// コード長 : 1139
// 実行時間 : 28


#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;
vector<int> par;

int root(int x){
    return par[x] < 0 ? x : par[x] = root(par[x]);
}

long long merge(int x, int y){
    x = root(x);
    y = root(y);
    
    if (x != y){
        if (par[x] > par[y])
            swap(x, y);
        
        long long ret = 1LL * par[x] * par[y];
        par[x] += par[y];
        par[y] = x;

        return ret;
    }

    return 0;
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> p;
    for (int i = 0; i < m; i++){
        pair<int, int> pp;
        cin >> pp.first >> pp.second;
        p.push_back(pp);
    }

    par=vector<int>(n);
    
    vector<long long> ans;
    long long cnt = (long long) n * (n - 1) / 2;
    for (int i = m - 1; i >= 0; i--){
        ans.push_back(cnt);
        cnt -= merge(p[i].first, p[i].second);
    }

    reverse(ans.begin(), ans.end());
    for (auto i: ans)
        cout << i << endl;

    return 0;
}
