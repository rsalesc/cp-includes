---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/unionfind-with-compression.test.cpp
    title: tests/yosupo/unionfind-with-compression.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: dsu/Compress.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/unionfind-with-compression.test.cpp
documentation_of: dsu/Compress.cpp
layout: document
redirect_from:
- /library/dsu/Compress.cpp
- /library/dsu/Compress.cpp.html
title: dsu/Compress.cpp
---
