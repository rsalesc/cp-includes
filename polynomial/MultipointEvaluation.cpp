#ifndef _LIB_POLYNOMIAL_MULTIPOINT_EVALUATION
#define _LIB_POLYNOMIAL_MULTIPOINT_EVALUATION
#include "../PolynomialRing.cpp"
#include "../Traits.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace math {
namespace {
/// keep caide
using traits::IsInputIterator;
/// keep caide
using traits::HasInputIterator;

} // namespace
template <typename Poly> struct MultipointEvaluation {
  using field = typename Poly::field;
  vector<field> w, fw;
  vector<Poly> t;

  template <
      typename Iterator,
      typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>
  MultipointEvaluation(Iterator begin, Iterator end) : w(distance(begin, end)) {
    int i = 0;
    for (auto it = begin; it != end; ++it, ++i)
      w[i] = *it;
    build();
  }

  template <
      typename Container,
      typename enable_if<HasInputIterator<Container>::value>::type * = nullptr>
  MultipointEvaluation(const Container &container)
      : MultipointEvaluation(container.begin(), container.end()) {}

  Poly build(int no, int l, int r) {
    if(l == r) return t[no] = Poly::from_root(w[l]);
    int mid = (l+r)/2;
    return t[no] = build(2*no, l, mid) * build(2*no+1, mid+1, r);
  }

  void build() {
    if(w.empty()) return;
    t = vector<Poly>(4 * w.size());
    build(1, 0, (int)w.size() - 1);
  }

  void eval(const Poly &p, int no, int l, int r) {
    if (l == r) {
      fw[l] = p[0];
      return;
    }
    int mid = (l+r)/2;
    eval(p % t[2*no], 2*no, l, mid);
    eval(p % t[2*no+1], 2*no+1, mid+1, r);
  }

  vector<field> eval(const Poly &p) {
    fw = vector<field>(w.size());
    eval(p, 1, 0, (int)w.size() - 1);
    return fw;
  }

  Poly interp(const Poly& p, int no, int l, int r) {
    if(l == r) return {fw[l] / p[0]};
    int mid = (l+r)/2;
    auto A = interp(p % t[2*no], 2*no, l, mid);
    auto B = interp(p % t[2*no+1], 2*no+1, mid+1, r);
    return A * t[2*no+1] + B * t[2*no];
  }

  template<typename Iterator>
  Poly interp(const Iterator& begin, const Iterator& end) {
    fw = vector<field>(distance(begin, end));
    assert(w.size() == fw.size());
    int i = 0;
    for (auto it = begin; it != end; ++it, ++i)
      fw[i] = *it;
    return interp(t[1].derivative(), 1, 0, (int)w.size() - 1);
  }
};
} // namespace math
} // namespace lib

#endif
