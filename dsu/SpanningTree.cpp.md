---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':heavy_check_mark:'
    path: utils/LazyArray.cpp
    title: utils/LazyArray.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: dsu/BinaryLifting.cpp
    title: dsu/BinaryLifting.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dsu/SpanningTree.cpp\"\n\n\n#include <bits/stdc++.h>\n#line\
    \ 1 \"utils/LazyArray.cpp\"\n\n\n#line 4 \"utils/LazyArray.cpp\"\n\nnamespace\
    \ lib {\n  using namespace std;\ntemplate<typename T>\nstruct LazyArray {\n  vector<T>\
    \ v;\n  vector<int> lz;\n  T lz_v;\n  int tempo = 1;\n\n  LazyArray() {}\n  LazyArray(int\
    \ n, T lz_v) : v(n), lz(n), lz_v(lz_v) {}\n\n  int size() const { return v.size();\
    \ }\n  void fill(T vv) { lz_v = vv, tempo++; }\n  void clear() {\n    fill(T());\n\
    \  }\n  T get(int i) const {\n    return tempo == lz[i] ? v[i] : lz_v;\n  }\n\
    \  T operator[](int i) const {\n    return get(i);\n  }\n  T& operator[](int i)\
    \ {\n    if(lz[i] != tempo) {\n      lz[i] = tempo;\n      v[i] = lz_v;\n    }\n\
    \    return v[i];\n  }\n};\n} // namespace lib\n\n\n#line 5 \"dsu/SpanningTree.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\nnamespace dsu {\n\nconst auto no_op_visitor\
    \ = [](int, int, const vector<int>&) -> void {};\n\ntemplate<typename D>\nstruct\
    \ SpanningTree : public D {\n  using D::last_swapped_;\n\n  vector<vector<int>>\
    \ adj;\n  vector<int> pai, depth;\n  LazyArray<char> vis;\n  pair<int, int> last_edge_;\n\
    \n  SpanningTree() : D() {}\n  SpanningTree(int n) : D(n), adj(n), pai(n, -1),\
    \ vis(n, 0), depth(n, 0) {}\n  virtual void clear() override {\n    D::clear();\n\
    \    for(int i = 0; i < adj.size(); i++)\n      adj[i].clear();\n    fill(pai.begin(),\
    \ pai.end(), -1);\n    fill(depth.begin(), depth.end(), 0);\n    vis.clear();\n\
    \    last_edge_ = {-1, -1};\n  }\n  virtual int merge(int u, int v) override {\n\
    \    if(!D::merge(u, v)) return 0;\n    if(last_swapped_)\n      swap(u, v);\n\
    \    last_edge_ = {u, v};\n    vis.clear();\n    fix_(u, v, depth[v]+1);\n   \
    \ adj[u].push_back(v);\n    adj[v].push_back(u);\n    return 1;\n  }\n  template<typename\
    \ F, typename G>\n  void traverse_last_small(const F& f, const G& g) {\n    vis.clear();\n\
    \    traverse_(last_edge_.first, last_edge_.second, f, g);\n  }\n  template<typename\
    \ F, typename G>\n  void traverse_(int u, int p, const F& f, const G& g) {\n \
    \   if(vis.get(u)) return;\n    vis[u] = 1;\n    f(u, p, adj[u]);\n    for(int\
    \ v : adj[u]) {\n      if(v == p || vis.get(v)) continue;\n      traverse_(v,\
    \ u, f, g);\n    }\n    g(u, p, adj[u]);\n  }\n  void fix_(int u, int p, int d)\
    \ {\n    if(vis.get(u)) return;\n    vis[u] = 1;\n    pai[u] = p;\n    depth[u]\
    \ = d;\n    for(int v : adj[u]) {\n      if(v == p || vis.get(v)) continue;\n\
    \      fix_(v, u, d+1);\n    }\n  }\n  pair<int, int> last_edge() const {\n  \
    \  return last_edge_;\n  }\n  int parent(int i) const {\n    return pai[i];\n\
    \  }\n};\n} // namespace dsu\n} // namespace lib\n\n\n\n"
  code: "#ifndef _LIB_DSU_SPANNING_TREE\n#define _LIB_DSU_SPANNING_TREE\n#include\
    \ <bits/stdc++.h>\n#include \"../utils/LazyArray.cpp\"\n\nnamespace lib {\nusing\
    \ namespace std;\nnamespace dsu {\n\nconst auto no_op_visitor = [](int, int, const\
    \ vector<int>&) -> void {};\n\ntemplate<typename D>\nstruct SpanningTree : public\
    \ D {\n  using D::last_swapped_;\n\n  vector<vector<int>> adj;\n  vector<int>\
    \ pai, depth;\n  LazyArray<char> vis;\n  pair<int, int> last_edge_;\n\n  SpanningTree()\
    \ : D() {}\n  SpanningTree(int n) : D(n), adj(n), pai(n, -1), vis(n, 0), depth(n,\
    \ 0) {}\n  virtual void clear() override {\n    D::clear();\n    for(int i = 0;\
    \ i < adj.size(); i++)\n      adj[i].clear();\n    fill(pai.begin(), pai.end(),\
    \ -1);\n    fill(depth.begin(), depth.end(), 0);\n    vis.clear();\n    last_edge_\
    \ = {-1, -1};\n  }\n  virtual int merge(int u, int v) override {\n    if(!D::merge(u,\
    \ v)) return 0;\n    if(last_swapped_)\n      swap(u, v);\n    last_edge_ = {u,\
    \ v};\n    vis.clear();\n    fix_(u, v, depth[v]+1);\n    adj[u].push_back(v);\n\
    \    adj[v].push_back(u);\n    return 1;\n  }\n  template<typename F, typename\
    \ G>\n  void traverse_last_small(const F& f, const G& g) {\n    vis.clear();\n\
    \    traverse_(last_edge_.first, last_edge_.second, f, g);\n  }\n  template<typename\
    \ F, typename G>\n  void traverse_(int u, int p, const F& f, const G& g) {\n \
    \   if(vis.get(u)) return;\n    vis[u] = 1;\n    f(u, p, adj[u]);\n    for(int\
    \ v : adj[u]) {\n      if(v == p || vis.get(v)) continue;\n      traverse_(v,\
    \ u, f, g);\n    }\n    g(u, p, adj[u]);\n  }\n  void fix_(int u, int p, int d)\
    \ {\n    if(vis.get(u)) return;\n    vis[u] = 1;\n    pai[u] = p;\n    depth[u]\
    \ = d;\n    for(int v : adj[u]) {\n      if(v == p || vis.get(v)) continue;\n\
    \      fix_(v, u, d+1);\n    }\n  }\n  pair<int, int> last_edge() const {\n  \
    \  return last_edge_;\n  }\n  int parent(int i) const {\n    return pai[i];\n\
    \  }\n};\n} // namespace dsu\n} // namespace lib\n\n#endif\n\n"
  dependsOn:
  - bits/stdc++.h
  - utils/LazyArray.cpp
  isVerificationFile: false
  path: dsu/SpanningTree.cpp
  requiredBy:
  - dsu/BinaryLifting.cpp
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dsu/SpanningTree.cpp
layout: document
redirect_from:
- /library/dsu/SpanningTree.cpp
- /library/dsu/SpanningTree.cpp.html
title: dsu/SpanningTree.cpp
---
