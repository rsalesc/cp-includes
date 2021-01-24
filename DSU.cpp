#ifndef _LIB_DSU
#define _LIB_DSU
#include <bits/stdc++.h>

namespace lib {
using namespace std;

struct DSU {
  vector<int> p, ptime, sz;
  int tempo = 0;

  DSU(int n = 0) : p(n), ptime(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }

  int make_node() {
    int i = p.size();
    p.emplace_back(i);
    ptime.emplace_back(0);
    sz.emplace_back(1);
    return 1;
  }

  int get(int i, int at) const {
    return p[i] == i ? i : (at >= ptime[i] ? get(p[i], at) : i);
  }

  int operator[](int i) const { return get(i, tempo); }

  int merge(int u, int v) {
    u = (*this)[u], v = (*this)[v];
    if (u == v)
      return 0;
    if (sz[u] < sz[v])
      swap(u, v);
    p[v] = u;
    ptime[v] = ++tempo;
    sz[u] += sz[v];
    return 1;
  }
};

struct CompressedDSU {
  vector<int> p;
  CompressedDSU(int n = 0) : p(n) { iota(p.begin(), p.end(), 0); }
  int get(int i) {
    return p[i] == i ? i : p[i] = get(p[i]);
  }
  int operator[](int i) { return get(i); }
  int& parent(int i) { return p[i]; }
};

struct FastDSU {
  vector<int> p, sz;
  FastDSU(int n = 0) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }

  int get(int i) {
    return p[i] == i ? i : p[i] = get(p[i]);
  }
  int operator[](int i) { return get(i); }

  int merge(int u, int v) {
    u = get(u), v = get(v);
    if(u == v) return 0;
    if(sz[u] < sz[v])
      swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return 1;
  }
};
} // namespace lib

#endif
