---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Combinatorics.cpp
    title: Combinatorics.cpp
  - icon: ':question:'
    path: DFT.cpp
    title: DFT.cpp
  - icon: ':warning:'
    path: FFT.cpp
    title: FFT.cpp
  - icon: ':question:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':heavy_check_mark:'
    path: Lagrange.cpp
    title: Lagrange.cpp
  - icon: ':question:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':question:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/ExponentialSum.cpp
    title: Exponential Sum
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/exp-sum-limit.test.cpp
    title: tests/yosupo/exp-sum-limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/exp-sum.test.cpp
    title: tests/yosupo/exp-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fht-convolution.test.cpp
    title: tests/yosupo/fht-convolution.test.cpp
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
  bundledCode: "#line 1 \"BitTricks.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nlong long next_power_of_two(long long n) {\n  return 1LL << (sizeof(long\
    \ long) * 8 - 1 - __builtin_clzll(n) +\n                 ((n & (n - 1LL)) != 0));\n\
    }\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_BIT_TRICKS\n#define _LIB_BIT_TRICKS\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nlong long next_power_of_two(long long n) {\n  return 1LL <<\
    \ (sizeof(long long) * 8 - 1 - __builtin_clzll(n) +\n                 ((n & (n\
    \ - 1LL)) != 0));\n}\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: BitTricks.cpp
  requiredBy:
  - FHT.cpp
  - polynomial/ExponentialSum.cpp
  - DFT.cpp
  - Combinatorics.cpp
  - PowerSeries.cpp
  - FFT.cpp
  - NTT.cpp
  - Lagrange.cpp
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/yosupo/subset-sum.test.cpp
  - tests/yosupo/fht-convolution.test.cpp
  - tests/yosupo/fps-power.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/exp-sum.test.cpp
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/fps-inv.test.cpp
  - tests/yosupo/exp-sum-limit.test.cpp
  - tests/yosupo/find-lr.test.cpp
documentation_of: BitTricks.cpp
layout: document
redirect_from:
- /library/BitTricks.cpp
- /library/BitTricks.cpp.html
title: BitTricks.cpp
---
