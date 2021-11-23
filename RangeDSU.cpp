#ifndef _LIB_RANGE_DSU
#define _LIB_RANGE_DSU
#include <bits/stdc++.h>
#include "SegtreeFast.cpp"
#include "DSU.cpp"

namespace lib {
using namespace std;
struct RangeDSU {
  struct NodeImpl {
    int low, high;
    int low_inv, high_inv;
    friend NodeImpl operator+(const NodeImpl& a, const NodeImpl& b) {
      NodeImpl res = a;
      if(b.low < res.low) res.low = b.low, res.low_inv = b.low_inv;
      if(b.high > res.high) res.high = b.high, res.high_inv = b.high_inv;
      return res;
    }
  };
  using Node = seg::Active<NodeImpl>;

  seg::SegtreeFast<Node, seg::CombineFolder<Node>> sg;
  FastDSU dsu;
  vector<vector<int>> inv;

  RangeDSU(int n) : sg(seg::make_builder(n)), dsu(n), inv(n) {
    // TODO: optimize
    for(int i = 0; i < n; i++) {
      sg.update_element(i, seg::SetUpdater<NodeImpl>(node_impl(i)));
      inv[i].push_back(i);
    }
  }

  NodeImpl node_impl(int i) {
    int u = dsu[i];
    return NodeImpl{u, u, i, i};
  }

  void activate(int i) {
    sg.update_element(i, seg::ActiveUpdater<Node>(true));
  }

  void deactivate(int i) {
    sg.update_element(i, seg::ActiveUpdater<Node>(false));
  }

  int operator[](int i) {
    return dsu[i];
  }

  bool merge(int u, int v) {
    if(!dsu.merge(u, v)) return false;
    tie(u, v) = dsu.last_merge();
    for(int x : inv[u]) {
      inv[v].push_back(x);
      sg.update_element(x, seg::SetUpdater<NodeImpl>(node_impl(x)));
    }
    return true;
  }

  int merge_range(int i, int j, int x) {
    x = dsu[x];
    Node res = sg.query<Node>(i, j, seg::CombineFolder<Node>());
    if(!res.is_active()) return -1;
    if(res.low != x) {
      merge(res.low, x);
      return res.low_inv;
    }
    if(res.high != x) {
      merge(res.high, x);
      return res.high_inv;
    }
    return -1;
  }

  void merge_all_range(int i, int j, int x) {
    while(merge_range(i, j, x) != -1);
  }

  pair<int, int> last_merge() const { return dsu.last_merge(); }
  vector<int> last_move() const { return inv[last_merge().first]; }
};
} // namespace lib

#endif
