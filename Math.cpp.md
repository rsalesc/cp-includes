---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':warning:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':warning:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':warning:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
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
    path: tests/judge/fft.cpp
    title: tests/judge/fft.cpp
  - icon: ':warning:'
    path: tests/judge/linear.cpp
    title: tests/judge/linear.cpp
  - icon: ':warning:'
    path: tests/judge/polyeval.cpp
    title: tests/judge/polyeval.cpp
  - icon: ':warning:'
    path: tests/judge/polymul.cpp
    title: tests/judge/polymul.cpp
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
  - icon: ':warning:'
    path: tests/yosupo/fps_inv.cpp
    title: tests/yosupo/fps_inv.cpp
  - icon: ':warning:'
    path: tests/yosupo/fps_power.cpp
    title: tests/yosupo/fps_power.cpp
  - icon: ':warning:'
    path: tests/yosupo/interplation.cpp
    title: tests/yosupo/interplation.cpp
  - icon: ':warning:'
    path: tests/yosupo/kth_term_lr.cpp
    title: tests/yosupo/kth_term_lr.cpp
  - icon: ':warning:'
    path: tests/yosupo/lr.cpp
    title: tests/yosupo/lr.cpp
  - icon: ':warning:'
    path: tests/yosupo/multipoint.cpp
    title: tests/yosupo/multipoint.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace lib\
    \ {\nusing namespace std;\nnamespace math {\n\n/// caide keep\ntemplate <typename\
    \ Type> struct DefaultPowerOp {\n  Type operator()() const { return Type(1); }\n\
    \  Type operator()(const Type &a) const { return a; }\n  void operator()(Type\
    \ &x, const Type &a, long long cur) const {\n    x *= x;\n    if (cur & 1)\n \
    \     x *= a;\n  }\n};\n\ntemplate <typename Type, typename Op>\nType generic_power(const\
    \ Type &a, long long n, Op op) {\n  if (n == 0)\n    return op();\n  Type res\
    \ = op(a);\n  int hi = 63 - __builtin_clzll(n);\n  for (int i = hi - 1; ~i; i--)\
    \ {\n    op(res, a, n >> i);\n  }\n  return res;\n}\n\ntemplate <typename Type>\
    \ Type generic_power(const Type &a, long long n) {\n  return generic_power(a,\
    \ n, DefaultPowerOp<Type>());\n}\n} // namespace math\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_MATH\n#define _LIB_MATH\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace math {\n\n/// caide keep\ntemplate <typename\
    \ Type> struct DefaultPowerOp {\n  Type operator()() const { return Type(1); }\n\
    \  Type operator()(const Type &a) const { return a; }\n  void operator()(Type\
    \ &x, const Type &a, long long cur) const {\n    x *= x;\n    if (cur & 1)\n \
    \     x *= a;\n  }\n};\n\ntemplate <typename Type, typename Op>\nType generic_power(const\
    \ Type &a, long long n, Op op) {\n  if (n == 0)\n    return op();\n  Type res\
    \ = op(a);\n  int hi = 63 - __builtin_clzll(n);\n  for (int i = hi - 1; ~i; i--)\
    \ {\n    op(res, a, n >> i);\n  }\n  return res;\n}\n\ntemplate <typename Type>\
    \ Type generic_power(const Type &a, long long n) {\n  return generic_power(a,\
    \ n, DefaultPowerOp<Type>());\n}\n} // namespace math\n} // namespace lib\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Math.cpp
  requiredBy:
  - PowerSeries.cpp
  - LinearRecurrence.cpp
  - PolynomialRing.cpp
  - tests/unit/PolynomialRing.cpp
  - tests/benchmark/PowerSeries.cpp
  - tests/benchmark/PolynomialRing.cpp
  - tests/benchmark/main.cpp
  - tests/yosupo/multipoint.cpp
  - tests/yosupo/fps_power.cpp
  - tests/yosupo/interplation.cpp
  - tests/yosupo/fps_inv.cpp
  - tests/yosupo/kth_term_lr.cpp
  - tests/yosupo/lr.cpp
  - tests/judge/polyeval.cpp
  - tests/judge/fft.cpp
  - tests/judge/polymul.cpp
  - tests/judge/linear.cpp
  - tests/stress/PowerSeries.cpp
  - tests/stress/PolynomialRing.cpp
  - tests/stress/main.cpp
  - polynomial/MultipointEvaluation.cpp
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math.cpp
layout: document
redirect_from:
- /library/Math.cpp
- /library/Math.cpp.html
title: Math.cpp
---
