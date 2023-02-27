---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/yosupo/static-rmq.test.cpp
    title: tests/yosupo/static-rmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/StaticRMQ.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace {\n  inline int lsb(int x) { return x&-x;\
    \ }\n}\n\n// Credits: hly1204\ntemplate<typename T, typename Cmp = std::less<T>>\n\
    struct StaticRMQ {\n  Cmp cmp;\n  vector<T> t1, t2, a;\n\n  StaticRMQ() {}\n\n\
    \  StaticRMQ(const vector<T>& a)\n    : t1(a.size() + 1), t2(a.size() + 1), a(a)\
    \ {\n    copy(a.begin(), a.end(), t1.begin() + 1);\n    copy(a.begin(), a.end(),\
    \ t2.begin() + 1);\n    build();\n  }\n\n  int size() const { return (int)t1.size()\
    \ - 1; }\n\n  T best(const T& a, const T& b) const {\n    return cmp(a, b) ? a\
    \ : b;\n  }\n\n  void build() {\n    int n = size();\n    for(int i = 1; i <=\
    \ n; i++) {\n      int b = lsb(i);\n      if(i + b <= n) t1[i + b] = best(t1[i\
    \ + b], t1[i]);\n    }\n    for(int i = n; i; i--) {\n      int b = lsb(i);\n\
    \      t2[i - b] = best(t2[i - b], t2[i]);\n    }\n  }\n\n  // [l, r], 0-indexed\n\
    \  T query(int l, int r) const {\n    if(l == r) return a[l];\n    ++l, ++r;\n\
    \    T ans = best(a[l-1], a[r-1]);\n    int x = l;\n    for(; x + lsb(x) - 1 <=\
    \ r; x += lsb(x))\n      ans = best(ans, t2[x]);\n    for(int y = r; y != 0 &&\
    \ y - lsb(y) + 1 >= l; y -= lsb(y))\n      ans = best(ans, t1[y]);\n    if(x <=\
    \ r)\n      ans = best(ans, a[x-1]);\n    return ans;\n  }\n};\n} // namespace\
    \ lib\n\n\n\n"
  code: "#ifndef _LIB_STATIC_RMQ\n#define _LIB_STATIC_RMQ\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace {\n  inline int lsb(int x)\
    \ { return x&-x; }\n}\n\n// Credits: hly1204\ntemplate<typename T, typename Cmp\
    \ = std::less<T>>\nstruct StaticRMQ {\n  Cmp cmp;\n  vector<T> t1, t2, a;\n\n\
    \  StaticRMQ() {}\n\n  StaticRMQ(const vector<T>& a)\n    : t1(a.size() + 1),\
    \ t2(a.size() + 1), a(a) {\n    copy(a.begin(), a.end(), t1.begin() + 1);\n  \
    \  copy(a.begin(), a.end(), t2.begin() + 1);\n    build();\n  }\n\n  int size()\
    \ const { return (int)t1.size() - 1; }\n\n  T best(const T& a, const T& b) const\
    \ {\n    return cmp(a, b) ? a : b;\n  }\n\n  void build() {\n    int n = size();\n\
    \    for(int i = 1; i <= n; i++) {\n      int b = lsb(i);\n      if(i + b <= n)\
    \ t1[i + b] = best(t1[i + b], t1[i]);\n    }\n    for(int i = n; i; i--) {\n \
    \     int b = lsb(i);\n      t2[i - b] = best(t2[i - b], t2[i]);\n    }\n  }\n\
    \n  // [l, r], 0-indexed\n  T query(int l, int r) const {\n    if(l == r) return\
    \ a[l];\n    ++l, ++r;\n    T ans = best(a[l-1], a[r-1]);\n    int x = l;\n  \
    \  for(; x + lsb(x) - 1 <= r; x += lsb(x))\n      ans = best(ans, t2[x]);\n  \
    \  for(int y = r; y != 0 && y - lsb(y) + 1 >= l; y -= lsb(y))\n      ans = best(ans,\
    \ t1[y]);\n    if(x <= r)\n      ans = best(ans, a[x-1]);\n    return ans;\n \
    \ }\n};\n} // namespace lib\n\n#endif\n\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: ds/StaticRMQ.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:43-03:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/yosupo/static-rmq.test.cpp
documentation_of: ds/StaticRMQ.cpp
layout: document
redirect_from:
- /library/ds/StaticRMQ.cpp
- /library/ds/StaticRMQ.cpp.html
title: ds/StaticRMQ.cpp
---
