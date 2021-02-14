---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph.cpp
    title: Graph.cpp
  - icon: ':warning:'
    path: HLD.cpp
    title: HLD.cpp
  - icon: ':warning:'
    path: Maxflow.cpp
    title: Maxflow.cpp
  - icon: ':warning:'
    path: SegtreeHLD.cpp
    title: SegtreeHLD.cpp
  - icon: ':heavy_check_mark:'
    path: TwoSat.cpp
    title: TwoSat.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/2sat.test.cpp
    title: tests/yosupo/2sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/chordal.test.cpp
    title: tests/yosupo/chordal.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/Wrappers.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace graph {\ntemplate <typename T> struct\
    \ Edge {\n  const int from, to;\n  T data;\n};\n\ntemplate <> struct Edge<void>\
    \ { const int from, to; };\n\ntemplate <typename T> struct VertexWrapper { T data;\
    \ };\n\ntemplate <> struct VertexWrapper<void> {};\n} // namespace graph\n} //\
    \ namespace lib\n\n\n"
  code: "#ifndef _LIB_WRAPPERS\n#define _LIB_WRAPPERS\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\nnamespace graph {\ntemplate <typename T>\
    \ struct Edge {\n  const int from, to;\n  T data;\n};\n\ntemplate <> struct Edge<void>\
    \ { const int from, to; };\n\ntemplate <typename T> struct VertexWrapper { T data;\
    \ };\n\ntemplate <> struct VertexWrapper<void> {};\n} // namespace graph\n} //\
    \ namespace lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/Wrappers.cpp
  requiredBy:
  - SegtreeHLD.cpp
  - Maxflow.cpp
  - HLD.cpp
  - TwoSat.cpp
  - Graph.cpp
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/chordal.test.cpp
  - tests/yosupo/2sat.test.cpp
documentation_of: utils/Wrappers.cpp
layout: document
redirect_from:
- /library/utils/Wrappers.cpp
- /library/utils/Wrappers.cpp.html
title: utils/Wrappers.cpp
---
