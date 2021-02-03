#ifndef _LIB_GRAPHIC_MATROID
#define _LIB_GRAPHIC_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"
#include "../../DSU.cpp"

namespace lib {
  using namespace std;
struct GraphicMatroid : IncrementalMatroid {
  using Edge = pair<int, int>;
  FastDSU dsu;
  int g_sz;
  lambda::Map<pair<int, int>> edge_fn;
  GraphicMatroid() {}
  GraphicMatroid(int n, const lambda::SubsetMap<pair<int, int>>& fn) 
    : IncrementalMatroid(), g_sz(n), edge_fn(fn), dsu(n) {
      set_ground(fn.size());
  }
  void clear() override {
    dsu = FastDSU(g_sz);
  }
  void add(int i) override {
    auto p = edge_fn(i);
    dsu.merge(p.first, p.second);
  }
  bool check(int i) override {
    auto p = edge_fn(i);
    return dsu.get(p.first) != dsu.get(p.second);
  }
};
} // namespace lib

#endif
