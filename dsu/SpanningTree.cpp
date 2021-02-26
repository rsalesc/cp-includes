#ifndef _LIB_DSU_SPANNING_TREE
#define _LIB_DSU_SPANNING_TREE
#include <bits/stdc++.h>
#include "../utils/LazyArray.cpp"

namespace lib {
using namespace std;
namespace dsu {

const auto no_op_visitor = [](int, int, const vector<int>&) -> void {};

template<typename D>
struct SpanningTree : public D {
  using D::last_swapped_;

  vector<vector<int>> adj;
  vector<int> pai, depth;
  LazyArray<char> vis;
  pair<int, int> last_edge_;

  SpanningTree() : D() {}
  SpanningTree(int n) : D(n), adj(n), pai(n, -1), vis(n, 0), depth(n, 0) {}
  virtual void clear() override {
    D::clear();
    for(int i = 0; i < adj.size(); i++)
      adj[i].clear();
    fill(pai.begin(), pai.end(), -1);
    fill(depth.begin(), depth.end(), 0);
    vis.clear();
    last_edge_ = {-1, -1};
  }
  virtual int merge(int u, int v) override {
    if(!D::merge(u, v)) return 0;
    if(last_swapped_)
      swap(u, v);
    last_edge_ = {u, v};
    vis.clear();
    fix_(u, v, depth[v]+1);
    adj[u].push_back(v);
    adj[v].push_back(u);
    return 1;
  }
  template<typename F, typename G>
  void traverse_last_small(const F& f, const G& g) {
    vis.clear();
    traverse_(last_edge_.first, last_edge_.second, f, g);
  }
  template<typename F, typename G>
  void traverse_(int u, int p, const F& f, const G& g) {
    if(vis.get(u)) return;
    vis[u] = 1;
    f(u, p, adj[u]);
    for(int v : adj[u]) {
      if(v == p || vis.get(v)) continue;
      traverse_(v, u, f, g);
    }
    g(u, p, adj[u]);
  }
  void fix_(int u, int p, int d) {
    if(vis.get(u)) return;
    vis[u] = 1;
    pai[u] = p;
    depth[u] = d;
    for(int v : adj[u]) {
      if(v == p || vis.get(v)) continue;
      fix_(v, u, d+1);
    }
  }
  pair<int, int> last_edge() const {
    return last_edge_;
  }
  int parent(int i) const {
    return pai[i];
  }
};
} // namespace dsu
} // namespace lib

#endif

