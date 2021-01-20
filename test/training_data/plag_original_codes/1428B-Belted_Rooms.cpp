#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef set<int> si;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define arep(i, v) for (auto i : v)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define fi first
#define se second
// #include <atcoder/all>
// using namespace atcoder;
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline void dump(T &v) {
  irep(i, v) { cout << (*i) << ((i == --v.end()) ? '\n' : ' '); }
}
template <class T, class U> inline void dump(map<T, U> &v) {
  irep(i, v) { cout << i->first << " " << i->second << '\n'; }
}
inline string getline() {
  string s;
  getline(cin, s);
  return s;
}
inline void yn(const bool b) { b ? fin("yes") : fin("no"); }
inline void Yn(const bool b) { b ? fin("Yes") : fin("No"); }
inline void YN(const bool b) { b ? fin("YES") : fin("NO"); }
struct io {
  io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  }
};
template <typename Head, typename Value>
auto vectors(const Head &head, const Value &v) {
  return vector<Value>(head, v);
}
template <typename Head, typename... Tail> auto vectors(Head x, Tail... tail) {
  auto inner = vectors(tail...);
  return vector<decltype(inner)>(x, inner);
}
const int INF = INT_MAX;
constexpr ll LLINF = 1LL << 61;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

/* --------------------   ここまでテンプレ   -------------------- */

class StronglyConnectedComponent {
public:
  int V;          // 頂点数
  int SubGraph;   // 強連結成分の数
  vvi Graph;      // グラフの隣接リスト表現
  vvi revGraph;   // 辺の向きを逆にしたグラフ
  vvi SmallGraph; // 強連結成分分解によって縮めたグラフ
  vi dfsline;     // 帰りがけ順の並び
  vi compo;       // cmp[i]で頂点iの属するグループ
  vb used;        // すでに調べたか

  StronglyConnectedComponent(int v) {
    V = v;
    Graph = vvi(v);
    revGraph = vvi(v);
    used = vb(v);
    compo = vi(v);
  }

  int operator[](int k) {
    // scc[i]でi番目の頂点のグループ番号を返す
    return compo[k];
  }

  void add_edge(int from, int to) {
    Graph[from].push_back(to);
    revGraph[to].push_back(from);
  }

  void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < Graph[v].size(); i++) {
      if (!used[Graph[v][i]])
        dfs(Graph[v][i]);
    }
    dfsline.push_back(v);
  }

  void revdfs(int v, int k) {
    used[v] = true;
    compo[v] = k;
    for (int i = 0; i < revGraph[v].size(); i++) {
      if (!used[revGraph[v][i]])
        revdfs(revGraph[v][i], k);
    }
  }

  int scc(void) {
    used = vb((int)used.size(), false);
    dfsline.clear();
    for (int v = 0; v < V; v++) {
      if (!used[v])
        dfs(v);
    }
    used = vb(used.size(), false);
    SubGraph = 0;
    for (int i = dfsline.size() - 1; i >= 0; i--) {
      if (!used[dfsline[i]])
        revdfs(dfsline[i], SubGraph++);
    }
    for (int i = 0; i < compo.size(); i++) {
      compo[i] = SubGraph - compo[i] - 1;
    }
    return SubGraph;
  }

  void build(void) {
    // 縮めたグラフを構築する
    SmallGraph = vvi(SubGraph);
    for (int i = 0; i < Graph.size(); i++) {
      for (int j = 0; j < Graph[i].size(); j++) {
        int to = Graph[i][j];
        int s = compo[i], t = compo[to];
        if (s != t) {
          SmallGraph[s].push_back(t);
        }
      }
    }
    for (int i = 0; i < SmallGraph.size(); i++) {
      // 被った辺を削除
      SmallGraph[i].erase(unique(SmallGraph[i].begin(), SmallGraph[i].end()),
                          SmallGraph[i].end());
    }
  }

  void show_set_to_edge(void) {
    for (int i = 0; i < SmallGraph.size(); i++) {
      cout << "集合" << i << "から出ている辺 : ";
      for (int j = 0; j < SmallGraph[i].size(); j++) {
        cout << SmallGraph[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }

  void show_group_of_node(void) {
    for (int i = 0; i < V; i++) {
      cout << "頂点" << i << "の属するグループ : " << compo[i] << endl;
    }
    cout << endl;
  }

  int show_node_in_group(void) {
    vvi group(SubGraph);
    for (int i = 0; i < compo.size(); i++) {
      group[compo[i]].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < SmallGraph.size(); i++) {
      // cout << "グループ" << i << "に属する頂点 : ";
      if (group[i].size() == 1)
        ans++;
      // for (int j = 0; j < group[i].size(); j++) {
      //     cout << group[i][j] << ' ';
      // }
      // cout << endl;
    }
    // cout << endl;
    return ans;
  }
};

int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    StronglyConnectedComponent scc(n);
    rep(i, n) {
      if (s[i] == '>' || s[i] == '-') {
        scc.add_edge(i, (i + 1) % n);
        // cout<<i<<" "<< (i + 1) % n<<endl;
      }
      if (s[(i - 1 + n) % n] == '<' || s[(i - 1 + n) % n] == '-') {
        scc.add_edge(i, (i - 1 + n) % n);
        // cout<<i<<" "<< (i - 1+n) % n<<endl;
      }
    }
    scc.scc();
    scc.build();
    fin(n - scc.show_node_in_group());
  }
}
