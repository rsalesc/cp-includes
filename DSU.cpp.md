---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: OfflineRMQ.cpp
    title: OfflineRMQ.cpp
  - icon: ':warning:'
    path: matroid/v2/GraphicMatroid.cpp
    title: matroid/v2/GraphicMatroid.cpp
  - icon: ':warning:'
    path: tests/judge/honestidad.cpp
    title: tests/judge/honestidad.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DSU.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace lib\
    \ {\nusing namespace std;\n\nstruct DSU {\n  vector<int> p, ptime, sz;\n  int\
    \ tempo = 0;\n  int merges = 0;\n\n  DSU(int n = 0) : p(n), ptime(n), sz(n, 1)\
    \ { iota(p.begin(), p.end(), 0); }\n\n  int make_node() {\n    int i = p.size();\n\
    \    p.emplace_back(i);\n    ptime.emplace_back(0);\n    sz.emplace_back(1);\n\
    \    return 1;\n  }\n\n  int get(int i, int at) const {\n    return p[i] == i\
    \ ? i : (at >= ptime[i] ? get(p[i], at) : i);\n  }\n\n  int operator[](int i)\
    \ const { return get(i, tempo); }\n\n  int merge(int u, int v) {\n    u = (*this)[u],\
    \ v = (*this)[v];\n    if (u == v)\n      return 0;\n    if (sz[u] < sz[v])\n\
    \      swap(u, v);\n    p[v] = u;\n    ptime[v] = ++tempo;\n    sz[u] += sz[v];\n\
    \    merges++;\n    return 1;\n  }\n\n  int n_comps() const { return (int)p.size()\
    \ - merges; }\n};\n\nstruct CompressedDSU {\n  vector<int> p;\n  CompressedDSU(int\
    \ n = 0) : p(n) { iota(p.begin(), p.end(), 0); }\n  int get(int i) {\n    return\
    \ p[i] == i ? i : p[i] = get(p[i]);\n  }\n  int operator[](int i) { return get(i);\
    \ }\n  int& parent(int i) { return p[i]; }\n};\n\nstruct FastDSU {\n  vector<int>\
    \ p, sz;\n  int merges = 0;\n  FastDSU(int n = 0) : p(n), sz(n, 1) { iota(p.begin(),\
    \ p.end(), 0); }\n\n  int get(int i) {\n    return p[i] == i ? i : p[i] = get(p[i]);\n\
    \  }\n  int operator[](int i) { return get(i); }\n\n  int merge(int u, int v)\
    \ {\n    u = get(u), v = get(v);\n    if(u == v) return 0;\n    if(sz[u] < sz[v])\n\
    \      swap(u, v);\n    p[v] = u;\n    sz[u] += sz[v];\n    merges++;\n    return\
    \ 1;\n  }\n\n  int n_comps() const { return (int)p.size() - merges; }\n};\n} //\
    \ namespace lib\n\n\n"
  code: "#ifndef _LIB_DSU\n#define _LIB_DSU\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\n\nstruct DSU {\n  vector<int> p, ptime, sz;\n \
    \ int tempo = 0;\n  int merges = 0;\n\n  DSU(int n = 0) : p(n), ptime(n), sz(n,\
    \ 1) { iota(p.begin(), p.end(), 0); }\n\n  int make_node() {\n    int i = p.size();\n\
    \    p.emplace_back(i);\n    ptime.emplace_back(0);\n    sz.emplace_back(1);\n\
    \    return 1;\n  }\n\n  int get(int i, int at) const {\n    return p[i] == i\
    \ ? i : (at >= ptime[i] ? get(p[i], at) : i);\n  }\n\n  int operator[](int i)\
    \ const { return get(i, tempo); }\n\n  int merge(int u, int v) {\n    u = (*this)[u],\
    \ v = (*this)[v];\n    if (u == v)\n      return 0;\n    if (sz[u] < sz[v])\n\
    \      swap(u, v);\n    p[v] = u;\n    ptime[v] = ++tempo;\n    sz[u] += sz[v];\n\
    \    merges++;\n    return 1;\n  }\n\n  int n_comps() const { return (int)p.size()\
    \ - merges; }\n};\n\nstruct CompressedDSU {\n  vector<int> p;\n  CompressedDSU(int\
    \ n = 0) : p(n) { iota(p.begin(), p.end(), 0); }\n  int get(int i) {\n    return\
    \ p[i] == i ? i : p[i] = get(p[i]);\n  }\n  int operator[](int i) { return get(i);\
    \ }\n  int& parent(int i) { return p[i]; }\n};\n\nstruct FastDSU {\n  vector<int>\
    \ p, sz;\n  int merges = 0;\n  FastDSU(int n = 0) : p(n), sz(n, 1) { iota(p.begin(),\
    \ p.end(), 0); }\n\n  int get(int i) {\n    return p[i] == i ? i : p[i] = get(p[i]);\n\
    \  }\n  int operator[](int i) { return get(i); }\n\n  int merge(int u, int v)\
    \ {\n    u = get(u), v = get(v);\n    if(u == v) return 0;\n    if(sz[u] < sz[v])\n\
    \      swap(u, v);\n    p[v] = u;\n    sz[u] += sz[v];\n    merges++;\n    return\
    \ 1;\n  }\n\n  int n_comps() const { return (int)p.size() - merges; }\n};\n} //\
    \ namespace lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: DSU.cpp
  requiredBy:
  - matroid/v2/GraphicMatroid.cpp
  - tests/judge/honestidad.cpp
  - OfflineRMQ.cpp
  timestamp: '2021-01-27 17:15:40-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DSU.cpp
layout: document
redirect_from:
- /library/DSU.cpp
- /library/DSU.cpp.html
title: DSU.cpp
---
