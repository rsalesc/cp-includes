#ifndef _LIB_CONTRACTION_MATROID
#define _LIB_CONTRACTION_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"

namespace lib {
  using namespace std;
template<typename M>
struct ContractionMatroid : Matroid {
  M m;
  lambda::SubsetFilter A, T;
  int basis_sz;
  lambda::Subset A_subset, T_subset;
  lambda::Subset basis_;
  ContractionMatroid(const M& m_, const lambda::SubsetFilter& T_)
    : Matroid(), m(m_), T(T_), A(!T_) {
      init();
  }
  void init() {
    A_subset = A.as_subset();
    T_subset = T.as_subset();
    set_ground(A_subset.size());

    basis_ = lambda::Subset(m.basis(T_subset));
    basis_sz = basis_.size();
  }

  lambda::Subset contraction_basis() const { return basis_; }

  void clear() override {
    m.clear();
    for(int i : basis_.items())
      m.add(i);
  }
  void add(int i) override {
    m.add(A_subset(i));
  }
  bool check(int i) override {
    return m.check(A_subset(i));
  }

  int rank(const lambda::Subset& s, const lambda::SubsetFilter& f) override {
    auto un = m.rank(s | T_subset, f | T);
    return un - basis_sz;
  }
};

namespace matroid {
template<typename M>
ContractionMatroid<M> contraction(const M& m, const lambda::SubsetFilter& f) {
  return ContractionMatroid<M>(m, f);
}
} // namespace matroid
} // namespace lib

#endif
