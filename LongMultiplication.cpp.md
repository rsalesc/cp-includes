---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':warning:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':warning:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':warning:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  - icon: ':warning:'
    path: tests/yosupo/fps_inv.cpp
    title: tests/yosupo/fps_inv.cpp
  - icon: ':warning:'
    path: tests/yosupo/fps_power.cpp
    title: tests/yosupo/fps_power.cpp
  - icon: ':warning:'
    path: tests/yosupo/interplation.cpp
    title: tests/yosupo/interplation.cpp
  - icon: ':warning:'
    path: tests/yosupo/kth_term_lr.cpp
    title: tests/yosupo/kth_term_lr.cpp
  - icon: ':warning:'
    path: tests/yosupo/lr.cpp
    title: tests/yosupo/lr.cpp
  - icon: ':warning:'
    path: tests/yosupo/multipoint.cpp
    title: tests/yosupo/multipoint.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"LongMultiplication.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace math {\nstruct NaiveMultiplication\
    \ {\n  template<typename T>\n  using Transform = void;\n\n  template <typename\
    \ Field>\n  vector<Field> operator()(const vector<Field> &a,\n               \
    \            const vector<Field> &b) const {\n    vector<Field> res(a.size() +\
    \ b.size());\n    for (size_t i = 0; i < a.size(); i++) {\n      for (size_t j\
    \ = 0; j < b.size(); j++) {\n        res[i + j] += a[i] * b[j];\n      }\n   \
    \ }\n    return res;\n  }\n};\n\ntemplate <typename Mult, typename Field>\nvector<Field>\
    \ shift_conv(const vector<Field> &a, vector<Field> b) {\n  if (b.empty())\n  \
    \  return {};\n  reverse(b.begin(), b.end());\n  int n = a.size();\n  int m =\
    \ b.size();\n\n  auto res = Mult()(a, b);\n  return vector<Field>(res.begin()\
    \ + m - 1, res.end());\n}\n} // namespace math\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_LONG_MULTIPLICATION\n#define _LIB_LONG_MULTIPLICATION\n#include\
    \ <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\nnamespace math {\n\
    struct NaiveMultiplication {\n  template<typename T>\n  using Transform = void;\n\
    \n  template <typename Field>\n  vector<Field> operator()(const vector<Field>\
    \ &a,\n                           const vector<Field> &b) const {\n    vector<Field>\
    \ res(a.size() + b.size());\n    for (size_t i = 0; i < a.size(); i++) {\n   \
    \   for (size_t j = 0; j < b.size(); j++) {\n        res[i + j] += a[i] * b[j];\n\
    \      }\n    }\n    return res;\n  }\n};\n\ntemplate <typename Mult, typename\
    \ Field>\nvector<Field> shift_conv(const vector<Field> &a, vector<Field> b) {\n\
    \  if (b.empty())\n    return {};\n  reverse(b.begin(), b.end());\n  int n = a.size();\n\
    \  int m = b.size();\n\n  auto res = Mult()(a, b);\n  return vector<Field>(res.begin()\
    \ + m - 1, res.end());\n}\n} // namespace math\n} // namespace lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: LongMultiplication.cpp
  requiredBy:
  - PowerSeries.cpp
  - LinearRecurrence.cpp
  - PolynomialRing.cpp
  - tests/yosupo/multipoint.cpp
  - tests/yosupo/fps_power.cpp
  - tests/yosupo/interplation.cpp
  - tests/yosupo/fps_inv.cpp
  - tests/yosupo/kth_term_lr.cpp
  - tests/yosupo/lr.cpp
  - polynomial/MultipointEvaluation.cpp
  timestamp: '2021-01-30 22:31:25-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: LongMultiplication.cpp
layout: document
redirect_from:
- /library/LongMultiplication.cpp
- /library/LongMultiplication.cpp.html
title: LongMultiplication.cpp
---
