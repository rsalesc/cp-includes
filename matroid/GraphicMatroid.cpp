#ifndef _LIB_GRAPHIC_MATROID
#define _LIB_GRAPHIC_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"
#include "../utils/FastAdj.cpp"

namespace lib {
  using namespace std;
struct GraphicMatroid : Matroid {
  lambda::Map<pair<int, int>> edge;
  FastAdj<pair<int, int>> g;
  vector<int> comp, st, nd, low;
  vector<int> bridges;
  int tempo, comps;
  bool printer = true;

  GraphicMatroid(int n, const lambda::Map<pair<int, int>>& edge_)
    : Matroid(), edge(edge_), g(n, n) {}
  void setup() {
    g.clear();
    g.reserve(ground_set_size());
    for(int i = 0; i < ground_set_size(); i++)
      if(in_I(i)) {
        auto p = edge(i);
        g.add(p.first, {p.second, i});
        g.add(p.second, {p.first, i});
      }
    build_graph();
  }
  void build_graph() {
    int n = g.size();
    comp.assign(n, -1);
    st.assign(n, 0);
    nd.assign(n, 0);
    low.assign(n, 0);
    bridges.assign(ground_set_size(), 0);

    tempo = 0;
    comps = 0;
    for(int i = 0; i < n; i++) {
      if(comp[i] == -1) dfs(i, -1, comps++);
    }
  }
  void dfs(int u, int p, int c) {
    comp[u] = c;
    st[u] = low[u] = tempo++;
    for(auto e : g.n_edges(u)) {
      int v = e.first;
      if(v == p) {
        p = -1;
        continue;
      }
      if(comp[v] != -1) low[u] = min(low[u], st[v]);
      else {
        dfs(v, u, c);
        low[u] = min(low[u], low[v]);
        if(low[v] > st[u]) {
          bridges[e.second] = 1;
        }
      }
    }
    nd[u] = tempo++;
  }
  bool is_bridge(int i) {
    return bridges[i];
  }
  bool is_anc(int u, int v) {
    return st[u] <= st[v] && st[v] <= nd[u];
  }
  bool can_exchange(int i, int j) {
    auto e1 = edge(i);
    auto e2 = edge(j);
    if(st[e1.first] > st[e1.second]) swap(e1.first, e1.second);
    return is_anc(e1.second, e2.first) + is_anc(e1.second, e2.second) == 1;
  }
  bool can_add(int i) {
    auto e = edge(i);
    return comp[e.first] != comp[e.second];
  }
};
} // namespace lib

#endif
