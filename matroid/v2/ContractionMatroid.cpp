#ifndef _LIB_GRAPHIC_MATROID
#define _LIB_GRAPHIC_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"
#include "../../DSU.cpp"

namespace lib {
  using namespace std;
template<typename M>
struct ContractionMatroid : Matroid {
  M ref_m, Am;
  lambda::SubsetFilter A, T;
  int basis_sz, union_sz;
  lambda::Subset A_subset, T_subset, A_inv_subset;
  ContractionMatroid(const M& m_, const lambda::SubsetFilter& T_)
    : Matroid(), ref_m(m_), T(T_), A(!T_) {}
  void build_deps() override {
    A_subset = A.as_subset();
    T_subset = T.as_subset();
    A_inv_subset = A_subset.take_inverse().as_subset();
    assert(A_subset.size() == size());
    Am = ref_m;
    auto Tm = ref_m;
    Tm.build(map() * T_subset.take_indices());

    auto basis = Tm.basis();
    auto Am_map = A_subset.take_indices()
      + lambda::from_vector(basis).as_subset().take_from(T_subset);
    Am.build(map() * Am_map);
    basis_sz = basis.size();
    union_sz = A_subset.size() + basis.size();
  }

  void clear() override {
    Am.clear();
    for(int i = A_subset.size(); i < union_sz; i++)
      Am.add(i);
  }
  void add(int i) override {
    Am.add(A_inv_subset(i));
  }
  bool check(int i) override {
    Am.check(A_inv_subset(i));
  }

  int rank(const lambda::Subset& s, const lambda::SubsetFilter& f) override {
   auto un = rank(s, f + lambda::SubsetFilter(basis_sz, lambda::all));
   return un - basis_sz;
  }
};
} // namespace lib

#endif
