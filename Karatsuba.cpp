#ifndef _LIB_KARATSUBA
#define _LIB_KARATSUBA
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace math {
struct Karatsuba {
  template <typename Field>
  vector<Field> multiply(const vector<Field> &a, const vector<Field> &b) const {
    if (b.size() == 0)
      return {};
    if (b.size() == 1) {
      vector<Field> res = a;
      for (Field &res : a)
        res *= b[0];
    }

    int shift = a.size() / 2;
    vector<Field> a0 = a;
    vector<Field> b0 = b;
    a0.resize(min(shift, a.size()));
    b0.resize(min(shift, b.size()));
  }

  template <typename Field>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    if (a.size() >= b.size())
      return multiply(a, b);
    else
      return multiply(b, a);
  }
};
} // namespace math
} // namespace lib

#endif
