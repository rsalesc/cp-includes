#ifndef _LIB_MATROID_INTERSECTION_V2
#define _LIB_MATROID_INTERSECTION_V2
#include <bits/stdc++.h>
#include "EdgeFinder.cpp"
#include "../../utils/FastQueue.cpp"
#include "../../Lambda.cpp"

namespace lib {
template<typename M1, typename M2>
struct MatroidIntersection {
  int n;
  M1 m1;
  M2 m2;

  // aux vectors
  vector<int> vI;
  vector<int> I;
  FastQueue<int> q;
  vector<int> dist;

  lambda::Subset sI_;
  lambda::SubsetFilter I_;

  MatroidIntersection() : q(1) { init (); }
  MatroidIntersection(int n, const M1& m1, const M2& m2) : m1(m1), m2(m2), n(n), q(n) {
    init();
  }
  int size() const { return n; }
  void init() {
    vI.clear();
    vI.reserve(n);
    I.assign(n, false);
    m1.build(n), m2.build(n);
  }
  void clear() { init(); }
  void setup_set() {
    vI.clear();
    for(int i = 0; i < n; i++) {
      if(I[i]) vI.push_back(i);
    }
    I_ = lambda::SubsetFilter(n, [this](int i) -> bool { return in_I(i); });
    sI_ = I_.subset(n);
  }
  template<typename M>
  auto edge_finder(M& mat, int u, int d) {
    return matroid::edge_finder(mat, sI_, I_, u, [this, d](int i) { return dist[i] == d; });
  }
  bool dfs(int u, int du) {
    int v;
    auto forward_edge = edge_finder(m2, u, du - 1);
    auto backward_edge = edge_finder(m1, u, du - 1);
    while((v = (du&1) ? backward_edge() : forward_edge()) >= 0) {
      if(v == n) return true;
      dist[v] = -1;
      if(dfs(v, du - 1))
        return I[v] ^= 1, true;
    }
    return false;
  }
  bool augment(bool single = true) {
    setup_set();
    q.clear();
    dist.assign(n+2, -1);
    dist[n+1] = 0;
    q.push(n+1);
    while(dist[n] == -1 && !q.empty()) {
      int u = q.pop();
      auto forward_edge = edge_finder(m1, u, -1);
      auto backward_edge = edge_finder(m2, u, -1);
      int v;
      while(dist[n] == -1 && (v = (dist[u]&1) ? backward_edge() : forward_edge()) >= 0) {
        q.push(v), dist[v] = dist[u]+1;
      }
    }
    if(dist[n] == -1) return false;
    while(dfs(n, dist[n])) {
      setup_set();
      if(single) break;
    }
    return true;
  }
  vector<int> solve() {
    m1.clear(), m2.clear();
    for(int i = 0; i < n; i++) {
      if(m1.check(i) && m2.check(i)) {
        m1.add(i), m2.add(i), I[i] = true;
      }
    }
    while(augment(false));
    return I;
  }
  int cardinality() const {
    int res = 0;
    for(int i = 0; i < n; i++)
      res += I[i];
    return res;
  }
  bool in_I(int i) const {
    return I[i];
  }
  const vector<int>& get_I() const {
    return I;
  }
};

template<typename M1, typename M2>
shared_ptr<MatroidIntersection<M1, M2>> make_matroid_intersection(int n, const M1& m1, const M2& m2) {
  return make_shared<MatroidIntersection<M1, M2>>(n, m1, m2);
}
} // namespace lib

#endif
