#ifndef _LIB_LAGRANGE
#define _LIB_LAGRANGE
#include <bits/stdc++.h>
#include "Combinatorics.cpp"

namespace lib {
using namespace std;
namespace linalg {
template <typename Field> struct PrefixLagrange {
  vector<Field> pref, suf;
  PrefixLagrange() {}

  void ensure(int n) {
    int o = pref.size();
    if (n <= o)
      return;
    pref.resize(n), suf.resize(n);
  }

  template <typename T> Field eval(const vector<Field> &v, T x) {
    using C = Combinatorics<Field>;
    assert(!v.empty());
    int d = (int)v.size() - 1;
    if (x <= d)
      return v[x];

    ensure(d + 1);

    Field a = x;
    pref[0] = suf[d] = 1;
    for (T i = 0; i < d; i++)
      pref[i + 1] = pref[i] * a, a -= 1;
    for (T i = d; i; i--)
      suf[i - 1] = suf[i] * a, a += 1;

    Field ans = 0;
    for (int i = 0; i <= d; i++) {
      Field l = pref[i] * suf[i] * C::ifactorial(i) * C::ifactorial(d-i) * v[i];
      if ((d + i) & 1)
        l = -l;
      ans += l;
    }
    return ans;
  }
};

template<typename T, typename U>
T lagrange_iota(const vector<T>& f, U n) {
  static PrefixLagrange<T> lag;
  return lag.eval(f, n);
}

template<typename T, typename U>
T lagrange_iota_sum(const vector<T>& f, U n) {
  int m = f.size();
  vector<T> g(m + 1);
  for(int i = 1; i <= m; i++)
      g[i] = g[i-1] + f[i-1];
  return lagrange_iota(g, n);
}
} // namespace linalg
} // namespace lib

#endif
