---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':question:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':heavy_check_mark:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':question:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':question:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':question:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':question:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':warning:'
    path: RollingHash.cpp
    title: RollingHash.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/and-convolution.test.cpp
    title: tests/yosupo/and-convolution.test.cpp
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
    path: tests/yosupo/subset-convolution.test.cpp
    title: tests/yosupo/subset-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/subset-sum.test.cpp
    title: tests/yosupo/subset-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"NumberTheory.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace nt {\nint64_t inverse(int64_t a, int64_t\
    \ b) {\n  long long b0 = b, t, q;\n  long long x0 = 0, x1 = 1;\n  if (b == 1)\n\
    \    return 1;\n  while (a > 1) {\n    q = a / b;\n    t = b, b = a % b, a = t;\n\
    \    t = x0, x0 = x1 - q * x0, x1 = t;\n  }\n  if (x1 < 0)\n    x1 += b0;\n  return\
    \ x1;\n}\ntemplate<typename T, typename U>\nT powmod (T a, U b, U p) {\n    int\
    \ res = 1;\n    while (b)\n        if (b & 1)\n            res = int (res * 1ll\
    \ * a % p),  --b;\n        else\n            a = int (a * 1ll * a % p),  b >>=\
    \ 1;\n    return res;\n}\ntemplate<typename T>\nvector<T> factors(T n) {\n  vector<T>\
    \ f;\n  for(T i = 2; i*i <= n; i++) {\n    if(n % i == 0) f.push_back(i);\n  \
    \  while(n % i == 0) n /= i;\n  }\n  if(n > 1) f.push_back(n);\n  return f;\n\
    }\n} // namespace nt\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_NUMBER_THEORY\n#define _LIB_NUMBER_THEORY\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace nt {\nint64_t inverse(int64_t\
    \ a, int64_t b) {\n  long long b0 = b, t, q;\n  long long x0 = 0, x1 = 1;\n  if\
    \ (b == 1)\n    return 1;\n  while (a > 1) {\n    q = a / b;\n    t = b, b = a\
    \ % b, a = t;\n    t = x0, x0 = x1 - q * x0, x1 = t;\n  }\n  if (x1 < 0)\n   \
    \ x1 += b0;\n  return x1;\n}\ntemplate<typename T, typename U>\nT powmod (T a,\
    \ U b, U p) {\n    int res = 1;\n    while (b)\n        if (b & 1)\n         \
    \   res = int (res * 1ll * a % p),  --b;\n        else\n            a = int (a\
    \ * 1ll * a % p),  b >>= 1;\n    return res;\n}\ntemplate<typename T>\nvector<T>\
    \ factors(T n) {\n  vector<T> f;\n  for(T i = 2; i*i <= n; i++) {\n    if(n %\
    \ i == 0) f.push_back(i);\n    while(n % i == 0) n /= i;\n  }\n  if(n > 1) f.push_back(n);\n\
    \  return f;\n}\n} // namespace nt\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: NumberTheory.cpp
  requiredBy:
  - FHT.cpp
  - ModularInteger.cpp
  - LinearRecurrence.cpp
  - polynomial/MultipointEvaluation.cpp
  - RollingHash.cpp
  - PowerSeries.cpp
  - NTT.cpp
  - PolynomialRing.cpp
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/yosupo/and-convolution.test.cpp
  - tests/yosupo/subset-sum.test.cpp
  - tests/yosupo/fht-convolution.test.cpp
  - tests/yosupo/fps-power.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/exp-sum.test.cpp
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/subset-convolution.test.cpp
  - tests/yosupo/fps-inv.test.cpp
  - tests/yosupo/exp-sum-limit.test.cpp
  - tests/yosupo/find-lr.test.cpp
documentation_of: NumberTheory.cpp
layout: document
redirect_from:
- /library/NumberTheory.cpp
- /library/NumberTheory.cpp.html
title: NumberTheory.cpp
---
