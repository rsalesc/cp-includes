#ifndef _LIB_EPSILON
#define _LIB_EPSILON
#include <bits/stdc++.h>

namespace lib {
  using namespace std;

  template<typename T>
  struct Epsilon {
    T eps;
    Epsilon(T eps) : eps(eps) {}

    template<typename G,
             typename enable_if<!is_integral<G>::value>::type* = nullptr>
    int operator()(G a, G b = 0) const {
      return a + eps < b ? -1 : (b + eps < a ? 1 : 0);
    }

    template<typename G,
             typename enable_if<is_integral<G>::value>::type* = nullptr>
   int operator()(G a, G b = 0) const {
     return a < b ? -1 : (a > b ? 1 : 0);
   }
  };
}

#endif
