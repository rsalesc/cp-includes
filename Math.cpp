#ifndef _LIB_MATH
#define _LIB_MATH
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace math {

  /// caide keep
  template<typename Type>
  struct DefaultPowerOp {
    Type operator()() const { return Type(1); }
    Type operator()(const Type& a) const { return a; }
    void operator()(Type& x, const Type& a, long long cur) const {
      x *= x;
      if(cur & 1)
        x *= a;
    }
  };

  template<typename Type, typename Op>
  Type generic_power(const Type& a, long long n, Op op) {
    if(n == 0) return op();
    Type res = op(a);
    int hi = 63 - __builtin_clzll(n);
    for(int i = hi - 1; ~i; i--) {
      op(res, a, n >> i);
    }
    return res;
  }

  template<typename Type>
  Type generic_power(const Type& a, long long n) {
    return generic_power(a, n, DefaultPowerOp<Type>());
  }
}  // namespace math
}  // namespace lib

#endif
