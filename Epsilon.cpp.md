---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':heavy_check_mark:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':heavy_check_mark:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':warning:'
    path: geometry/Caliper.cpp
    title: geometry/Caliper.cpp
  - icon: ':warning:'
    path: geometry/Circle2D.cpp
    title: geometry/Circle2D.cpp
  - icon: ':warning:'
    path: geometry/GeometryEpsilon.cpp
    title: geometry/GeometryEpsilon.cpp
  - icon: ':warning:'
    path: geometry/Line2D.cpp
    title: geometry/Line2D.cpp
  - icon: ':warning:'
    path: geometry/Polygon2D.cpp
    title: geometry/Polygon2D.cpp
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
  bundledCode: "#line 1 \"Epsilon.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\n\ntemplate <typename T = double> struct Epsilon\
    \ {\n  T eps;\n  constexpr Epsilon(T eps = 1e-9) : eps(eps) {}\n\n  template <typename\
    \ G,\n            typename enable_if<is_floating_point<G>::value>::type * = nullptr>\n\
    \  int operator()(G a, G b = 0) const {\n    return a + eps < b ? -1 : (b + eps\
    \ < a ? 1 : 0);\n  }\n\n  template <typename G,\n            typename enable_if<!is_floating_point<G>::value>::type\
    \ * = nullptr>\n  int operator()(G a, G b = 0) const {\n    return a < b ? -1\
    \ : (a > b ? 1 : 0);\n  }\n\n  template <typename G,\n            typename enable_if<is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return (*this)(a) == 0;\n  }\n\n\
    \  template <typename G,\n            typename enable_if<!is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return a == 0;\n  }\n};\n} // namespace\
    \ lib\n\n\n"
  code: "#ifndef _LIB_EPSILON\n#define _LIB_EPSILON\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\n\ntemplate <typename T = double> struct\
    \ Epsilon {\n  T eps;\n  constexpr Epsilon(T eps = 1e-9) : eps(eps) {}\n\n  template\
    \ <typename G,\n            typename enable_if<is_floating_point<G>::value>::type\
    \ * = nullptr>\n  int operator()(G a, G b = 0) const {\n    return a + eps < b\
    \ ? -1 : (b + eps < a ? 1 : 0);\n  }\n\n  template <typename G,\n            typename\
    \ enable_if<!is_floating_point<G>::value>::type * = nullptr>\n  int operator()(G\
    \ a, G b = 0) const {\n    return a < b ? -1 : (a > b ? 1 : 0);\n  }\n\n  template\
    \ <typename G,\n            typename enable_if<is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return (*this)(a) == 0;\n  }\n\n\
    \  template <typename G,\n            typename enable_if<!is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return a == 0;\n  }\n};\n} // namespace\
    \ lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Epsilon.cpp
  requiredBy:
  - PolynomialRing.cpp
  - LinearRecurrence.cpp
  - polynomial/MultipointEvaluation.cpp
  - PowerSeries.cpp
  - geometry/Polygon2D.cpp
  - geometry/Circle2D.cpp
  - geometry/Line2D.cpp
  - geometry/Caliper.cpp
  - geometry/GeometryEpsilon.cpp
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/fps-power.test.cpp
  - tests/yosupo/subset-sum.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/fps-inv.test.cpp
  - tests/yosupo/find-lr.test.cpp
documentation_of: Epsilon.cpp
layout: document
redirect_from:
- /library/Epsilon.cpp
- /library/Epsilon.cpp.html
title: Epsilon.cpp
---
