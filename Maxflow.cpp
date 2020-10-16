#ifndef _LIB_MAX_FLOW
#define _LIB_MAX_FLOW
#include "Graph.cpp"
#include <bits/stdc++.h>
// TODO: L-R flow

namespace lib {
using namespace std;
namespace flow {
template <typename T, typename E> struct Edge {
  T cap;
  bool original;
  E label;
};
template <typename T> struct Edge<T, void> {
  T cap;
  bool original;
};

template <typename T, typename E = void> struct Maxflow {
  typedef Maxflow<T, E> type;
  typedef Edge<T, E> flow_edge_type;
  typedef lib::graph::Graph<void, flow_edge_type> graph;
  using edge_type = typename graph::edge_type;

  graph g;
  int source, sink;
  vector<bool> visited;
  vector<int> dist;
  vector<size_t> used;

  explicit Maxflow(int n) : g(n), source(n - 2), sink(n - 1) { assert(n >= 2); }
  void setup(int a, int b) { source = a, sink = b; }
  void add_fake_edge(int u, int v, T weight) {
    g.add_edge(u, v) = {weight, false};
    g.add_edge(v, u) = {0, false};
  }
  template <typename S = E,
            typename enable_if<is_void<S>::value>::type * = nullptr>
  void add_edge(int u, int v, T weight = 1) {
    g.add_edge(u, v) = {weight, true};
    g.add_edge(v, u) = {0, true};
  }
  template <typename S = E,
            typename enable_if<!is_void<S>::value>::type * = nullptr>
  void add_edge(int u, int v, T weight = 1, S data = S()) {
    g.add_edge(u, v) = {weight, true, data};
    g.add_edge(v, u) = {0, true, S()};
  }
  inline int size() const { return g.size(); }
  inline int edge_size() const { return g.edge_size(); }
  edge_type reverse(int i) const { return g.edge(i ^ 1); }
  edge_type edge(int i) const { return g.edge(i); }
  flow_edge_type &flow_edge(int i) { return g.edge(i).data; }
  flow_edge_type &reverse_flow_edge(int i) { return g.edge(i ^ 1).data; }

  bool layered_bfs() {
    int n = size();
    dist.assign(n, -1);
    dist[source] = 0;
    vector<int> q;
    q.reserve(n);
    q.push_back(source);

    for (size_t i = 0; i < q.size(); i++) {
      int u = q[i];
      if (u == sink)
        break;
      for (const auto &e : g.n_edges(u)) {
        if (dist[e.to] == -1 && e.data.cap > 0) {
          dist[e.to] = dist[u] + 1;
          q.push_back(e.to);
        }
      }
    }

    return dist[sink] != -1;
  }

  T augmenting_path(const int u, const T bottle) {
    if (!bottle)
      return 0;
    if (u == sink)
      return bottle;
    for (size_t &i = used[u]; i < g.adj[u].size(); i++) {
      int x = g.adj[u][i];
      auto &e = g.edge(x);
      if (dist[e.to] != dist[u] + 1)
        continue;
      T cf = augmenting_path(e.to, min(bottle, e.data.cap));
      e.data.cap -= cf;
      g.edge(x ^ 1).data.cap += cf;
      if (cf)
        return cf;
    }
    return 0;
  }

  T blocking_flow() {
    if (!layered_bfs())
      return 0;
    used.assign(size(), 0);
    T aug, flow = 0;
    while ((aug = augmenting_path(source, numeric_limits<T>::max())))
      flow += aug;
    return flow;
  }

  T maxflow() {
    T aug, flow = 0;
    while ((aug = blocking_flow()))
      flow += aug;
    return flow;
  }

  vector<bool> mincut() const {
    int n = size();
    vector<bool> vis(n);
    vector<int> q;
    q.reserve(n);
    q.push_back(source);
    vis[source] = true;
    for (size_t i = 0; i < q.size(); i++) {
      int u = q[i];
      for (const auto &e : g.n_edges(u)) {
        if (e.data.cap > 0 && !vis[e.to]) {
          q.push_back(e.to);
          vis[e.to] = true;
        }
      }
    }
    return vis;
  }
};
} // namespace flow
} // namespace lib

#endif
