#ifndef _LIB_REROOTING
#define _LIB_REROOTING
#include "Graph.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace graph {
template<typename Combiner, typename V, typename E>
auto reroot(const Graph<V, E>& graph, const Combiner& combiner) {
  using Elem = decltype(combiner.init());

  int n = graph.size();
  vector<Elem> dp(n, combiner.init());
  vector<int> seen(n);
  auto dfs1 = [&](auto&& self, int u, int p) -> void {
    seen[u] = true;
    for (const auto& ed : graph.n_edges(u)) {
      if (ed.to == p) continue;
      self(self, ed.to, u);
      dp[u] = combiner.take(dp[u], dp[ed.to], ed, graph.vertex(ed.from), graph.vertex(ed.to));
    }
    dp[u] = combiner.finalize(dp[u], graph.vertex(u));
  };
  
  vector<int> roots;
  for(int i = 0; i < n; i++) if (!seen[i]) {
    roots.push_back(i);
    dfs1(dfs1, i, -1);
  }

  auto exclusive = [&](int u) {
    int deg = graph.degree(u);
    vector<Elem> exc(deg, combiner.init()),
                 pref(deg, combiner.init()),
                 suf(deg, combiner.init());
    typename Graph<V, E>::iterable adj = graph.n_edges(u);
    for (int i = 1; i < deg; i++) {
      int j = deg - i - 1;
      int iiv = adj[i-1].to;
      int jjv = adj[j+1].to; 
      pref[i] = combiner.take(pref[i-1], dp[iiv], adj[i-1], graph.vertex(u), graph.vertex(iiv));
      suf[j] = combiner.take(suf[j+1], dp[jjv], adj[j+1], graph.vertex(u), graph.vertex(jjv));
    }

    for(int i = 0; i < deg; i++) {
      exc[i] = combiner.merge(pref[i], suf[i]);
    }
    return exc;
  };

  vector<Elem> ans(n, combiner.init());
  // dfs2(u, ...) assumes every dfs1(v, u) for v adjacent to u is computed, finalized
  // and stored in dp[v] beforehand
  auto dfs2 = [&](auto&& self, int u, int p) -> void {
    vector<Elem> exc = exclusive(u);
    if (graph.degree(u) > 0) {
      const auto& ed = graph.n_edges(u)[0];
      ans[u] = combiner.take(exc[0], dp[ed.to], ed, graph.vertex(ed.from), graph.vertex(ed.to));
      ans[u] = combiner.finalize(ans[u], graph.vertex(u));
    }
    typename Graph<V, E>::iterable adj = graph.n_edges(u);
    for (int i = 0; i < adj.size(); i++) {
      if (adj[i].to == p) continue;
      dp[u] = combiner.finalize(exc[i], graph.vertex(u));
      self(self, adj[i].to, u);
    }
  };

  for (int root : roots) dfs2(dfs2, root, -1);

  return ans;
}
} // namespace graph
} // namespace lib

#endif