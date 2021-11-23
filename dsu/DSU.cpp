#ifndef _LIB_RANK_DSU
#define _LIB_RANK_DSU
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace dsu {
struct RankDSU {
  mutable vector<int> r, sz;
  pair<int, int> last_merge_ = {-1, -1};
  bool last_swapped_ = false;
  int merges = 0;
  RankDSU() {}
  RankDSU(int n) : r(n), sz(n, 1) {
    iota(r.begin(), r.end(), 0);
  }
  virtual void clear() {
    iota(r.begin(), r.end(), 0);
    fill(sz.begin(), sz.end(), 1);
    last_merge_ = {-1, -1};
    merges = 0;
  }
  virtual int get(int i) const {
    return r[i] == i ? i : get(r[i]);
  }
  int operator[](int i) const {
    return get(i);
  }
  pair<int, int> last_merge() const {
    return last_merge_;
  }
  int n_comps() const { return (int)r.size() - merges; }
  virtual void merged(int u, int v) {}
  virtual int merge(int u, int v) {
    u = get(u), v = get(v);
    if(u == v) return 0;
    last_swapped_ = false;
    if(sz[u] > sz[v]) swap(u, v), last_swapped_ = true;
    r[u] = v;
    sz[v] += sz[u];
    last_merge_ = {u, v};
    merged(u, v);
    return 1;
  }
};

template<template<class> class ...Ts>
struct ByRankImpl;

template<template<class> class T, template<class> class ...Ts>
struct ByRankImpl<T, Ts...> {
  using type = T<typename ByRankImpl<Ts...>::type>;
};

template<>
struct ByRankImpl<> {
  using type = RankDSU;
};

template<template<class> class ...Ts>
using ByRank = typename ByRankImpl<Ts...>::type;
} // namespace dsu
} // namespace lib

#endif

