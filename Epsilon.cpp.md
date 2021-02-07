---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':warning:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':warning:'
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
  - icon: ':warning:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
  - PowerSeries.cpp
  - LinearRecurrence.cpp
  - PolynomialRing.cpp
  - geometry/Line2D.cpp
  - geometry/Polygon2D.cpp
  - geometry/GeometryEpsilon.cpp
  - geometry/Circle2D.cpp
  - geometry/Caliper.cpp
  - polynomial/MultipointEvaluation.cpp
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Epsilon.cpp
layout: document
redirect_from:
- /library/Epsilon.cpp
- /library/Epsilon.cpp.html
title: Epsilon.cpp
---
