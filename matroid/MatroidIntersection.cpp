#ifndef _LIB_MATROID_INTERSECTION
#define _LIB_MATROID_INTERSECTION
#include <bits/stdc++.h>
#include "../utils/FastAdj.cpp"
#include "../utils/FastQueue.cpp"
#include "../Lambda.cpp"

namespace lib {
template<typename M1, typename M2, typename W = int>
struct MatroidIntersection {
  int n;
  M1 m1;
  M2 m2;

  // aux vectors
  vector<int> vI;
  vector<int> I;
  vector<int> nd;
  FastQueue<int> q;
  vector<int> p;
  vector<int> ch;
  vector<int> in_q;
  vector<W> w;
  vector<W> dist;

  FastAdj<int> g;

  MatroidIntersection() : q(1) { init (); }
  MatroidIntersection(int n, const M1& m1, const M2& m2) : m1(m1), m2(m2), n(n), g(n+2, n), q(n) {
    init();
  }
  void set_weights(const vector<W>& w_) {
    assert(n == w_.size());
    w = w_;
  }
  int size() const { return n; }
  void init() {
    vI.reserve(n);
    p.assign(n, -1);
    I.assign(n, false);
    nd.assign(n, 0);
  }
  void setup_augment() {
    vI.clear();
    g.clear();
    for(int i = 0; i < n; i++) {
      if(I[i]) vI.push_back(i);
      nd[i] = 0;
    }
  }
  bool is_weighted() const {
    return !w.empty();
  }
  bool augment(int truncate = 1e9) {
    setup_augment();
    if(vI.size() == min(truncate, n)) return false;
    auto f = lambda::SubsetFilter(n, [this](int i) -> bool { return in_I(i); });
    m1.build(f), m2.build(f);
    m1.setup(), m2.setup();
    // Check potential starting and ending points of the path.
    // Also, return earlier if is both starting and ending point.
    for(int i = 0; i < n; i++) {
      if(I[i]) continue;
      if(m1.can_add(i)) nd[i] |= 1;
      if(m2.can_add(i)) nd[i] |= 2;
      if(nd[i] == 3 && !is_weighted()) {
        I[i] = true;
        return true;
      }
    }
    m1.setup_graph(), m2.setup_graph();
    for(int i : vI) {
      I[i] = false;
      m1.setup_exchange(i), m2.setup_exchange(i);
      for(int j = 0; j < n; j++) {
        if(I[j] || i == j) continue;
        if(m1.can_exchange(i, j)) g.add(i, j);
        if(m2.can_exchange(i, j)) g.add(j, i);
      }
      I[i] = true;
      m1.finish_exchange(i), m2.finish_exchange(i);
    }

    int st = is_weighted() ? weighted_sp() : unweighted_sp();
    if(st == -1) return false;
    I[st] ^= 1;
    while(p[st] != st) {
      st = p[st];
      I[st] ^= 1;
    }
    return true;
  }
  int unweighted_sp() {
    q.clear();
    p.assign(n, -1);
    for(int i = 0; i < n; i++)
      if(nd[i]&1) q.push(i), p[i] = i;

    int st = -1;
    while(!q.empty() && st == -1) {
      int u = q.pop();
      if(nd[u]&2) {
        st = u;
        break;
      }
      for(int v : g.n_edges(u)) {
        if(p[v] == -1) {
          p[v] = u;
          q.push(v);
        }
      }
    }
    return st;
  }
  int weighted_sp() {
    q.clear();
    in_q.assign(n, 0);
    p.assign(n, -1);
    const W oo = numeric_limits<W>::max() / 2;
    ch.assign(n, 1e9);
    dist.assign(n, oo);
    for(int i = 0; i < n; i++)
      if(nd[i]&1)
        dist[i] = -w[i], ch[i] = 0, p[i] = i, q.push(i), in_q[i] = 1;
    while(!q.empty()) {
      int i = q.pop();
      in_q[i] = 0;
      for(int v : g.n_edges(i)) {
        if(v == i) continue;
        W n_dist = dist[i] + (I[v] ? w[v] : -w[v]);
        int n_ch = ch[i] + 1;
        using ii = pair<W, int>;
        if(ii(n_dist, n_ch) < ii(dist[v], ch[v])) {
          dist[v] = n_dist;
          ch[v] = n_ch;
          p[v] = i;
          if(!in_q[v]) {
            in_q[v] = 1;
            q.push(v);
          }
        }
      }
    }

    pair<pair<W, int>, int> best = {{oo, 1e9}, -1};
    for(int i = 0; i < n; i++) {
      if(nd[i]&2) {
        best = min(best, {{dist[i], ch[i]}, i});
      }
    }
    return best.second;
  }
  vector<int> solve(int truncate = 1e9) {
    while(augment(truncate));
    return I;
  }
  W cost() const {
    W res = 0;
    for(int i = 0; i < n; i++) {
      if(I[i])
        res += is_weighted() ? w[i] : 1;
    }
    return res;
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
  void flip(int i) {
    I[i] ^= 1;
  }
  const vector<int>& get_I() const {
    return I;
  }
};

template<typename M1, typename M2>
shared_ptr<MatroidIntersection<M1, M2>> make_matroid_intersection(int n, const M1& m1, const M2& m2) {
  return make_shared<MatroidIntersection<M1, M2>>(n, m1, m2);
}
template<typename W, typename M1, typename M2>
shared_ptr<MatroidIntersection<M1, M2, W>> make_weighted_matroid_intersection(int n, const M1& m1, const M2& m2, const lambda::Map<W>& f) {
  auto res = make_shared<MatroidIntersection<M1, M2, W>>(n, m1, m2);
  vector<W> w(n);
  for(int i = 0; i < n; i++) w[i] = f(i);
  res->set_weights(w);
  return res;
}
} // namespace lib

#endif
