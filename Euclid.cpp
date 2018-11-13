#ifndef _LIB_EUCLID
#define _LIB_EUCLID
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace math {
  template<typename T, typename S = T, typename D = T>
  struct Euclid {
    template<typename U, typename V>
    static V safe_mod(U x, V m) {
      x %= m;
      if(x < 0) x += m;
      return x;
    }

    template<typename U>
    static U safe_mult(U a, U b, U m) {
      a = safe_mod(a, m), b = safe_mod(b, m);

      int hi = 63 - __builtin_clzll((unsigned long long)b);
      U res = 0;
      for(int i = hi; i >= 0; i--) {
        res = safe_mod(res * 2, m);
        if((b>>i)&1) res = safe_mod(res + a, m);
      }
      return res;
    }

    static T euclid_(T a, T b, T& x, T& y) {
      if(a == 0) {
        x = 0, y = 1;
        return b;
      }
      T x1, y1;
      T g = euclid_(b%a, a, x1, y1);
      x = y1 - b / a * x1;
      y = x1;
      return g;
    }

    static T euclid(T a, T b, T& x, T& y) {
      T g = euclid_(a, b, x, y);
      if(g < 0) g = -g, x = -x, y = -y;
      return g;
    }

    static pair<T, T> crt(T a, T b, T m1, T m2) {
      T xx, yy;
      T g = euclid(m1, m2, xx, yy);
      if(safe_mod(a, g) != safe_mod(b, g))
        return {0, 0};

      T mod = m1 / g * m2;

      S x = safe_mod<D, D>(xx, mod);
      S y = safe_mod<D, D>(yy, mod);
      S xb = safe_mult<S>(x, b, mod);
      S ya = safe_mult<S>(y, a, mod);
      S res = safe_mult<S>(xb, m1/g, mod) + safe_mult<S>(ya, m2/g, mod);
      return {safe_mod<T>(res, mod), mod};
    }

    static pair<T, T> crt(const vector<pair<T, T>>& equations) {
      pair<T, T> acc = {0, 1};
      for(const pair<T, T>& e : equations) {
        acc = crt(acc.first, e.first, acc.second, e.second);
        if(!acc.second) return {0, 0};
      }
      return acc;
    }
  };

  using LongCRT = Euclid<long long, unsigned long long>;
}  // namespace math
}  // namespace lib

#endif
