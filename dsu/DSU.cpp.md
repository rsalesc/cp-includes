---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dsu/DSU.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace dsu {\nstruct RankDSU {\n  mutable vector<int>\
    \ r, sz;\n  pair<int, int> last_merge_ = {-1, -1};\n  bool last_swapped_ = false;\n\
    \  int merges = 0;\n  RankDSU() {}\n  RankDSU(int n) : r(n), sz(n, 1) {\n    iota(r.begin(),\
    \ r.end(), 0);\n  }\n  virtual void clear() {\n    iota(r.begin(), r.end(), 0);\n\
    \    fill(sz.begin(), sz.end(), 1);\n    last_merge_ = {-1, -1};\n    merges =\
    \ 0;\n  }\n  virtual int get(int i) const {\n    return r[i] == i ? i : get(r[i]);\n\
    \  }\n  int operator[](int i) const {\n    return get(i);\n  }\n  pair<int, int>\
    \ last_merge() const {\n    return last_merge_;\n  }\n  int n_comps() const {\
    \ return (int)r.size() - merges; }\n  virtual void merged(int u, int v) {}\n \
    \ virtual int merge(int u, int v) {\n    u = get(u), v = get(v);\n    if(u ==\
    \ v) return 0;\n    last_swapped_ = false;\n    if(sz[u] > sz[v]) swap(u, v),\
    \ last_swapped_ = true;\n    r[u] = v;\n    sz[v] += sz[u];\n    last_merge_ =\
    \ {u, v};\n    merged(u, v);\n    return 1;\n  }\n};\n\ntemplate<template<class>\
    \ class ...Ts>\nstruct ByRankImpl;\n\ntemplate<template<class> class T, template<class>\
    \ class ...Ts>\nstruct ByRankImpl<T, Ts...> {\n  using type = T<typename ByRankImpl<Ts...>::type>;\n\
    };\n\ntemplate<>\nstruct ByRankImpl<> {\n  using type = RankDSU;\n};\n\ntemplate<template<class>\
    \ class ...Ts>\nusing ByRank = typename ByRankImpl<Ts...>::type;\n} // namespace\
    \ dsu\n} // namespace lib\n\n\n\n"
  code: "#ifndef _LIB_RANK_DSU\n#define _LIB_RANK_DSU\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\nnamespace dsu {\nstruct RankDSU {\n  mutable\
    \ vector<int> r, sz;\n  pair<int, int> last_merge_ = {-1, -1};\n  bool last_swapped_\
    \ = false;\n  int merges = 0;\n  RankDSU() {}\n  RankDSU(int n) : r(n), sz(n,\
    \ 1) {\n    iota(r.begin(), r.end(), 0);\n  }\n  virtual void clear() {\n    iota(r.begin(),\
    \ r.end(), 0);\n    fill(sz.begin(), sz.end(), 1);\n    last_merge_ = {-1, -1};\n\
    \    merges = 0;\n  }\n  virtual int get(int i) const {\n    return r[i] == i\
    \ ? i : get(r[i]);\n  }\n  int operator[](int i) const {\n    return get(i);\n\
    \  }\n  pair<int, int> last_merge() const {\n    return last_merge_;\n  }\n  int\
    \ n_comps() const { return (int)r.size() - merges; }\n  virtual void merged(int\
    \ u, int v) {}\n  virtual int merge(int u, int v) {\n    u = get(u), v = get(v);\n\
    \    if(u == v) return 0;\n    last_swapped_ = false;\n    if(sz[u] > sz[v]) swap(u,\
    \ v), last_swapped_ = true;\n    r[u] = v;\n    sz[v] += sz[u];\n    last_merge_\
    \ = {u, v};\n    merged(u, v);\n    return 1;\n  }\n};\n\ntemplate<template<class>\
    \ class ...Ts>\nstruct ByRankImpl;\n\ntemplate<template<class> class T, template<class>\
    \ class ...Ts>\nstruct ByRankImpl<T, Ts...> {\n  using type = T<typename ByRankImpl<Ts...>::type>;\n\
    };\n\ntemplate<>\nstruct ByRankImpl<> {\n  using type = RankDSU;\n};\n\ntemplate<template<class>\
    \ class ...Ts>\nusing ByRank = typename ByRankImpl<Ts...>::type;\n} // namespace\
    \ dsu\n} // namespace lib\n\n#endif\n\n"
  dependsOn: []
  isVerificationFile: false
  path: dsu/DSU.cpp
  requiredBy: []
  timestamp: '2021-02-26 00:37:16-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dsu/DSU.cpp
layout: document
redirect_from:
- /library/dsu/DSU.cpp
- /library/dsu/DSU.cpp.html
title: dsu/DSU.cpp
---
