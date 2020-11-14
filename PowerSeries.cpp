#ifndef _LIB_POWER_SERIES
#define _LIB_POWER_SERIES
#include "BitTricks.cpp"
#include "PolynomialRing.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace series {
  
template <typename P> P ln(const P &p, int n);

template <typename P> P inverse(P p, int n) {
  return p.inverse(n);
}

template <typename P> P ln(const P &p, int n) {
  return (p.derivative() * inverse(p, n) % n).integral() % n;
}

template<typename P> pair<P, P> exp2(P p, int n) {
  assert(p[0] == 0);
  P f{1}, g{1};
  for(int i = 1; i < n; i*=2) {
    g = g * 2 - (g*g%i*f)%i;
    P q = (p % i).derivative();
    q += g * (f.derivative() - f * q) % (2 * i - 1);
    f += f * (p % (2 * i) - q.integral()) % (2 * i);
  }
  return {f % n, g % n};
}

// p[0] must be null
template <typename P> P exp(P p, int n) {
  return exp2(p, n).first;
}

template <typename P> P power(const P &p, long long k, int n) {
  if (n <= 0)
    return P();
  return exp(ln(p, n) * k, n) * (p[0] ^ k);
}
} // namespace series
} // namespace lib

#endif
