#ifndef _LIB_COGRAPHIC_MATROID
#define _LIB_COGRAPHIC_MATROID
#include <bits/stdc++.h>
#include "GraphicMatroid.cpp"

namespace lib {
  using namespace std;
struct CographicMatroid : GraphicMatroid {

  CographicMatroid(int n, std::function<pair<int, int>(int)> edge_fn_)
    : GraphicMatroid(n, edge_fn_) {}

  void build(const lambda::SubsetFilter& I_) override {
    GraphicMatroid::build(!I_);
  }
  void setup_exchange(int i) {
    setup();
  }
  bool can_exchange(int i, int j) {
    return can_add(j);
  }
  bool can_add(int i) {
    return !is_bridge(i);
  }
};
} // namespace lib

#endif
