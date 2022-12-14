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
  - icon: ':x:'
    path: tests/yosupo/subset-sum.test.cpp
    title: tests/yosupo/subset-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"polynomial/Transform.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\ntemplate<template <class> class T>\n\
    struct TransformMultiplication {\n  template<typename Field>\n  using Transform\
    \ = T<Field>;\n\n  template <typename Field>\n  vector<Field> operator()(const\
    \ vector<Field> &a,\n                           const vector<Field> &b) const\
    \ {\n    return T<Field>::convolve(a, b);\n  };\n\n  template<typename Field>\n\
    \  inline VectorN<Field> transform(int n, const vector<Field>& p) const {\n  \
    \  int np = next_power_of_two(n);\n    return T<Field>::transform(p, np);\n  }\n\
    \n  template<typename Field>\n  inline vector<Field> itransform(int n, const vector<Field>&\
    \ p) const {\n    return T<Field>::itransform(p, n);\n  }\n\n  template <typename\
    \ Field, typename Functor, typename ...Ts>\n  inline vector<Field> on_transform(\n\
    \    int n,\n    Functor& f,        \n    const vector<Ts>&... vs) const {\n \
    \   int np = next_power_of_two(n);\n    return T<Field>::itransform(\n      f(n,\
    \ T<Field>::transform(vs, np)...), n);\n  }\n};\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_POLYNOMIAL_TRANSFORM\n#define _LIB_POLYNOMIAL_TRANSFORM\n#include\
    \ <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\ntemplate<template\
    \ <class> class T>\nstruct TransformMultiplication {\n  template<typename Field>\n\
    \  using Transform = T<Field>;\n\n  template <typename Field>\n  vector<Field>\
    \ operator()(const vector<Field> &a,\n                           const vector<Field>\
    \ &b) const {\n    return T<Field>::convolve(a, b);\n  };\n\n  template<typename\
    \ Field>\n  inline VectorN<Field> transform(int n, const vector<Field>& p) const\
    \ {\n    int np = next_power_of_two(n);\n    return T<Field>::transform(p, np);\n\
    \  }\n\n  template<typename Field>\n  inline vector<Field> itransform(int n, const\
    \ vector<Field>& p) const {\n    return T<Field>::itransform(p, n);\n  }\n\n \
    \ template <typename Field, typename Functor, typename ...Ts>\n  inline vector<Field>\
    \ on_transform(\n    int n,\n    Functor& f,        \n    const vector<Ts>&...\
    \ vs) const {\n    int np = next_power_of_two(n);\n    return T<Field>::itransform(\n\
    \      f(n, T<Field>::transform(vs, np)...), n);\n  }\n};\n} // namespace lib\n\
    \n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: polynomial/Transform.cpp
  requiredBy:
  - FHT.cpp
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/fps-power.test.cpp
  - tests/yosupo/find-lr.test.cpp
  - tests/yosupo/fht-convolution.test.cpp
  - tests/yosupo/fps-inv.test.cpp
  - tests/yosupo/subset-sum.test.cpp
documentation_of: polynomial/Transform.cpp
layout: document
redirect_from:
- /library/polynomial/Transform.cpp
- /library/polynomial/Transform.cpp.html
title: polynomial/Transform.cpp
---
