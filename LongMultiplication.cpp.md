---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':question:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':question:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/find-lr.test.cpp
    title: tests/yosupo/find-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fps-inv.test.cpp
    title: tests/yosupo/fps-inv.test.cpp
  - icon: ':x:'
    path: tests/yosupo/fps-power.test.cpp
    title: tests/yosupo/fps-power.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/kth-term-lr.test.cpp
    title: tests/yosupo/kth-term-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/multipoint.test.cpp
    title: tests/yosupo/multipoint.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/subset-sum.test.cpp
    title: tests/yosupo/subset-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
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
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: LongMultiplication.cpp
  requiredBy:
  - PowerSeries.cpp
  - LinearRecurrence.cpp
  - PolynomialRing.cpp
  - polynomial/MultipointEvaluation.cpp
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/yosupo/fps-power.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/subset-sum.test.cpp
  - tests/yosupo/find-lr.test.cpp
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/fps-inv.test.cpp
documentation_of: LongMultiplication.cpp
layout: document
redirect_from:
- /library/LongMultiplication.cpp
- /library/LongMultiplication.cpp.html
title: LongMultiplication.cpp
---