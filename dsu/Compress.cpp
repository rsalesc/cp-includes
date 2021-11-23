#ifndef _LIB_DSU_COMPRESS
#define _LIB_DSU_COMPRESS
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace dsu {

template<typename D>
struct Compress : public D {
  using D::r;

  Compress() : D() {}
  Compress(int n) : D(n) {}

  virtual int get(int i) const override {
    return r[i] == i ? i : r[i] = get(r[i]);
  }
};
} // namespace dsu
} // namespace lib

#endif

