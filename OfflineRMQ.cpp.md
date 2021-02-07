---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DSU.cpp
    title: DSU.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"OfflineRMQ.cpp\"\n\n\n#include <bits/stdc++.h>\n#line 1\
    \ \"DSU.cpp\"\n\n\n#line 4 \"DSU.cpp\"\n\nnamespace lib {\nusing namespace std;\n\
    \nstruct DSU {\n  vector<int> p, ptime, sz;\n  int tempo = 0;\n  int merges =\
    \ 0;\n\n  DSU(int n = 0) : p(n), ptime(n), sz(n, 1) { iota(p.begin(), p.end(),\
    \ 0); }\n\n  int make_node() {\n    int i = p.size();\n    p.emplace_back(i);\n\
    \    ptime.emplace_back(0);\n    sz.emplace_back(1);\n    return 1;\n  }\n\n \
    \ int get(int i, int at) const {\n    return p[i] == i ? i : (at >= ptime[i] ?\
    \ get(p[i], at) : i);\n  }\n\n  int operator[](int i) const { return get(i, tempo);\
    \ }\n\n  int merge(int u, int v) {\n    u = (*this)[u], v = (*this)[v];\n    if\
    \ (u == v)\n      return 0;\n    if (sz[u] < sz[v])\n      swap(u, v);\n    p[v]\
    \ = u;\n    ptime[v] = ++tempo;\n    sz[u] += sz[v];\n    merges++;\n    return\
    \ 1;\n  }\n\n  int n_comps() const { return (int)p.size() - merges; }\n};\n\n\
    struct CompressedDSU {\n  vector<int> p;\n  CompressedDSU(int n = 0) : p(n) {\
    \ iota(p.begin(), p.end(), 0); }\n  int get(int i) {\n    return p[i] == i ? i\
    \ : p[i] = get(p[i]);\n  }\n  int operator[](int i) { return get(i); }\n  int&\
    \ parent(int i) { return p[i]; }\n};\n\nstruct FastDSU {\n  vector<int> p, sz;\n\
    \  int merges = 0;\n  FastDSU(int n = 0) : p(n), sz(n, 1) { iota(p.begin(), p.end(),\
    \ 0); }\n\n  int get(int i) {\n    return p[i] == i ? i : p[i] = get(p[i]);\n\
    \  }\n  int operator[](int i) { return get(i); }\n\n  int merge(int u, int v)\
    \ {\n    u = get(u), v = get(v);\n    if(u == v) return 0;\n    if(sz[u] < sz[v])\n\
    \      swap(u, v);\n    p[v] = u;\n    sz[u] += sz[v];\n    merges++;\n    return\
    \ 1;\n  }\n\n  int n_comps() const { return (int)p.size() - merges; }\n};\n} //\
    \ namespace lib\n\n\n#line 5 \"OfflineRMQ.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\n\n// O(n + qlogn)\ntemplate<typename T, typename U = T>\nvector<T> offline_rmq(const\
    \ vector<T>& v, const vector<pair<U, U>>& qrs) {\n  int n = v.size();\n  vector<vector<pair<U,\
    \ int>>> cont(n);\n  for(int i = 0; i < (int)qrs.size(); i++) {\n    auto p =\
    \ qrs[i];\n    cont[p.second].push_back({p.first, i});\n  }\n  vector<T> ans(qrs.size());\n\
    \n  CompressedDSU dsu(n);\n  vector<U> s;\n  for(int i = 0; i < n; i++) {\n  \
    \  while(!s.empty() && v[s.back()] > v[i]) {\n      dsu.parent(s.back()) = i;\n\
    \      s.pop_back();\n    }\n    s.push_back(i);\n    for(auto p : cont[i]) {\n\
    \      ans[p.second] = v[dsu[p.first]];\n    }\n  }\n  return ans;\n}\n} // namespace\
    \ lib\n\n\n\n"
  code: "#ifndef _LIB_OFFLINE_RMQ\n#define _LIB_OFFLINE_RMQ\n#include <bits/stdc++.h>\n\
    #include \"DSU.cpp\"\n\nnamespace lib {\nusing namespace std;\n\n// O(n + qlogn)\n\
    template<typename T, typename U = T>\nvector<T> offline_rmq(const vector<T>& v,\
    \ const vector<pair<U, U>>& qrs) {\n  int n = v.size();\n  vector<vector<pair<U,\
    \ int>>> cont(n);\n  for(int i = 0; i < (int)qrs.size(); i++) {\n    auto p =\
    \ qrs[i];\n    cont[p.second].push_back({p.first, i});\n  }\n  vector<T> ans(qrs.size());\n\
    \n  CompressedDSU dsu(n);\n  vector<U> s;\n  for(int i = 0; i < n; i++) {\n  \
    \  while(!s.empty() && v[s.back()] > v[i]) {\n      dsu.parent(s.back()) = i;\n\
    \      s.pop_back();\n    }\n    s.push_back(i);\n    for(auto p : cont[i]) {\n\
    \      ans[p.second] = v[dsu[p.first]];\n    }\n  }\n  return ans;\n}\n} // namespace\
    \ lib\n\n#endif\n\n"
  dependsOn:
  - DSU.cpp
  isVerificationFile: false
  path: OfflineRMQ.cpp
  requiredBy: []
  timestamp: '2021-01-27 17:15:40-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: OfflineRMQ.cpp
layout: document
redirect_from:
- /library/OfflineRMQ.cpp
- /library/OfflineRMQ.cpp.html
title: OfflineRMQ.cpp
---
