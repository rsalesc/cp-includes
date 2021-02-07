---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Combinatorics.cpp
    title: Combinatorics.cpp
  - icon: ':heavy_check_mark:'
    path: DFT.cpp
    title: DFT.cpp
  - icon: ':warning:'
    path: FFT.cpp
    title: FFT.cpp
  - icon: ':heavy_check_mark:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':heavy_check_mark:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':heavy_check_mark:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fht-convolution.test.cpp
    title: tests/yosupo/fht-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/find-lr.test.cpp
    title: tests/yosupo/find-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fps-inv.test.cpp
    title: tests/yosupo/fps-inv.test.cpp
  - icon: ':heavy_check_mark:'
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  dependsOn: []
  isVerificationFile: false
  path: BitTricks.cpp
  requiredBy:
  - PowerSeries.cpp
  - FHT.cpp
  - NTT.cpp
  - FFT.cpp
  - DFT.cpp
  - Combinatorics.cpp
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/fht-convolution.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/find-lr.test.cpp
  - tests/yosupo/subset-sum.test.cpp
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/fps-inv.test.cpp
  - tests/yosupo/fps-power.test.cpp
documentation_of: BitTricks.cpp
layout: document
redirect_from:
- /library/BitTricks.cpp
- /library/BitTricks.cpp.html
title: BitTricks.cpp
---
