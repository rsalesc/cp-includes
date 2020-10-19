#ifndef _LIB_COMPLEX
#define _LIB_COMPLEX
#include <bits/stdc++.h>

namespace lib {
using namespace std;
template <typename T> struct Complex {
  T re, im;
  Complex(T a = T(), T b = T()) : re(a), im(b) {}
  T real() const { return re; }
  T imag() const { return im; }
  template<typename G>
  operator Complex<G>() const { return Complex<G>(re, im); }
  Complex conj() const { return Complex(re, -im); }
  void operator+=(const Complex<T> &rhs) { re += rhs.re, im += rhs.im; }
  void operator-=(const Complex<T> &rhs) { re -= rhs.re, im -= rhs.im; }
  void operator*=(const Complex<T> &rhs) {
    tie(re, im) =
        make_pair(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re);
  }
  Complex<T> operator+(const Complex<T> &rhs) {
    Complex<T> res = *this;
    res += rhs;
    return res;
  }
  Complex<T> operator-(const Complex<T> &rhs) {
    Complex<T> res = *this;
    res -= rhs;
    return res;
  }
  Complex<T> operator*(const Complex<T> &rhs) {
    Complex<T> res = *this;
    res *= rhs;
    return res;
  }
  void operator/=(const T x) { re /= x, im /= x; }
};
} // namespace lib

#endif
