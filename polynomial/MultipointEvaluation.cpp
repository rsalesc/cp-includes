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
  int n;
  vector<field> w;
  vector<Poly> up, down;

  template <
      typename Iterator,
      typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>
  MultipointEvaluation(Iterator begin, Iterator end) : w(distance(begin, end)) {
    int i = 0;
    for (auto it = begin; it != end; ++it, ++i)
      w[i] = *it;
    n = w.size();
    build();
  }

  template <
      typename Container,
      typename enable_if<HasInputIterator<Container>::value>::type * = nullptr>
  MultipointEvaluation(const Container &container)
      : MultipointEvaluation(container.begin(), container.end()) {}

  void build() {
    if(w.empty()) return;
    up = vector<Poly>(2 * n);
    down = vector<Poly>(2 * n);
    for(int i = 0; i < n; i++)
      up[i+n] = {-w[i], 1};
    for(int i = n-1; i; i--)
      up[i] = up[2*i] * up[2*i+1];
  }

  vector<field> eval(const Poly &p) {
    down[1] = p % up[1];
    for(int i = 2; i < 2*n; i++)
      down[i] = down[i/2] % up[i];
    vector<field> res(n);
    for(int i = 0; i < n; i++)
      res[i] = down[i+n][0];
    return res;
  }

  template<typename Iterator>
  Poly interp(const Iterator& begin, const Iterator& end) {
    assert(n == distance(begin, end));
    vector<field> a = eval(up[1].derivative());
    auto it = begin;
    for(int i = 0; i < n; i++, ++it)
      down[i+n] = {*it / a[i]};
    for(int i = n-1; i; i--)
      down[i] = down[i*2] * up[i*2+1] + down[i*2+1] * up[i*2];
    return down[1];
  }

  template <
      typename Container,
      typename enable_if<traits::HasInputIterator<Container>::value>::type * = nullptr>
  Poly interp(const Container &container) {
    interp(container.begin(), container.end());
  }

};
} // namespace math
} // namespace lib

#endif
