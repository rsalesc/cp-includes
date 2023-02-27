---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Epsilon.cpp
    title: Epsilon.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/Caliper.cpp
    title: geometry/Caliper.cpp
  - icon: ':warning:'
    path: geometry/Circle2D.cpp
    title: geometry/Circle2D.cpp
  - icon: ':warning:'
    path: geometry/Line2D.cpp
    title: geometry/Line2D.cpp
  - icon: ':warning:'
    path: geometry/Polygon2D.cpp
    title: geometry/Polygon2D.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/GeometryEpsilon.cpp\"\n\n\n#line 1 \"Epsilon.cpp\"\
    \n\n\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\n\ntemplate\
    \ <typename T = double> struct Epsilon {\n  T eps;\n  constexpr Epsilon(T eps\
    \ = 1e-9) : eps(eps) {}\n\n  template <typename G,\n            typename enable_if<is_floating_point<G>::value>::type\
    \ * = nullptr>\n  int operator()(G a, G b = 0) const {\n    return a + eps < b\
    \ ? -1 : (b + eps < a ? 1 : 0);\n  }\n\n  template <typename G,\n            typename\
    \ enable_if<!is_floating_point<G>::value>::type * = nullptr>\n  int operator()(G\
    \ a, G b = 0) const {\n    return a < b ? -1 : (a > b ? 1 : 0);\n  }\n\n  template\
    \ <typename G,\n            typename enable_if<is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return (*this)(a) == 0;\n  }\n\n\
    \  template <typename G,\n            typename enable_if<!is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return a == 0;\n  }\n};\n} // namespace\
    \ lib\n\n\n#line 5 \"geometry/GeometryEpsilon.cpp\"\n\n#define GEOMETRY_EPSILON(T,\
    \ x)                                                 \\\n  template <>       \
    \                                                           \\\n  lib::Epsilon<T>\
    \ *lib::geo::GeometryEpsilon<T>::eps =                         \\\n      new lib::Epsilon<T>((x));\n\
    \n#define GEOMETRY_COMPARE0(T, x) GeometryEpsilon<T>()((x))\n#define GEOMETRY_COMPARE(T,\
    \ x, y) GeometryEpsilon<T>()((x), (y))\n\nnamespace lib {\nusing namespace std;\n\
    namespace geo {\ntemplate <typename T> struct GeometryEpsilon {\n  static Epsilon<T>\
    \ *eps;\n  template <typename G> int operator()(G a, G b = 0) const {\n    return\
    \ (*eps)(a, b);\n  }\n};\n\nGEOMETRY_EPSILON(int, 0);\nGEOMETRY_EPSILON(long,\
    \ 0);\nGEOMETRY_EPSILON(long long, 0);\n} // namespace geo\n} // namespace lib\n\
    \n\n"
  code: "#ifndef _LIB_GEOMETRY_EPSILON\n#define _LIB_GEOMETRY_EPSILON\n#include \"\
    ../Epsilon.cpp\"\n#include <bits/stdc++.h>\n\n#define GEOMETRY_EPSILON(T, x) \
    \                                                \\\n  template <>           \
    \                                                       \\\n  lib::Epsilon<T>\
    \ *lib::geo::GeometryEpsilon<T>::eps =                         \\\n      new lib::Epsilon<T>((x));\n\
    \n#define GEOMETRY_COMPARE0(T, x) GeometryEpsilon<T>()((x))\n#define GEOMETRY_COMPARE(T,\
    \ x, y) GeometryEpsilon<T>()((x), (y))\n\nnamespace lib {\nusing namespace std;\n\
    namespace geo {\ntemplate <typename T> struct GeometryEpsilon {\n  static Epsilon<T>\
    \ *eps;\n  template <typename G> int operator()(G a, G b = 0) const {\n    return\
    \ (*eps)(a, b);\n  }\n};\n\nGEOMETRY_EPSILON(int, 0);\nGEOMETRY_EPSILON(long,\
    \ 0);\nGEOMETRY_EPSILON(long long, 0);\n} // namespace geo\n} // namespace lib\n\
    \n#endif\n"
  dependsOn:
  - Epsilon.cpp
  - bits/stdc++.h
  isVerificationFile: false
  path: geometry/GeometryEpsilon.cpp
  requiredBy:
  - geometry/Polygon2D.cpp
  - geometry/Caliper.cpp
  - geometry/Line2D.cpp
  - geometry/Circle2D.cpp
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/GeometryEpsilon.cpp
layout: document
redirect_from:
- /library/geometry/GeometryEpsilon.cpp
- /library/geometry/GeometryEpsilon.cpp.html
title: geometry/GeometryEpsilon.cpp
---
