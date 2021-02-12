#ifndef _LIB_EXPONENTIAL_SUM
#define _LIB_EXPONENTIAL_SUM
#include <bits/stdc++.h>
#include "../Combinatorics.cpp"
#include "../Lagrange.cpp"

namespace lib {
using namespace std;

// given  : f(0)...f(k) (deg(f) = k), a
// return : \sum_{i=0...infty} a^i f(i)
template<typename Field>
Field exponential_sum_limit(const vector<Field>& f, Field a) {
  if(a == 0) return f[0];
  assert(a != 1);
  int m = f.size();
  vector<Field> g(m);
  Field acc = 1;
  for(int i = 0; i < m; i++) g[i] = f[i] * acc, acc *= a;
  for(int i = 1; i < m; i++) g[i] += g[i-1];
  Field c = 0;
  acc = 1;
  for(int i = 0; i < m; i++) {
    c += Combinatorics<Field>::nCr(m, i) * acc * g[m - i - 1];
    acc *= -a;
  }
  c /= (1 - a)^m;
  return c;
}

// given  : f(0)...f(k) (deg(f) = k), a, n
// return : \sum_{i=0...n-1} a^i f(i)
template<typename Field>
Field exponential_sum(const vector<Field>& f, Field a, int64_t n) {
  if(n == 0) return 0;
  if(a == 0) return f[0];
  if(a == 1) {
    // Interpolate polynomial of deg == k + 1
    return linalg::lagrange_iota_sum(f, n);
  }
  int m = f.size();
  vector<Field> g(m);
  auto c = exponential_sum_limit(f, a);
  Field acc = 1;
  for(int i = 0; i < m; i++) g[i] = f[i] * acc, acc *= a;
  for(int i = 1; i < m; i++) g[i] += g[i-1];
  auto ai = Field(1) / a;
  acc = 1;
  for(int i = 0; i < m; i++) {
    g[i] = (g[i] - c) * acc;
    acc *= ai;
  }
  // Interpolate polynomial of deg == k
  auto tn = linalg::lagrange_iota(g, n - 1);
  return c + (a^(n-1)) * tn;
}

// given  : p, n
// return : (0^p, 1^p, ... , n^p)
template <typename Field>
vector<Field> monomials(int p, int n) {
  vector<Field> f(n + 1, Field(0));
  if (!p) {
    f[0] = 1;
    return std::move(f);
  }
  f[1] = 1;
  vector<bool> sieve(n + 1, false);
  vector<int> ps;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      f[i] = Field(i)^p;
      ps.push_back(i);
    }
    for (int j = 0; j < (int)ps.size() && i * ps[j] <= n; j++) {
      sieve[i * ps[j]] = 1;
      f[i * ps[j]] = f[i] * f[ps[j]];
      if (i % ps[j] == 0) break;
    }
  }
  return std::move(f);
}
} // namespace lib

#endif
