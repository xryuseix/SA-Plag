// 引用元 : https://atcoder.jp/contests/abc126/submissions/10483186
// 得点 : 600
// コード長 : 1954
// 実行時間 : 23


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define SIZE 300005
#define MOD 1000000007LL
#define EPS 1e-10
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DOWN(i,b,a) for(int i=b;i>=a;i--)
#define SET(a,c) memset(a,c,sizeof a)
#define BIT(i,j) ((i)>>(j))&1
#define ALL(o) (o).begin(), (o).end()
#define ERASE(o) (o).erase(unique((o).begin(),(o).end()), (o).end())
#define SQ(x) ((x)*(x))
using namespace std;
typedef int_fast64_t ll;
typedef pair<ll,ll> Pll;
typedef pair<int, int> Pii;
typedef pair<double, double> Pdd;
typedef complex<double> dcomplex;
template<typename T> inline void priv(vector<T>a){REP(i,a.size()){cerr<<a[i]<<((i==a.size()-1)?"\n":" ");}}
inline void fastio(){cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15);}
ll gcd(ll a,ll b){ll c=max(a,b);ll d=min(a,b);return c==0||d==0?c:gcd(c%d,d);}
ll lcm(ll a,ll b){return a==0||b==0?0:a*b/gcd(a,b);}
ll modfact(ll a){ll b=1;FOR(i,2,a)b=b*i%MOD;return b;}
ll modpow(ll a, ll n){ll b=1;while (n>0){if(n&1)b=b*a%MOD;a=a*a%MOD;n>>=1;}return b;}
ll modcomb(ll n, ll k){ll b=1;k=min(n-k,k);DOWN(i,n,n-k+1)b=b*i%MOD;return b*modpow(modfact(k),MOD-2)%MOD;}

int M, K;

class UnionFind {
public:
    // 親の番号を格納．親だった場合は-(その集合のサイズ)
    vector<int> Parent;
    // 重さの差を格納
    vector<ll> diffWeight;

    UnionFind(const int N) {
        Parent = vector<int>(N, -1);
        diffWeight = vector<ll>(N, 0);
    }

    // Aがどのグループに属しているか調べる
    int root(const int A) {
        if (Parent[A] < 0) return A;
        int Root = root(Parent[A]);
        diffWeight[A] += diffWeight[Parent[A]];
        return Parent[A] = Root;
    }

    // 自分のいるグループの頂点数を調べる
    int size(const int A) {
        return -Parent[root(A)];
    }

    // 自分の重さを調べる
    ll weight(const int A) {
        root(A); // 経路圧縮
        return diffWeight[A];
    }

    // 重さの差を計算する
    ll diff(const int A, const int B) {
        return weight(B) - weight(A);
    }

    // AとBをくっ付ける
    bool connect(int A, int B, ll W = 0) {
        // Wをrootとの重み差分に変更
        W += weight(A);
        W -= weight(B);

        // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);

        if (A == B) {
            //すでにくっついてるからくっ付けない
            return false;
        }

        // 大きい方(A)に小さいほう(B)をくっ付ける
        // 大小が逆だったらひっくり返す
        if (size(A) < size(B)) {
            swap(A, B);
            W = -W;
        }

        // Aのサイズを更新する
        Parent[A] += Parent[B];
        // Bの親をAに変更する
        Parent[B] = A;

        // AはBの親であることが確定しているのでBにWの重みを充てる
        diffWeight[B] = W;

        return true;
    }
};

int main() {
    fastio();
    cin >> M >> K;
    if((1 << M) <= K || (M == 1 && K == 1)) {
        printf("-1");
    	return 0;
    }
    if (M == 0 && K == 0) {
        printf("0 0");
        return 0;
    }
    if (M == 1 && K == 0) {
        printf("0 1 1 0");
        return 0;
    }
    printf("%d ", K);
    FOR(i, 0, K - 1) printf("%d ", i);
    FOR(i, K + 1, (1 << M) - 1) printf("%d ", i);
    printf("%d ", K);
    DOWN(i, (1 << M) - 1, K + 1) printf("%d ", i);
    DOWN(i, K - 1, 0) printf("%d ", i);
    return 0;
    
}
