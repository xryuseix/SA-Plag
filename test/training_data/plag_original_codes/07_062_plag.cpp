// 引用元 : https://atcoder.jp/contests/agc003/submissions/1125179
// 得点 : 400
// コード長 : 361
// 実行時間 : 58


#include <iostream>
using namespace std;
// 頂点fromから頂点toへのコストcostの辺
struct bf_edge {
    int from;
    int to;
    int cost;
};

class Bellman_Ford{
public:
    vector<bf_edge> es; // 辺
    vector<int> d; // d[i]...頂点sから頂点iまでの最短距離
    int V, E; // Vは頂点数、Eは辺数

    Bellman_Ford(int v, int e) {
        V = v;
        E = e;
        d = vector<int>(v);
    }

    void add(int from, int to, int cost) {
        bf_edge ed = {from, to, cost};
        es.push_back(ed);
    }

    // s番目の頂点から各頂点への最短距離を求める
    // trueなら負の閉路が存在する
    bool shortest_path(int s) {
        for(int i = 0; i < V; i++) {
            d[i] = 0;
        }
        for (int i = 0; i < 3*V; i++) {
            for(int j = 0; j < E; j++) {
                bf_edge e = es[j];
                if(d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;

                    // 3n回目にも更新があるなら負の閉路が存在する
                    if(i == V - 1)return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    int n; cin>>n;
    int a[n]; for(e: a) cin>>e;

    long res=0;
    int c=0;
    for(int e: a) {
        if (e==0) {
            c=0;
        }
        else {
            res+=c;
            e-=c;
            res+=e/2;
            c=e%2;
        }
    }
    cout<<res<<endl;
}

