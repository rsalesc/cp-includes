---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: BitTricks.cpp
    title: BitTricks.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FFT.cpp
    title: FFT.cpp
  - icon: ':question:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':question:'
    path: NTT.cpp
    title: NTT.cpp
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
  - icon: ':x:'
    path: tests/yosupo/fps-power.test.cpp
    title: tests/yosupo/fps-power.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/kth-term-lr.test.cpp
    title: tests/yosupo/kth-term-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/multipoint.test.cpp
    title: tests/yosupo/multipoint.test.cpp
  - icon: ':x:'
    path: tests/yosupo/subset-sum.test.cpp
    title: tests/yosupo/subset-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DFT.cpp\"\n\n\n#include <bits/stdc++.h>\n#line 1 \"BitTricks.cpp\"\
    \n\n\n#line 4 \"BitTricks.cpp\"\n\nnamespace lib {\nlong long next_power_of_two(long\
    \ long n) {\n  return 1LL << (sizeof(long long) * 8 - 1 - __builtin_clzll(n) +\n\
    \                 ((n & (n - 1LL)) != 0));\n}\n} // namespace lib\n\n\n#line 5\
    \ \"DFT.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace linalg {\ntemplate\
    \ <typename Ring, typename Provider>\nstruct DFT {\n  static vector<int> rev;\n\
    \  static vector<Ring> fa;\n\n  // function used to precompute rev for fixed size\
    \ fft (n is a power of two)\n  static void dft_rev(int n) {\n    Provider()(n);\n\
    \    int lbn = __builtin_ctz(n);\n    if ((int)rev.size() < (1 << lbn))\n    \
    \  rev.resize(1 << lbn);\n    int h = -1;\n    for (int i = 1; i < n; i++) {\n\
    \      if ((i & (i - 1)) == 0)\n        h++;\n      rev[i] = rev[i ^ (1 << h)]\
    \ | (1 << (lbn - h - 1));\n    }\n  }\n\n  static void dft_iter(Ring *p, int n)\
    \ {\n    Provider w;\n    for (int L = 2; L <= n; L <<= 1) {\n      for (int i\
    \ = 0; i < n; i += L) {\n        for (int j = 0; j < L / 2; j++) {\n         \
    \ Ring z = p[i + j + L / 2] * w[j + L / 2];\n          p[i + j + L / 2] = p[i\
    \ + j] - z;\n          p[i + j] += z;\n        }\n      }\n    }\n  }\n\n  static\
    \ void swap(vector<Ring> &buf) { std::swap(fa, buf); }\n  static void _dft(Ring\
    \ *p, int n) {\n    dft_rev(n);\n    for (int i = 0; i < n; i++)\n      if (i\
    \ < rev[i])\n        std::swap(p[i], p[rev[i]]);\n    dft_iter(p, n);\n  }\n \
    \ static void _idft(Ring *p, int n) {\n    _dft(p, n);\n    reverse(p + 1, p +\
    \ n);\n    Ring inv = Provider().inverse(n);\n    for (int i = 0; i < n; i++)\n\
    \      p[i] *= inv;\n  }\n\n  static void dft(int n) { _dft(fa.data(), n); }\n\
    \n  static void idft(int n) { _idft(fa.data(), n); }\n\n  static void dft(vector<Ring>\
    \ &v, int n) {\n    swap(v);\n    dft(n);\n    swap(v);\n  }\n  static void idft(vector<Ring>\
    \ &v, int n) {\n    swap(v);\n    idft(n);\n    swap(v);\n  }\n\n  static int\
    \ ensure(int a, int b = 0) {\n    int n = a+b;\n    n = next_power_of_two(n);\n\
    \    if ((int)fa.size() < n)\n      fa.resize(n);\n    return n;\n  }\n\n  static\
    \ void clear(int n) { fill(fa.begin(), fa.begin() + n, 0); }\n\n  template<typename\
    \ Iterator>\n  static void fill(Iterator begin, Iterator end) {\n    int n = ensure(distance(begin,\
    \ end));\n    int i = 0;\n    for(auto it = begin; it != end; ++it) {\n      fa[i++]\
    \ = *it;\n    }\n    for(;i < n; i++) fa[i] = Ring();\n  }\n};\n\ntemplate<typename\
    \ DF, typename U>\nstatic vector<U> retrieve(int n) {\n  assert(n <= DF::fa.size());\n\
    \  vector<U> res(n);\n  for(int i = 0; i < n; i++) res[i] = (U)DF::fa[i];\n  return\
    \ res;\n}\n\ntemplate<typename Ring, typename Provider>\nvector<int> DFT<Ring,\
    \ Provider>::rev = vector<int>();\n\ntemplate<typename Ring, typename Provider>\n\
    vector<Ring> DFT<Ring, Provider>::fa = vector<Ring>();\n}\n} // namespace lib\n\
    \n\n"
  code: "#ifndef _LIB_DFT\n#define _LIB_DFT\n#include <bits/stdc++.h>\n#include \"\
    BitTricks.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace linalg {\n\
    template <typename Ring, typename Provider>\nstruct DFT {\n  static vector<int>\
    \ rev;\n  static vector<Ring> fa;\n\n  // function used to precompute rev for\
    \ fixed size fft (n is a power of two)\n  static void dft_rev(int n) {\n    Provider()(n);\n\
    \    int lbn = __builtin_ctz(n);\n    if ((int)rev.size() < (1 << lbn))\n    \
    \  rev.resize(1 << lbn);\n    int h = -1;\n    for (int i = 1; i < n; i++) {\n\
    \      if ((i & (i - 1)) == 0)\n        h++;\n      rev[i] = rev[i ^ (1 << h)]\
    \ | (1 << (lbn - h - 1));\n    }\n  }\n\n  static void dft_iter(Ring *p, int n)\
    \ {\n    Provider w;\n    for (int L = 2; L <= n; L <<= 1) {\n      for (int i\
    \ = 0; i < n; i += L) {\n        for (int j = 0; j < L / 2; j++) {\n         \
    \ Ring z = p[i + j + L / 2] * w[j + L / 2];\n          p[i + j + L / 2] = p[i\
    \ + j] - z;\n          p[i + j] += z;\n        }\n      }\n    }\n  }\n\n  static\
    \ void swap(vector<Ring> &buf) { std::swap(fa, buf); }\n  static void _dft(Ring\
    \ *p, int n) {\n    dft_rev(n);\n    for (int i = 0; i < n; i++)\n      if (i\
    \ < rev[i])\n        std::swap(p[i], p[rev[i]]);\n    dft_iter(p, n);\n  }\n \
    \ static void _idft(Ring *p, int n) {\n    _dft(p, n);\n    reverse(p + 1, p +\
    \ n);\n    Ring inv = Provider().inverse(n);\n    for (int i = 0; i < n; i++)\n\
    \      p[i] *= inv;\n  }\n\n  static void dft(int n) { _dft(fa.data(), n); }\n\
    \n  static void idft(int n) { _idft(fa.data(), n); }\n\n  static void dft(vector<Ring>\
    \ &v, int n) {\n    swap(v);\n    dft(n);\n    swap(v);\n  }\n  static void idft(vector<Ring>\
    \ &v, int n) {\n    swap(v);\n    idft(n);\n    swap(v);\n  }\n\n  static int\
    \ ensure(int a, int b = 0) {\n    int n = a+b;\n    n = next_power_of_two(n);\n\
    \    if ((int)fa.size() < n)\n      fa.resize(n);\n    return n;\n  }\n\n  static\
    \ void clear(int n) { fill(fa.begin(), fa.begin() + n, 0); }\n\n  template<typename\
    \ Iterator>\n  static void fill(Iterator begin, Iterator end) {\n    int n = ensure(distance(begin,\
    \ end));\n    int i = 0;\n    for(auto it = begin; it != end; ++it) {\n      fa[i++]\
    \ = *it;\n    }\n    for(;i < n; i++) fa[i] = Ring();\n  }\n};\n\ntemplate<typename\
    \ DF, typename U>\nstatic vector<U> retrieve(int n) {\n  assert(n <= DF::fa.size());\n\
    \  vector<U> res(n);\n  for(int i = 0; i < n; i++) res[i] = (U)DF::fa[i];\n  return\
    \ res;\n}\n\ntemplate<typename Ring, typename Provider>\nvector<int> DFT<Ring,\
    \ Provider>::rev = vector<int>();\n\ntemplate<typename Ring, typename Provider>\n\
    vector<Ring> DFT<Ring, Provider>::fa = vector<Ring>();\n}\n} // namespace lib\n\
    \n#endif\n"
  dependsOn:
  - bits/stdc++.h
  - BitTricks.cpp
  isVerificationFile: false
  path: DFT.cpp
  requiredBy:
  - FHT.cpp
  - FFT.cpp
  - NTT.cpp
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/yosupo/subset-sum.test.cpp
  - tests/yosupo/fht-convolution.test.cpp
  - tests/yosupo/fps-power.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/fps-inv.test.cpp
  - tests/yosupo/find-lr.test.cpp
documentation_of: DFT.cpp
layout: document
redirect_from:
- /library/DFT.cpp
- /library/DFT.cpp.html
title: DFT.cpp
---
