---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':question:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':question:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/find-lr.test.cpp
    title: tests/yosupo/find-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fps-inv.test.cpp
    title: tests/yosupo/fps-inv.test.cpp
  - icon: ':x:'
    path: tests/yosupo/fps-power.test.cpp
    title: tests/yosupo/fps-power.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/kth-term-lr.test.cpp
    title: tests/yosupo/kth-term-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/multipoint.test.cpp
    title: tests/yosupo/multipoint.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/subset-sum.test.cpp
    title: tests/yosupo/subset-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
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
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: Math.cpp
  requiredBy:
  - polynomial/MultipointEvaluation.cpp
  - PolynomialRing.cpp
  - PowerSeries.cpp
  - LinearRecurrence.cpp
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/subset-sum.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/find-lr.test.cpp
  - tests/yosupo/fps-inv.test.cpp
  - tests/yosupo/fps-power.test.cpp
documentation_of: Math.cpp
layout: document
redirect_from:
- /library/Math.cpp
- /library/Math.cpp.html
title: Math.cpp
---
