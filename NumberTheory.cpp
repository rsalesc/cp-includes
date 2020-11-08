#ifndef _LIB_NUMBER_THEORY
#define _LIB_NUMBER_THEORY
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace nt {
int64_t inverse(int64_t a, int64_t b) {
  long long b0 = b, t, q;
  long long x0 = 0, x1 = 1;
  if (b == 1)
    return 1;
  while (a > 1) {
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  if (x1 < 0)
    x1 += b0;
  return x1;
}
template<typename T, typename U>
T powmod (T a, U b, U p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}
template<typename T>
vector<T> factors(T n) {
  vector<T> f;
  for(T i = 2; i*i <= n; i++) {
    if(n % i == 0) f.push_back(i);
    while(n % i == 0) n /= i;
  }
  if(n > 1) f.push_back(n);
  return f;
}
} // namespace nt
} // namespace lib

#endif
