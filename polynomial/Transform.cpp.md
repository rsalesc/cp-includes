---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':warning:'
    path: tests/yosupo/convolution.cpp
    title: tests/yosupo/convolution.cpp
  - icon: ':warning:'
    path: tests/yosupo/fps_power.cpp
    title: tests/yosupo/fps_power.cpp
  - icon: ':warning:'
    path: tests/yosupo/kth_term_lr.cpp
    title: tests/yosupo/kth_term_lr.cpp
  - icon: ':warning:'
    path: tests/yosupo/lr.cpp
    title: tests/yosupo/lr.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
  dependsOn: []
  isVerificationFile: false
  path: polynomial/Transform.cpp
  requiredBy:
  - FHT.cpp
  - tests/yosupo/convolution.cpp
  - tests/yosupo/fps_power.cpp
  - tests/yosupo/kth_term_lr.cpp
  - tests/yosupo/lr.cpp
  timestamp: '2021-01-30 22:31:25-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: polynomial/Transform.cpp
layout: document
redirect_from:
- /library/polynomial/Transform.cpp
- /library/polynomial/Transform.cpp.html
title: polynomial/Transform.cpp
---
