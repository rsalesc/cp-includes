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
  bundledCode: "#line 1 \"dsu/Time.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace dsu {\n\ntemplate<typename D>\nstruct\
    \ Time : public D {\n  using D::r;\n  using D::sz;\n\n  vector<int> t;\n  int\
    \ tempo = 0;\n  Time() : D() {}\n  Time(int n) : D(n), t(n, 1e9) {}\n  virtual\
    \ void clear() override {\n    tempo = 0;\n    fill(t.begin(), t.end(), (int)1e9);\n\
    \  }\n  int get(int i, int tt) const {\n    return r[i] == i ? i : (t[i] <= tt\
    \ ? get(r[i]) : i);\n  }\n  int get_merge_time(int u, int v) const {\n    int\
    \ ans = -1;\n    while(u != v) {\n      if(sz[u] < sz[v]) swap(u, v);\n      ans\
    \ = max(ans, t[v]);\n      if(r[v] == v) return -1;\n      v = r[v];\n    }\n\
    \    return ans;\n  }\n  Time& at_time(int tt) {\n    assert(tt >= tempo);\n \
    \   tempo = tt;\n    return *this;\n  }\n  Time& tick() {\n    return at_time(tempo+1);\n\
    \  }\n  virtual void merged(int u, int v) override {\n    D::merged(u, v);\n \
    \   t[u] = tempo;\n  }\n};\n} // namespace dsu\n} // namespace lib\n\n\n\n"
  code: "#ifndef _LIB_DSU_TIME\n#define _LIB_DSU_TIME\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\nnamespace dsu {\n\ntemplate<typename D>\n\
    struct Time : public D {\n  using D::r;\n  using D::sz;\n\n  vector<int> t;\n\
    \  int tempo = 0;\n  Time() : D() {}\n  Time(int n) : D(n), t(n, 1e9) {}\n  virtual\
    \ void clear() override {\n    tempo = 0;\n    fill(t.begin(), t.end(), (int)1e9);\n\
    \  }\n  int get(int i, int tt) const {\n    return r[i] == i ? i : (t[i] <= tt\
    \ ? get(r[i]) : i);\n  }\n  int get_merge_time(int u, int v) const {\n    int\
    \ ans = -1;\n    while(u != v) {\n      if(sz[u] < sz[v]) swap(u, v);\n      ans\
    \ = max(ans, t[v]);\n      if(r[v] == v) return -1;\n      v = r[v];\n    }\n\
    \    return ans;\n  }\n  Time& at_time(int tt) {\n    assert(tt >= tempo);\n \
    \   tempo = tt;\n    return *this;\n  }\n  Time& tick() {\n    return at_time(tempo+1);\n\
    \  }\n  virtual void merged(int u, int v) override {\n    D::merged(u, v);\n \
    \   t[u] = tempo;\n  }\n};\n} // namespace dsu\n} // namespace lib\n\n#endif\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: dsu/Time.cpp
  requiredBy: []
  timestamp: '2021-02-26 00:37:16-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dsu/Time.cpp
layout: document
redirect_from:
- /library/dsu/Time.cpp
- /library/dsu/Time.cpp.html
title: dsu/Time.cpp
---
