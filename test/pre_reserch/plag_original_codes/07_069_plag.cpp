// 引用元 : https://atcoder.jp/contests/abc093/submissions/6478251
// 得点 : 300
// コード長 : 1216
// 実行時間 : 1


#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ALL(x)      (x).begin(),(x).end()
#define REP(i,n)    for(int i=0;i<(n);i++)
#define REP1(i,n)   for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n)   for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))
 
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
 
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
 
const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};
std::mt19937 mt{ std::random_device{}() };
std::uniform_int_distribution<int> dist(129, INF);
const int BASE = dist(mt);

class RollingHash {
public:
    string str;
    vector<ull> powBase, csumHash;
    const ull ROLMOD = (1LL << 61) - 1;
    const ull MASK30 = (1LL << 30) - 1;
    const ull MASK31 = (1LL << 31) - 1;
    const ull LLMAX = ROLMOD*((1LL << 3) - 1);

    RollingHash(const string s) : str(s) {
        powBase.resize(s.size() + 1);
        csumHash.resize(s.size() + 1);
        powBase[0] = 1;
        for(int i = 0; i < s.size(); i++) {
            powBase[i + 1] = calcMod(multiple(powBase[i], BASE));
        }
    }

    void rollingHash() {
        csumHash[0] = 0;
        for(int i = 0; i < str.size(); ++i) {
            csumHash[i + 1] = calcMod(multiple(csumHash[i], BASE) + str[i]);
        }
    }

    ull getHash(const int begin, const int length) {
        return calcMod(csumHash[begin + length] + LLMAX - multiple(csumHash[begin], powBase[length]));
    }

    string substr(const int begin) {
        return str.substr(begin);
    }

    string substr(const int begin, const int length) {
        if(length < 0) {
            return str.substr(begin, str.size() + length - begin + 1);
        } else {
            return str.substr(begin, length);
        }
    }

private:
    ull calcMod(const ull num) {
        const ull modNum = (num & ROLMOD) + (num >> 61);
        return (modNum >= ROLMOD) ? modNum - ROLMOD : modNum;
    }

    ull multiple(const ull leftNum, const ull rightNum) {
        ull lu = leftNum >> 31;
        ull ld = leftNum & MASK31;
        ull ru = rightNum >> 31;
        ull rd = rightNum & MASK31;
        ull middleBit = ld * ru + lu * rd;
        return ((lu * ru) << 1) + ld * rd + ((middleBit & MASK30) << 31) + (middleBit >> 30);
    }

};
void solve(long long A, long long B, long long C){
    VLL memo;
    memo.PB(A);
    memo.PB(B);
    memo.PB(C);

    sort(ALL(memo));

    LL ans = memo[2] - memo[1] + memo[2] - memo[0];
    if(ans % 2 == 1) ans+=3;
    cout << ans / 2 << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    solve(A, B, C);
    return 0;
}
