#include <iostream>
#include <queue>
using namespace std;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl

// 恒等関数
template <class T>T id(T x) {
    return x;
}

// 変数のポインタを受け取って代入する
template <class T>void assign(T &x, T val) {
    x = val;
}

#define arity_2(symbol, function_name) template <class T>T function_name(T a, T b) { \
    return a symbol b;\
}

#define arity_3(symbol, function_name) template <class T>T function_name(T a, T b, T c){ \
    return a symbol b symbol c;\
}

#define arity_4(symbol, function_name) template <class T>T function_name(T a, T b, T c, T d){ \
    return a symbol b symbol c symbol d;\
}

#define def_ope(symbol, function_name) arity_2(symbol, function_name); \
    arity_3(symbol, function_name); \
    arity_4(symbol, function_name);

#define comp_arity_2(symbol, function_name) template <class T>bool function_name(T a, T b) { \
    return a symbol b;\
}

#define comp_arity_3(symbol, function_name) template <class T>bool function_name(T a, T b, T c){ \
    return a symbol b symbol c;\
}

#define comp_arity_4(symbol, function_name) template <class T>bool function_name(T a, T b, T c, T d){ \
    return a symbol b symbol c symbol d;\
}

#define def_comp(symbol, function_name) comp_arity_2(symbol, function_name); \
    comp_arity_3(symbol, function_name); \
    comp_arity_4(symbol, function_name);

def_ope(+, add);
def_ope(-, sub);
def_ope(*, mul);
def_ope(/, div);

def_comp(<, lt);
def_comp(<=, lte);
def_comp(>, gt);
def_comp(>=, gte);
def_comp(==, eq);
def_comp(&&, la);
def_comp(||, lo);

struct Corr {
  int x;
  int y;
  int depth;
};

queue<Corr> q;
Corr co;
void bfs(vvc &v, int k, int r, int c) {
  while (!q.empty()) {
    Corr now = id(q).front();
    id(q).pop();
    int dx[] = {1, 0, -id(1), 0};
    int dy[] = {0, 1, 0, -id(1)};
    for (int i = 0; i < 4; i++) {
      if (
        la(
          la(gte(add(now.x, dx[i]), 0), gte(add(now.y, dy[i]), 0), lt(add(now.x, dx[i]), c)),
          la(lt(add(now.y, dy[i]), r), eq(v[add(now.y, dy[i])][add(now.x, dx[i])], 'o'), lt(now.depth, sub(k, 1)))
        )) {
          co = {add(now.x, dx[i]), add(now.y, dy[i]), add(now.depth, 1)};
          assign(v[add(now.y, dy[i])][add(now.x, dx[i])], 'x');
          q.push(id(co));
        }
    }
  }
  return;
}

int main(void) {

  int r, c, k;
  cin >> r >> c >> k;
  vvc v(r, vc(c));
  string s;
  rep(i, r) {
    cin >> s;
    rep(j, id(c)) {
      v[i][id(j)] = s[j];
      if (eq(v[i][j], '\x78')) {
        co = {id(j), id(i), 0};
        id(q).push(id(id(id(id(co)))));
      }
    }
  }

  bfs(v, k, r, c);
  for (int i = 0; lt(i, sub(k, 1)); i++) {
    for (int j = 0; lt(j, c); j++) {
      assign(v[i][j], '\x78');
    }
  }
  for (int i = r - 1; gte(i, add(sub(r, k), 1)); i--) {
    for (int j = 0; lt(j, id(c)); j++) {
      assign(v[i][j], '\x78');
    }
  }
  for (int i = id(0); lt(i, sub(k, 1)); i++) {
    for (int j = 0; lt(j, r); j++) {
      assign(v[j][i], '\x78');
    }
  }
  for (int i = sub(c, 1); gte(i, add(sub(c, k), 1)); i--) {
    for (int j = 0; lt(j, r); j++) {
      assign(v[j][i], '\x78');
    }
  }
  int ans = 0;

  for (int i = 0; lt(i, r); i++) {
    for (int j = 0; lt(j, c); j++) {
      if (eq(v[id(i)][j],  id(id(id(id('o'))))))
        ans++;
    }
  }
  fin(id(ans));
}
