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
  bundledCode: "#line 1 \"Fenwick.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\ntemplate<typename T>\nstruct Fenwick {\n  vector<int>\
    \ t;\n  Fenwick(int n) : t(n+1) {}\n  int size() const { return t.size() - 1;\
    \ }\n  void add(int i, T x) {\n    for(i++; i < t.size(); i += (i&-i))\n     \
    \ t[i] += x;\n  }\n  T get(int i) const {\n    T res = 0;\n    for(i++; i > 0;\
    \ i -= (i&-i))\n      res += t[i];\n    return res;\n  }\n  T get(int i, int j)\
    \ const {\n    return get(j) - get(i - 1);\n  }\n  T from(int i) const {\n   \
    \ return get(i, size() - 1);\n  }\n};\n} // namespace lib\n\n"
  code: "#ifndef _LIB_FENWICK\n#define _LIB_FENWICK\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\ntemplate<typename T>\nstruct Fenwick {\n\
    \  vector<int> t;\n  Fenwick(int n) : t(n+1) {}\n  int size() const { return t.size()\
    \ - 1; }\n  void add(int i, T x) {\n    for(i++; i < t.size(); i += (i&-i))\n\
    \      t[i] += x;\n  }\n  T get(int i) const {\n    T res = 0;\n    for(i++; i\
    \ > 0; i -= (i&-i))\n      res += t[i];\n    return res;\n  }\n  T get(int i,\
    \ int j) const {\n    return get(j) - get(i - 1);\n  }\n  T from(int i) const\
    \ {\n    return get(i, size() - 1);\n  }\n};\n} // namespace lib\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Fenwick.cpp
  requiredBy: []
  timestamp: '2020-11-07 21:20:23-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Fenwick.cpp
layout: document
redirect_from:
- /library/Fenwick.cpp
- /library/Fenwick.cpp.html
title: Fenwick.cpp
---
