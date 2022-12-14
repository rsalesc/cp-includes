---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FFT.cpp
    title: FFT.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Complex.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\ntemplate <typename T> struct Complex {\n  T re,\
    \ im;\n  Complex(T a = T(), T b = T()) : re(a), im(b) {}\n  T real() const { return\
    \ re; }\n  T imag() const { return im; }\n  explicit operator T() const { return\
    \ re; }\n  template<typename G>\n  operator Complex<G>() const { return Complex<G>(re,\
    \ im); }\n  Complex conj() const { return Complex(re, -im); }\n  void operator+=(const\
    \ Complex<T> &rhs) { re += rhs.re, im += rhs.im; }\n  void operator-=(const Complex<T>\
    \ &rhs) { re -= rhs.re, im -= rhs.im; }\n  void operator*=(const Complex<T> &rhs)\
    \ {\n    tie(re, im) =\n        make_pair(re * rhs.re - im * rhs.im, re * rhs.im\
    \ + im * rhs.re);\n  }\n  Complex<T> operator+(const Complex<T> &rhs) {\n    Complex<T>\
    \ res = *this;\n    res += rhs;\n    return res;\n  }\n  Complex<T> operator-(const\
    \ Complex<T> &rhs) {\n    Complex<T> res = *this;\n    res -= rhs;\n    return\
    \ res;\n  }\n  Complex<T> operator*(const Complex<T> &rhs) {\n    Complex<T> res\
    \ = *this;\n    res *= rhs;\n    return res;\n  }\n  Complex<T> operator-() const\
    \ {\n    return {-re, -im};\n  }\n  void operator/=(const T x) { re /= x, im /=\
    \ x; }\n};\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_COMPLEX\n#define _LIB_COMPLEX\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\ntemplate <typename T> struct Complex {\n\
    \  T re, im;\n  Complex(T a = T(), T b = T()) : re(a), im(b) {}\n  T real() const\
    \ { return re; }\n  T imag() const { return im; }\n  explicit operator T() const\
    \ { return re; }\n  template<typename G>\n  operator Complex<G>() const { return\
    \ Complex<G>(re, im); }\n  Complex conj() const { return Complex(re, -im); }\n\
    \  void operator+=(const Complex<T> &rhs) { re += rhs.re, im += rhs.im; }\n  void\
    \ operator-=(const Complex<T> &rhs) { re -= rhs.re, im -= rhs.im; }\n  void operator*=(const\
    \ Complex<T> &rhs) {\n    tie(re, im) =\n        make_pair(re * rhs.re - im *\
    \ rhs.im, re * rhs.im + im * rhs.re);\n  }\n  Complex<T> operator+(const Complex<T>\
    \ &rhs) {\n    Complex<T> res = *this;\n    res += rhs;\n    return res;\n  }\n\
    \  Complex<T> operator-(const Complex<T> &rhs) {\n    Complex<T> res = *this;\n\
    \    res -= rhs;\n    return res;\n  }\n  Complex<T> operator*(const Complex<T>\
    \ &rhs) {\n    Complex<T> res = *this;\n    res *= rhs;\n    return res;\n  }\n\
    \  Complex<T> operator-() const {\n    return {-re, -im};\n  }\n  void operator/=(const\
    \ T x) { re /= x, im /= x; }\n};\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: Complex.cpp
  requiredBy:
  - FFT.cpp
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Complex.cpp
layout: document
redirect_from:
- /library/Complex.cpp
- /library/Complex.cpp.html
title: Complex.cpp
---
