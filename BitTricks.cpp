#ifndef _LIB_BIT_TRICKS
#define _LIB_BIT_TRICKS
#include <bits/stdc++.h>

namespace lib {
long long next_power_of_two(long long n) {
  if (n <= 0) return 1;
  return 1LL << (sizeof(long long) * 8 - 1 - __builtin_clzll(n) +
                 ((n & (n - 1LL)) != 0));
}
} // namespace lib

#endif
