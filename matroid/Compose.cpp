#ifndef _LIB_COMPOSE_MATROID
#define _LIB_COMPOSE_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"
#include "../Lambda.cpp"

namespace lib {
  using namespace std;
namespace matroid {
template<typename M>
struct Filter : Matroid {
  M mat;
  lambda::Filter filter_fn;
  lambda::SubsetMap<int> inv_fn;
  Filter(const M& mat_, const lambda::Filter& filter_fn_)
    : Matroid(), mat(mat_), filter_fn(filter_fn_) {}

  void build(const lambda::SubsetFilter& I_) override{
    Matroid::build(I_);
    auto subset = filter_fn.subset(I_.size());
    inv_fn = subset.take_inverse();
    mat.build(subset.take_from(I_));
  }

  void setup() { mat.setup(); }
  void setup_graph() { mat.setup_graph(); }
  void setup_exchange(int i) {
    mat.setup_exchange(inv_fn(i));
  }
  void finish_exchange(int i) {
    mat.finish_exchange(inv_fn(i));
  }

  bool can_add(int i) {
    if(!filter_fn(i)) return true;
    return mat.can_add(inv_fn(i));
  }
  bool can_exchange(int i, int j) {
    if(!filter_fn(i)) return can_add(j);
    if(!filter_fn(j)) return true;
    return mat.can_exchange(inv_fn(i), inv_fn(j));
  }
};

template<typename M>
Filter<M> make_filter(const M& mat, const lambda::Filter& fn) {
  return Filter<M>(mat, fn);
}
} // namespace matroid
} // namespace lib

#endif
