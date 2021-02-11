---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: matroid/MatroidIntersection.cpp
    title: matroid/MatroidIntersection.cpp
  - icon: ':warning:'
    path: matroid/v2/MatroidIntersection.cpp
    title: matroid/v2/MatroidIntersection.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/FastQueue.cpp\"\n\n\n#include <bits/stdc++.h>\n\n\
    namespace lib {\n  using namespace std;\ntemplate<typename T>\nstruct FastQueue\
    \ {\n  vector<T> v;\n  int L = 0, R = 0;\n  FastQueue(int cap) : v(cap) {}\n\n\
    \  void push(const T& no) {\n    if(R >= v.size()) v.emplace_back();\n    v[R++]\
    \ = no;\n  }\n  T& front() {\n    return v[L];\n  }\n  T front() const {\n   \
    \ return v[L];\n  }\n  T pop() {\n    return v[L++];\n  }\n  bool empty() const\
    \ {\n    return L >= R;\n  }\n  int size() const {\n    return max(R - L, 0);\n\
    \  }\n  void clear() {\n    L = 0, R = 0;\n  }\n};\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_FAST_QUEUE\n#define _LIB_FAST_QUEUE\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\n  using namespace std;\ntemplate<typename T>\nstruct FastQueue\
    \ {\n  vector<T> v;\n  int L = 0, R = 0;\n  FastQueue(int cap) : v(cap) {}\n\n\
    \  void push(const T& no) {\n    if(R >= v.size()) v.emplace_back();\n    v[R++]\
    \ = no;\n  }\n  T& front() {\n    return v[L];\n  }\n  T front() const {\n   \
    \ return v[L];\n  }\n  T pop() {\n    return v[L++];\n  }\n  bool empty() const\
    \ {\n    return L >= R;\n  }\n  int size() const {\n    return max(R - L, 0);\n\
    \  }\n  void clear() {\n    L = 0, R = 0;\n  }\n};\n} // namespace lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/FastQueue.cpp
  requiredBy:
  - matroid/v2/MatroidIntersection.cpp
  - matroid/MatroidIntersection.cpp
  timestamp: '2021-01-28 01:15:31-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/FastQueue.cpp
layout: document
redirect_from:
- /library/utils/FastQueue.cpp
- /library/utils/FastQueue.cpp.html
title: utils/FastQueue.cpp
---
