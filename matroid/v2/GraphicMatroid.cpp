#ifndef _LIB_GRAPHIC_MATROID
#define _LIB_GRAPHIC_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"
#include "../../DSU.cpp"

namespace lib {
  using namespace std;
struct GraphicMatroid : IncrementalMatroid {
  FastDSU dsu;
  int g_sz;
  lambda::Map<pair<int, int>> edge_fn;
  GraphicMatroid(int n, const lambda::Map<pair<int, int>>& fn) 
    : IncrementalMatroid(), g_sz(n), edge_fn(fn), dsu(n) {}
  void clear() override {
    dsu = FastDSU(g_sz);
  }
  void add(int i) override {
    auto p = edge_fn(F(i));
    dsu.merge(p.first, p.second);
  }
  bool check(int i) override {
    auto p = edge_fn(F(i));
    return dsu.get(p.first) != dsu.get(p.second);
  }
};
} // namespace lib

#endif
