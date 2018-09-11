#ifndef _LIB_LONG_MULTIPLICATION
#define _LIB_LONG_MULTIPLICATION
#include "FFT.cpp"
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace math {
  struct FastMultiplication {
    template<typename Field>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      return linalg::rounded_fft(a, b);
    }
  };
  
  struct SafeMultiplication {
    template<typename Field>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      return linalg::mod_split_fft(a, b);
    };
  };

  struct NaiveMultiplication {
    template<typename Field>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      vector<Field> res(a.size() + b.size());
      for(size_t i = 0; i < a.size(); i++) {
        for(size_t j = 0; j < b.size(); j++) {
          res[i + j] += a[i] * b[j];
        }
      }
      return res;
    }
  };
}  // namespace math
}  // namespace lib

#endif
