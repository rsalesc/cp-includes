---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: dsu/BinaryLifting.cpp
    title: dsu/BinaryLifting.cpp
  - icon: ':warning:'
    path: dsu/SpanningTree.cpp
    title: dsu/SpanningTree.cpp
  - icon: ':heavy_check_mark:'
    path: graphs/BlockCut.cpp
    title: graphs/BlockCut.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/biconnected-components.test.cpp
    title: tests/yosupo/biconnected-components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/LazyArray.cpp\"\n\n\n#include <bits/stdc++.h>\n\n\
    namespace lib {\n  using namespace std;\ntemplate<typename T>\nstruct LazyArray\
    \ {\n  vector<T> v;\n  vector<int> lz;\n  T lz_v;\n  int tempo = 1;\n\n  LazyArray()\
    \ {}\n  LazyArray(int n, T lz_v) : v(n), lz(n), lz_v(lz_v) {}\n\n  int size()\
    \ const { return v.size(); }\n  void fill(T vv) { lz_v = vv, tempo++; }\n  void\
    \ clear() {\n    fill(T());\n  }\n  T get(int i) const {\n    return tempo ==\
    \ lz[i] ? v[i] : lz_v;\n  }\n  T operator[](int i) const {\n    return get(i);\n\
    \  }\n  T& operator[](int i) {\n    if(lz[i] != tempo) {\n      lz[i] = tempo;\n\
    \      v[i] = lz_v;\n    }\n    return v[i];\n  }\n};\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_LAZY_ARRAY\n#define _LIB_LAZY_ARRAY\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\n  using namespace std;\ntemplate<typename T>\nstruct LazyArray\
    \ {\n  vector<T> v;\n  vector<int> lz;\n  T lz_v;\n  int tempo = 1;\n\n  LazyArray()\
    \ {}\n  LazyArray(int n, T lz_v) : v(n), lz(n), lz_v(lz_v) {}\n\n  int size()\
    \ const { return v.size(); }\n  void fill(T vv) { lz_v = vv, tempo++; }\n  void\
    \ clear() {\n    fill(T());\n  }\n  T get(int i) const {\n    return tempo ==\
    \ lz[i] ? v[i] : lz_v;\n  }\n  T operator[](int i) const {\n    return get(i);\n\
    \  }\n  T& operator[](int i) {\n    if(lz[i] != tempo) {\n      lz[i] = tempo;\n\
    \      v[i] = lz_v;\n    }\n    return v[i];\n  }\n};\n} // namespace lib\n\n\
    #endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: utils/LazyArray.cpp
  requiredBy:
  - dsu/SpanningTree.cpp
  - dsu/BinaryLifting.cpp
  - graphs/BlockCut.cpp
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/biconnected-components.test.cpp
documentation_of: utils/LazyArray.cpp
layout: document
redirect_from:
- /library/utils/LazyArray.cpp
- /library/utils/LazyArray.cpp.html
title: utils/LazyArray.cpp
---
