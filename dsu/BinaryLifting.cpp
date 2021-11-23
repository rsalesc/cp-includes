#ifndef _LIB_DSU_BINARY_LIFTING
#define _LIB_DSU_BINARY_LIFTING
#include <bits/stdc++.h>
#include "SpanningTree.cpp"

namespace lib {
using namespace std;
namespace dsu {

template<typename D>
struct BinaryLifting : public D {
  using D::parent;
  vector<vector<int>> P;
  int K;

  BinaryLifting() : D() {}
  BinaryLifting(int n) : D(n) {
    P = decltype(P)(n, vector<int>(__lg(n)+1, -1));
    K = __lg(n)+1;
  }
  virtual void clear() override {
    D::clear();
    int n = P.size();
    P = decltype(P)(n, vector<int>(K, -1));
  }
  virtual int merge(int u, int v) override {
    if(!D::merge(u, v)) return 0;
    this->traverse_last_small([this](int u, int p, vector<int>&) {
      for(int& x : P[u]) x = -1;
      P[u][0] = p;
      for(int i = 1; i < K; i++) {
        if(P[u][i-1] == -1) break;
        P[u][i] = P[P[u][i-1]][i-1];
      }
    }, no_op_visitor);
    return 1;
  }
  int parent(int u, int k) {
    assert(k >= 0);
    for(int i = K-1; i >= 0; i--) {
      if(!((k>>i)&1)) continue;
      u = P[u][i];
      if(u == -1) return -1;
    }
    return u;
  }
};
} // namespace dsu
} // namespace lib

#endif

