// 引用元 : https://atcoder.jp/contests/abc053/submissions/5998272
// 得点 : 300
// コード長 : 1128
// 実行時間 : 1


#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using ll = long long ;
class DIJKSTRA {
public:
	int V;

	struct dk_edge {
		int to;
		ll cost;
	};

	typedef pair<ll, int> PI;  // firstは最短距離、secondは頂点の番号
	vector<vector<dk_edge> > G;
	vector<ll> d;      //これ答え。d[i]:=V[i]までの最短距離
	vector<int> prev;  //経路復元

	DIJKSTRA(int size) {
		V = size;
		G = vector<vector<dk_edge> >(V);
		prev = vector<int>(V, -1);
	}

	void add(int from, int to, ll cost) {
		dk_edge e = {to, cost};
		G[from].push_back(e);
	}

	void dijkstra(int s) {
		// greater<P>を指定することでfirstが小さい順に取り出せるようにする
		priority_queue<PI, vector<PI>, greater<PI> > que;
		d = vector<ll>(V, LLINF);
		d[s] = 0;
		que.push(PI(0, s));

		while (!que.empty()) {
			PI p = que.top();
			que.pop();
			int v = p.second;
			if (d[v] < p.first) continue;
			for (int i = 0; i < G[v].size(); i++) {
				dk_edge e = G[v][i];
				if (d[e.to] > d[v] + e.cost) {
					d[e.to] = d[v] + e.cost;
					prev[e.to] = v;
					que.push(PI(d[e.to], e.to));
				}
			}
		}
	}
	vector<int> get_path(int t) {
		vector<int> path;
		for (; t != -1; t = prev[t]) {
			// tがsになるまでprev[t]をたどっていく
			path.push_back(t);
		}
		//このままだとt->sの順になっているので逆順にする
		reverse(path.begin(), path.end());
		return path;
	}
	void show(void) {
		for (int i = 0; i < d.size() - 1; i++) {
			cout << d[i] << " ";
		}
		cout << d[d.size() - 1] << endl;
	}
};
int main(){
	ll x ;
	cin >> x ;
	ll ans = x / 11 * 2;
	if ( x % 11 > 6 ) ans+=2 ;
	else if ( x % 11 > 0 ) ans++ ;
	cout << ans << endl;
	return 0 ;
}
