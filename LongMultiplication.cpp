#ifndef _LIB_LONG_MULTIPLICATION
#define _LIB_LONG_MULTIPLICATION
#include "FFT.cpp"
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace math {
  struct FastMultiplication {
    template<typename Field, typename U = double>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      return linalg::rounded_fft<Field, U>(a, b);
    }
  };

  struct FFTMultiplication {
    template<typename Field, typename U = double>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      return linalg::fft<Field, U>(a, b);
    }
  }
  ;
  struct SafeMultiplication {
    template<typename Field, typename U = double>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      return linalg::mod_split_fft<Field, U>(a, b);
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

  template<typename Mult, typename Field>
  vector<Field> circular_conv(const vector<Field>& a, vector<Field> b) {
    if(b.empty()) return {};
    reverse(b.begin(), b.end());
    int m = b.size();

    auto res = Mult()(a, b);
    return vector<Field>(res.begin() + m - 1, res.end());
  }
}  // namespace math
}  // namespace lib

#endif
