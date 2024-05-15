#ifndef _LIB_REROOTING
#define _LIB_REROOTING
#include "Graph.cpp"
#include "traits/Operators.cpp"
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
      dp[u] = combiner.take(dp[u], dp[ed.to], ed);
    }
    dp[u] = combiner.finalize(dp[u], u);
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
      pref[i] = combiner.take(pref[i-1], dp[iiv], adj[i-1]);
      suf[j] = combiner.take(suf[j+1], dp[jjv], adj[j+1]);
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
      ans[u] = combiner.take(exc[0], dp[ed.to], ed);
      ans[u] = combiner.finalize(ans[u], u);
    }
    typename Graph<V, E>::iterable adj = graph.n_edges(u);
    for (int i = 0; i < adj.size(); i++) {
      if (adj[i].to == p) continue;
      dp[u] = combiner.finalize(exc[i], u);
      self(self, adj[i].to, u);
    }
  };

  for (int root : roots) dfs2(dfs2, root, -1);

  return ans;
}

template<typename Elem, typename V, typename E>
struct RerootCombinerParams {
  using edge_type = typename Graph<V, E>::edge_type;

  using InitFn = std::function<Elem()>;
  using MergeFn = std::function<Elem(const Elem&, const Elem&)>;
  using TakeFn = std::function<Elem(const Elem&, const Elem&, const edge_type&)>;
  using TakeAndMergeFn = std::function<Elem(const Elem&, const edge_type&)>;
  using FinalizeFn = std::function<Elem(const Elem&, int)>;

  std::optional<InitFn> init;
  std::optional<MergeFn> merge;
  std::optional<TakeFn> take;
  std::optional<TakeAndMergeFn> take_and_merge;
  std::optional<FinalizeFn> finalize;
};

template<typename Elem, typename V, typename E>
struct RerootCombinerFromParams {
  using edge_type = typename Graph<V, E>::edge_type;

  RerootCombinerFromParams(const RerootCombinerParams<Elem, V, E>& params) : params(params) {}

  Elem init() const { return params.init.value()(); }
  Elem merge(const Elem& a, const Elem& b) const { return params.merge.value()(a, b); }
  Elem take(const Elem&a, const Elem&b, const edge_type& c) const { return params.take.value()(a, b, c); }
  Elem finalize(const Elem& a, int b) const { return params.finalize.value()(a, b); }

  RerootCombinerParams<Elem, V, E> params;
};

template<typename Elem, typename V, typename E>
RerootCombinerParams<Elem, V, E>
make_reroot_params(const Graph<V, E>&) {
  return RerootCombinerParams<Elem, V, E>();
}

template<typename Elem, typename V, typename E>
RerootCombinerFromParams<Elem, V, E>
make_reroot_combiner(const Graph<V, E>&, RerootCombinerParams<Elem, V, E> params) {
  using edge_type = typename Graph<V, E>::edge_type;

  if (params.init == std::nullopt) {
    if constexpr (std::is_default_constructible<Elem>::value) {
      params.init = []() { return Elem(); };
    } else {
      assert(false && "Combiner .init is necessary if Elem is not default-constructible.");
    }
  }

  if (params.merge == std::nullopt) {
    if constexpr (traits::has_add_operator<Elem>::value) {
      params.merge = [](const Elem& a, const Elem& b) { return a + b; };
    } else {
      assert(false && "Combiner .merge is necessary if Elem does not define operator+.");
    }
  }

  if (params.take == std::nullopt) {
    if (params.take_and_merge != std::nullopt) {
      params.take = [&params](const Elem& a, const Elem& b, const edge_type& ed) {
        return params.merge.value()(a, params.take_and_merge.value()(b, ed));
      };
    } else {
      params.take = [&params](const Elem& a, const Elem& b, const edge_type&) {
        return params.merge.value()(a, b);
      };
    }
  }

  if (params.finalize == std::nullopt) {
    params.finalize = [](const Elem& x, int) { return x; };
  }

  return RerootCombinerFromParams(std::move(params));
}

template<typename Elem, typename V, typename E>
auto reroot_with_params(const Graph<V, E>& g, RerootCombinerParams<Elem, V, E> params) {
  auto combiner = make_reroot_combiner(g, params);
  return reroot(g, combiner);
}

} // namespace graph
} // namespace lib

#endif