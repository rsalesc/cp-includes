#ifndef _LIB_BINARY_MATROID
#define _LIB_BINARY_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"

namespace lib {
  using namespace std;
template<int N>
struct BinaryMatroid : IncrementalMatroid {
  
  BinaryMatroid(int n, const lambda::Map<bitset<N>>& fn) 
    : BinaryMatroid() {}
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
