#ifndef _LIB_EUCLID
#define _LIB_EUCLID
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace math {
  template<typename T, typename S = T>
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
      T x, y;
      T g = euclid(m1, m2, x, y);
      if(safe_mod(a, g) != safe_mod(b, g))
        return {-1, 0};

      T mod = m1/g*m2;

      // trick for reducing the chances of overflowing
      S xx = x;
      S yy = y;
      x %= mod, y %= mod;
      if(xx < 0) xx += mod;
      if(yy < 0) yy += mod;

      x = safe_mod(xx, mod);
      y = safe_mod(yy, mod);
      T xb = safe_mult<T>(x, b, mod);
      T ya = safe_mult<T>(y, a, mod);
      T res = safe_mult<T>(xb, m1/g, mod) + safe_mult<T>(ya, m2/g, mod);
      return {safe_mod(res, mod), mod};
    }

    static pair<T, T> crt(const vector<pair<T, T>>& equations) {
      pair<T, T> acc = {0, 1};
      for(const pair<T, T>& e : equations) {
        acc = crt(acc.first, e.first, acc.second, e.second);
        if(!acc.second) return {-1, 0};
      }
      return acc;
    }
  };
}  // namespace math
}  // namespace lib

#endif
