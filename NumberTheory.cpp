#ifndef _LIB_NUMBER_THEORY
#define _LIB_NUMBER_THEORY
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace nt {
  int64_t inverse(int64_t a, int64_t b) {
    long long b0 = b, t, q;
    long long x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
      q = a / b;
      t = b, b = a % b, a = t;
      t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
  }
}
}  // namespace lib

#endif
