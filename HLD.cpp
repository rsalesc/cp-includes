#ifndef _LIB_HLD
#define _LIB_HLD
#include <bits/stdc++.h>
#include "Graph.cpp"
#include "Segtree.cpp"
#include "Traits.cpp"

namespace lib {
  using namespace std;
namespace graph {
  namespace {
    void empty_lifter(int a, int b, bool inv) {}
  }

  template<typename G>
  struct HLD {
    G graph;
    vector<int> in, out, rin;
    vector<int> L, sz, ch;
    int tempo;

    HLD(const G& g) 
      : graph(g), in(g.size()), out(g.size()), rin(g.size()), L(g.size()),
        sz(g.size()), ch(g.size()) {
        build();
    }

    inline int size() const { return graph.size(); }

    void dfs0(int u) {
      sz[u] = 1;
      for(auto& k : graph.adj[u]) {
        int v = graph.edge(k).to;
        L[v] = L[u] + 1;
        dfs0(v);
        if(sz[v] > sz[graph.edge(graph.adj[u][0]).to])
          swap(k, graph.adj[u][0]);
        sz[u] += sz[v];
      }
    }

    void dfs1(int u) {
      in[u] = tempo++;
      rin[in[u]] = u;

      if(graph.adj[u].size() > 0) {
        int v = graph.edge(graph.adj[u][0]).to;
        ch[v] = ch[u];
        dfs1(v);
        for(size_t i = 1; i < graph.adj[u].size(); i++) {
          v = graph.edge(graph.adj[u][i]).to;
          ch[v] = v;
          dfs1(v);
        }
      }
      out[u] = tempo;
    }

    void build() {
      vector<int> roots = graph.roots();
      for(int i : roots) dfs0(i);
      tempo = 0;
      for(int i : roots) dfs1(i);
    }

    template<typename Lifter>
    inline void operate_on_subtree(int u, Lifter& lifter) {
      lifter(in[u], out[u]-1, false);
    }

    template<typename T, typename QueryIssuer>
    inline T query_on_subtree(int u, const QueryIssuer& issuer) {
      return issuer(in[u], out[u]-1);
    }

    template<typename Lifter>
    inline void operate_on_subtree_edges(int u, Lifter& lifter) {
      if(in[u]+2 <= out[u]) lifter(in[u]+1, out[u]-1, false);
    }

    template<typename T, typename QueryIssuer>
    inline void query_on_subtree_edges(int u, const QueryIssuer& issuer) {
      assert(in[u]+2 <= out[u]);
      return issuer(in[u]+1, out[u]-1);
    }

    template<bool is_edge, typename Lifter>
    int _query_path(int u, int v, Lifter& lifter) {
      int inv = 0;
      for(; ch[u] != ch[v]; u = graph.parent(ch[u])) {
        if(L[ch[u]] < L[ch[v]])
          swap(u, v), inv ^= 1;
        lifter(in[ch[u]], in[u], (bool)inv);
      }
      if(L[u] > L[v]) swap(u, v), inv ^= 1;
      inv ^= 1;
      if(is_edge && in[u]+1 <= in[v])
        lifter(in[u]+1, in[v], (bool)inv);
      else if(!is_edge)
        lifter(in[u], in[v], (bool)inv);
      return u;
    }

    template<typename Lifter>
    inline int operate_on_path(int u, int v, Lifter& lifter) {
      return _query_path<false>(u, v, lifter);
    }

    template<typename Lifter>
    inline int operate_on_path_edges(int u, int v, Lifter& lifter) {
      return _query_path<true>(u, v, lifter);
    }

    template<typename Op>
    inline void operate_on_vertex(int u, Op& op) {
      op(in[u]);
    }

    template<typename T, typename QueryIssuer>
    inline T query_on_vertex(int u, const QueryIssuer& issuer) {
      return issuer(in[u]);
    }

    inline int lca(int u, int v) {
      return _query_path<false>(u, v, empty_lifter);
    }

    inline int dist(int u, int v) {
      int uv = lca(u, v);
      return L[u] + L[v] - 2*L[uv];
    }
  };

  template<typename G>
  HLD<G> make_hld(const G& graph) {
    return HLD<G>(graph);
  }
}  // namespace graph
}  // namespace lib

#endif
