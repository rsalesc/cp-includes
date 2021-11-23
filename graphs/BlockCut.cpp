#ifndef _LIB_BLOCK_CUT
#define _LIB_BLOCK_CUT
#include <bits/stdc++.h>
#include "../Graph.cpp"
#include "../utils/LazyArray.cpp"

namespace lib {
  using namespace std;
namespace graph {
template<typename V, typename E>
struct BlockCut {
  int n, m;
  Graph<V, E> g;
  int tempo = 0;
  vector<int> vis, low, seen;
  vector<int> st;
  vector<vector<int>> comps;
  LazyArray<char> seen_v;

  Graph<V, E> g2;
  int n2 = 0;

  BlockCut(const Graph<V, E>& g) : g(g) {
    n = g.size();
    m = g.edge_size();
    vis = low = vector<int>(n);
    seen = vector<int>(m);
    st.reserve(m);
    comps.reserve(n);
    seen_v = LazyArray<char>(n, 0);

    g2 = Graph<V, E>(n);

    for(int i = 0; i < n; i++) {
      if(!vis[i]) tarjan(i, -1);
    }
  }
  Graph<V, E> graph() const { return g2; }
  vector<int> get_vertices_(const vector<int>& e) {
    seen_v.clear();
    vector<int> comp;
    for(int kk : e) {
      auto ed = g.edge(kk);
      if(!seen_v.get(ed.from)) comp.push_back(ed.from), seen_v[ed.from] = true;
      if(!seen_v.get(ed.to)) comp.push_back(ed.to), seen_v[ed.to] = true;
    }
    return comp;
  }
  void process_component_(int k) {
    vector<int> e;
    int cur;
    do {
      cur = st.back(); st.pop_back();
      e.push_back(cur);
    } while(cur != k);
    auto comp = get_vertices_(e);
    g2.add_vertex();
    for(int w : comp) {
      g2.add_2edge(n + n2, w);
    }
    n2++;
  }
  void tarjan(int u, int p) {
    vis[u] = low[u] = ++tempo;
    auto nei = g.n_edges(u);
    for(int i = 0; i < nei.size(); i++) {
      int k = nei.index(i);
      int v = g.edge(k).to;
      if(v == p) continue;

      if(!seen[k]) {
        seen[k] = seen[k^1] = 1;
        st.push_back(k);
      }

      if(!vis[v]) {
        tarjan(v, u);
        low[u] = min(low[u], low[v]);

        if(low[v] >= vis[u]) {
          process_component_(k);
        }
      } else {
        low[u] = min(low[u], vis[v]);
      }
    }
  }
};

template<typename V, typename E>
BlockCut<V, E> make_block_cut(const Graph<V, E>& g) {
  return BlockCut<V, E>(g);
}
} // namespace graph
} // namespace lib

#endif