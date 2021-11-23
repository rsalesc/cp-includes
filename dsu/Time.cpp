#ifndef _LIB_DSU_TIME
#define _LIB_DSU_TIME
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace dsu {

template<typename D>
struct Time : public D {
  using D::r;
  using D::sz;

  vector<int> t;
  int tempo = 0;
  Time() : D() {}
  Time(int n) : D(n), t(n, 1e9) {}
  virtual void clear() override {
    tempo = 0;
    fill(t.begin(), t.end(), (int)1e9);
  }
  int get(int i, int tt) const {
    return r[i] == i ? i : (t[i] <= tt ? get(r[i]) : i);
  }
  int get_merge_time(int u, int v) const {
    int ans = -1;
    while(u != v) {
      if(sz[u] < sz[v]) swap(u, v);
      ans = max(ans, t[v]);
      if(r[v] == v) return -1;
      v = r[v];
    }
    return ans;
  }
  Time& at_time(int tt) {
    assert(tt >= tempo);
    tempo = tt;
    return *this;
  }
  Time& tick() {
    return at_time(tempo+1);
  }
  virtual void merged(int u, int v) override {
    D::merged(u, v);
    t[u] = tempo;
  }
};
} // namespace dsu
} // namespace lib

#endif

