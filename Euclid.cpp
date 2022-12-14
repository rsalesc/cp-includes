#ifndef _LIB_EUCLID
#define _LIB_EUCLID
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace math {
namespace {
constexpr static size_t ULL_SIZE = sizeof(unsigned long long);

template <typename T>
using IsManageableInt =
    typename conditional<is_integral<T>::value && sizeof(T) <= ULL_SIZE,
                         true_type, false_type>::type;
} // namespace

template <typename T, typename US = T> struct Euclid {
  template <typename U, typename V> static V safe_mod(U x, V m) {
    x %= m;
    if (x < 0)
      x += m;
    return x;
  }

  template <typename U,
            typename enable_if<IsManageableInt<U>::value>::type * = nullptr>
  static U safe_mult(U a, U b, U m) {
    a = safe_mod(a, m), b = safe_mod(b, m);

    if (!b) return 0;
    int hi = 63 - __builtin_clzll((unsigned long long)b);
    U res = 0;
    for (int i = hi; i >= 0; i--) {
      res = safe_mod(res * 2, m);
      if ((b >> i) & 1)
        res = safe_mod(res + a, m);
    }
    return res;
  }

  template <typename U,
            typename enable_if<!IsManageableInt<U>::value>::type * = nullptr>
  static U safe_mult(U a, U b, U m) {
    return a * b % m;
  }

  static T euclid_(T a, T b, T &x, T &y) {
    if (a == 0) {
      x = 0, y = 1;
      return b;
    }
    T x1, y1;
    T g = euclid_(b % a, a, x1, y1);
    x = y1 - b / a * x1;
    y = x1;
    return g;
  }

  static T euclid(T a, T b, T &x, T &y) {
    T g = euclid_(a, b, x, y);
    if (g < 0)
      g = -g, x = -x, y = -y;
    return g;
  }

  static pair<T, T> crt(T a, T b, T m1, T m2) {
    if (m1 < m2)
      swap(m1, m2), swap(a, b);
    T xx, yy;
    T g = euclid(m1, m2, xx, yy);
    if (safe_mod(a, g) != safe_mod(b, g))
      return {0, 0};

    T mod = m1 / g * m2;

    T x = safe_mod<T>(xx, mod);
    US s = safe_mult<T>(x, (b - a) / g, m2 / g) * m1 % mod;
    T res = safe_mod<US, US>((US)a + s, mod);

    return {safe_mod<T>(res, mod), mod};
  }

  static pair<T, T> crt(const vector<pair<T, T>> &equations) {
    pair<T, T> acc = {0, 1};
    for (const pair<T, T> &e : equations) {
      acc = crt(acc.first, e.first, acc.second, e.second);
      if (!acc.second)
        return {0, 0};
    }
    return acc;
  }

  static bool diophantine_solution(T a, T b, T c, T& x0, T& y0, T& g) {
    g = euclid(a, b, x0, y0);
    if (c % g)
      return false;
    x0 *= c/g;
    y0 *= c/g;
    return true;
  }

  // Give solutions for diophantine in the form [x = x.first * k + x.second].
  static bool diophantine_solutions(T a, T b, T c, pair<T, T>& x, pair<T, T>& y) {
    T g;
    if(!diophantine_solution(a, b, c, x.second, y.second, g))
      return false;
    x.first = b / g;
    y.first = -a / g;
    return true;
  }

  // Give parameterized solution (in terms of k) to:
  // a_1 * k + b_1 = ... = a_n * k + b_n, i.e, an equation for where those
  // functions meet.
  static bool linear_equality_system(const vector<pair<T, T>>& v, pair<T, T>& res) {
    assert(!v.empty());
    res = v[0];
    for(int i = 1; i < v.size(); i++) {
      pair<T, T> x, y;
      if (!diophantine_solutions(res.first, -v[i].first, v[i].second - res.second, x, y))
        return false;
      auto num = res.first * x.first;
      if (num < 0) num = -num;
      res = {
        num,
        safe_mod(res.second + safe_mult(res.first, x.second, num), num),
      };
    }
    return true;
  }
};

using LongCRT = Euclid<long long, unsigned long long>;
} // namespace math
} // namespace lib

#endif
