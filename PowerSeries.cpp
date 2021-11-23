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

// \sum ln(1 + x^K), where K are elements of v.
template<typename P, typename I>
P ln_1px(const vector<I>& v, int n) {
  using Field = typename P::field;
  vector<I> h(n);
  vector<Field> res(n);
  for(auto x : v) if(x < n) h[x]++;
  res[0] = h[0];
  for(int i = 1; i < n; i++) {
    if(!h[i]) continue;
    for(int j = 0, k = i; k < n; k += i, j++) {
      Field c = Field(1) / Field(j + 1);
      if(j&1) c = -c;
      res[k] += c * h[i];
    }
  }
  return P(res);
}

template<typename P> pair<P, P> exp2(P p, int n) {
  assert(p[0] == 0);
  P f{1}, g{1};
  for(int i = 1; i <= n; i*=2) {
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
  int m = p.size();
  for(int i = 0; i < m; i++) {
    if(p[i] == 0) continue;
    if(i > 0 && k > n / i) return {};
    auto rev = typename P::field(1) / p[i];
    auto D = (p * rev) >> i;
    int sz = n - i * k;
    D = exp(ln(D, sz) * k, sz) * (p[i] ^ k);
    if(i == 0) return D % n;
    long long S = k * i;
    D <<= S;
    return D % n;
  }
  return {};
}
} // namespace series
} // namespace lib

#endif
