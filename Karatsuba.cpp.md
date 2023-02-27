---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Karatsuba.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace math {\nstruct Karatsuba {\n  template\
    \ <typename Field>\n  vector<Field> multiply(const vector<Field> &a, const vector<Field>\
    \ &b) const {\n    if (b.size() == 0)\n      return {};\n    if (b.size() == 1)\
    \ {\n      vector<Field> res = a;\n      for (Field &res : a)\n        res *=\
    \ b[0];\n    }\n\n    int shift = a.size() / 2;\n    vector<Field> a0 = a;\n \
    \   vector<Field> b0 = b;\n    a0.resize(min(shift, a.size()));\n    b0.resize(min(shift,\
    \ b.size()));\n  }\n\n  template <typename Field>\n  vector<Field> operator()(const\
    \ vector<Field> &a,\n                           const vector<Field> &b) const\
    \ {\n    if (a.size() >= b.size())\n      return multiply(a, b);\n    else\n \
    \     return multiply(b, a);\n  }\n};\n} // namespace math\n} // namespace lib\n\
    \n\n"
  code: "#ifndef _LIB_KARATSUBA\n#define _LIB_KARATSUBA\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace math {\nstruct Karatsuba {\n\
    \  template <typename Field>\n  vector<Field> multiply(const vector<Field> &a,\
    \ const vector<Field> &b) const {\n    if (b.size() == 0)\n      return {};\n\
    \    if (b.size() == 1) {\n      vector<Field> res = a;\n      for (Field &res\
    \ : a)\n        res *= b[0];\n    }\n\n    int shift = a.size() / 2;\n    vector<Field>\
    \ a0 = a;\n    vector<Field> b0 = b;\n    a0.resize(min(shift, a.size()));\n \
    \   b0.resize(min(shift, b.size()));\n  }\n\n  template <typename Field>\n  vector<Field>\
    \ operator()(const vector<Field> &a,\n                           const vector<Field>\
    \ &b) const {\n    if (a.size() >= b.size())\n      return multiply(a, b);\n \
    \   else\n      return multiply(b, a);\n  }\n};\n} // namespace math\n} // namespace\
    \ lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: Karatsuba.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Karatsuba.cpp
layout: document
redirect_from:
- /library/Karatsuba.cpp
- /library/Karatsuba.cpp.html
title: Karatsuba.cpp
---
