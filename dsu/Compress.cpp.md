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
  bundledCode: "#line 1 \"dsu/Compress.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace dsu {\n\ntemplate<typename D>\nstruct\
    \ Compress : public D {\n  using D::r;\n\n  Compress() : D() {}\n  Compress(int\
    \ n) : D(n) {}\n\n  virtual int get(int i) const override {\n    return r[i] ==\
    \ i ? i : r[i] = get(r[i]);\n  }\n};\n} // namespace dsu\n} // namespace lib\n\
    \n\n\n"
  code: "#ifndef _LIB_DSU_COMPRESS\n#define _LIB_DSU_COMPRESS\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace dsu {\n\ntemplate<typename\
    \ D>\nstruct Compress : public D {\n  using D::r;\n\n  Compress() : D() {}\n \
    \ Compress(int n) : D(n) {}\n\n  virtual int get(int i) const override {\n   \
    \ return r[i] == i ? i : r[i] = get(r[i]);\n  }\n};\n} // namespace dsu\n} //\
    \ namespace lib\n\n#endif\n\n"
  dependsOn: []
  isVerificationFile: false
  path: dsu/Compress.cpp
  requiredBy: []
  timestamp: '2021-02-26 00:37:16-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dsu/Compress.cpp
layout: document
redirect_from:
- /library/dsu/Compress.cpp
- /library/dsu/Compress.cpp.html
title: dsu/Compress.cpp
---