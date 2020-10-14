#ifndef _LIB_EPSILON
#define _LIB_EPSILON
#include <bits/stdc++.h>

namespace lib {
  using namespace std;

  template<typename T = double>
  struct Epsilon {
    T eps;
    constexpr Epsilon(T eps = 1e-9) : eps(eps) {}

    template<typename G,
             typename enable_if<is_floating_point<G>::value>::type* = nullptr>
    int operator()(G a, G b = 0) const {
      return a + eps < b ? -1 : (b + eps < a ? 1 : 0);
    }

    template<typename G,
             typename enable_if<!is_floating_point<G>::value>::type* = nullptr>
   int operator()(G a, G b = 0) const {
     return a < b ? -1 : (a > b ? 1 : 0);
   }

   template<typename G,
            typename enable_if<is_floating_point<G>::value>::type* = nullptr>
   bool null(G a) const {
     return (*this)(a) == 0;
   }

   template<typename G,
            typename enable_if<!is_floating_point<G>::value>::type* = nullptr>
   bool null(G a) const {
     return a == 0;
   }
  };
}

#endif
