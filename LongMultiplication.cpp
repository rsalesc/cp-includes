#ifndef _LIB_LONG_MULTIPLICATION
#define _LIB_LONG_MULTIPLICATION
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace math {
struct NaiveMultiplication {
  template <typename Field>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    vector<Field> res(a.size() + b.size());
    for (size_t i = 0; i < a.size(); i++) {
      for (size_t j = 0; j < b.size(); j++) {
        res[i + j] += a[i] * b[j];
      }
    }
    return res;
  }
};

template <typename Mult, typename Field>
vector<Field> shift_conv(const vector<Field> &a, vector<Field> b) {
  if (b.empty())
    return {};
  reverse(b.begin(), b.end());
  int n = a.size();
  int m = b.size();

  auto res = Mult()(a, b);
  return vector<Field>(res.begin() + m - 1, res.end());
}
} // namespace math
} // namespace lib

#endif
