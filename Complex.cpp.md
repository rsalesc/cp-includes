---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FFT.cpp
    title: FFT.cpp
  - icon: ':warning:'
    path: tests/benchmark/PolynomialRing.cpp
    title: tests/benchmark/PolynomialRing.cpp
  - icon: ':warning:'
    path: tests/benchmark/PowerSeries.cpp
    title: tests/benchmark/PowerSeries.cpp
  - icon: ':warning:'
    path: tests/benchmark/main.cpp
    title: tests/benchmark/main.cpp
  - icon: ':warning:'
    path: tests/judge/kinv.cpp
    title: tests/judge/kinv.cpp
  - icon: ':warning:'
    path: tests/judge/polyeval.cpp
    title: tests/judge/polyeval.cpp
  - icon: ':warning:'
    path: tests/stress/PolynomialRing.cpp
    title: tests/stress/PolynomialRing.cpp
  - icon: ':warning:'
    path: tests/stress/PowerSeries.cpp
    title: tests/stress/PowerSeries.cpp
  - icon: ':warning:'
    path: tests/stress/main.cpp
    title: tests/stress/main.cpp
  - icon: ':warning:'
    path: tests/unit/PolynomialRing.cpp
    title: tests/unit/PolynomialRing.cpp
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
  dependsOn: []
  isVerificationFile: false
  path: Complex.cpp
  requiredBy:
  - tests/unit/PolynomialRing.cpp
  - tests/benchmark/PowerSeries.cpp
  - tests/benchmark/PolynomialRing.cpp
  - tests/benchmark/main.cpp
  - tests/judge/polyeval.cpp
  - tests/judge/kinv.cpp
  - tests/stress/PowerSeries.cpp
  - tests/stress/PolynomialRing.cpp
  - tests/stress/main.cpp
  - FFT.cpp
  timestamp: '2021-01-30 22:31:25-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Complex.cpp
layout: document
redirect_from:
- /library/Complex.cpp
- /library/Complex.cpp.html
title: Complex.cpp
---
