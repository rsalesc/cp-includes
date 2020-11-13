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
  if (n == 1)
    return P(p[0].inverse());
  p %= n;
  P q = inverse(p, (n + 1) >> 1);
  auto qq = q * q % n;
  return (q * 2 - p * qq % n) % n;
}

namespace two { // functions for n = 2^k, k >= 0

// p[0] must be invertible
// if p[0] is 1, correctly computes ln(p)
// else computes weirdly scaled ln(p)
template <typename P> P ln(const P &p, int n) {
  return (p.derivative() * inverse(p, n) % n).integral() % n;
}

// p[0] must be null
template <typename P> P exp(P p, int n) {
  if (n == 1)
    return P(1);
  p %= n;
  P q = exp(p, n >> 1);
  return q * (p - ln(q, n) + P(1)) % n;
}
} // namespace two

template <typename P> P ln(const P &p, int n) {
  if (n <= 0)
    return P();
  return two::ln(p, next_power_of_two(n)) % n;
}

template <typename P> P exp(const P &p, int n) {
  if (n <= 0)
    return P();
  return two::exp(p, next_power_of_two(n)) % n;
}

template <typename P> P power(const P &p, long long k, int n) {
  if (n <= 0)
    return P();
  return exp(ln(p, n) * k, n) * (p[0] ^ k);
}
} // namespace series
} // namespace lib

#endif
