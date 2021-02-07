---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':warning:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':heavy_check_mark:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':warning:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':warning:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':warning:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':warning:'
    path: RollingHash.cpp
    title: RollingHash.cpp
  - icon: ':warning:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  - icon: ':warning:'
    path: tests/yosupo/convolution.cpp
    title: tests/yosupo/convolution.cpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/subset-convolution.test.cpp
    title: tests/yosupo/subset-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  dependsOn: []
  isVerificationFile: false
  path: NumberTheory.cpp
  requiredBy:
  - PowerSeries.cpp
  - ModularInteger.cpp
  - LinearRecurrence.cpp
  - PolynomialRing.cpp
  - FHT.cpp
  - RollingHash.cpp
  - NTT.cpp
  - tests/yosupo/multipoint.cpp
  - tests/yosupo/convolution.cpp
  - tests/yosupo/fps_power.cpp
  - tests/yosupo/interplation.cpp
  - tests/yosupo/fps_inv.cpp
  - tests/yosupo/kth_term_lr.cpp
  - tests/yosupo/lr.cpp
  - polynomial/MultipointEvaluation.cpp
  timestamp: '2020-11-07 21:20:50-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/subset-convolution.test.cpp
documentation_of: NumberTheory.cpp
layout: document
redirect_from:
- /library/NumberTheory.cpp
- /library/NumberTheory.cpp.html
title: NumberTheory.cpp
---
