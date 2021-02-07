---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Combinatorics.cpp
    title: Combinatorics.cpp
  - icon: ':warning:'
    path: DFT.cpp
    title: DFT.cpp
  - icon: ':warning:'
    path: FFT.cpp
    title: FFT.cpp
  - icon: ':warning:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':warning:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':warning:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: BitTricks.cpp
layout: document
redirect_from:
- /library/BitTricks.cpp
- /library/BitTricks.cpp.html
title: BitTricks.cpp
---
