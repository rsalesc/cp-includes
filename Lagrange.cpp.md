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
  bundledCode: "#line 1 \"Lagrange.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace linalg {\ntemplate <typename Field> struct\
    \ PrefixLagrange {\n  vector<Field> fat, ifat, pref, suf;\n  PrefixLagrange()\
    \ {\n    fat = {1};\n    ifat = {1};\n  }\n\n  void ensure(int n) {\n    int o\
    \ = fat.size();\n    if (n + 1 <= o)\n      return;\n    fat.resize(n + 1), ifat.resize(n\
    \ + 1);\n    pref.resize(n + 5), suf.resize(n + 5);\n\n    for (int i = o; i <=\
    \ n; i++)\n      fat[i] = fat[i - 1] * i;\n\n    ifat.back() = Field(1) / fat.back();\n\
    \    for (int i = n - 1; i >= o; i--)\n      ifat[i] = ifat[i + 1] * (i + 1);\n\
    \  }\n\n  template <typename T> Field eval(const vector<Field> &v, T x) {\n  \
    \  assert(!v.empty());\n    int d = (int)v.size() - 1;\n    if (x <= d)\n    \
    \  return v[x];\n\n    ensure(d + 1);\n\n    pref[0] = suf[d] = 1;\n    for (int\
    \ i = 0; i < d; i++)\n      pref[i + 1] = pref[i] * (x - i);\n    for (int i =\
    \ d; i; i--)\n      suf[i - 1] = suf[i] * (x - i);\n\n    Field ans = 0;\n   \
    \ for (int i = 0; i <= d; i++) {\n      Field l = pref[i] * suf[i] * ifat[i] *\
    \ ifat[d - i];\n      if ((d + i) & 1)\n        l = -l;\n      ans += l * v[i];\n\
    \    }\n    return ans;\n  }\n};\n} // namespace linalg\n} // namespace lib\n\n\
    \n"
  code: "#ifndef _LIB_LAGRANGE\n#define _LIB_LAGRANGE\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\nnamespace linalg {\ntemplate <typename\
    \ Field> struct PrefixLagrange {\n  vector<Field> fat, ifat, pref, suf;\n  PrefixLagrange()\
    \ {\n    fat = {1};\n    ifat = {1};\n  }\n\n  void ensure(int n) {\n    int o\
    \ = fat.size();\n    if (n + 1 <= o)\n      return;\n    fat.resize(n + 1), ifat.resize(n\
    \ + 1);\n    pref.resize(n + 5), suf.resize(n + 5);\n\n    for (int i = o; i <=\
    \ n; i++)\n      fat[i] = fat[i - 1] * i;\n\n    ifat.back() = Field(1) / fat.back();\n\
    \    for (int i = n - 1; i >= o; i--)\n      ifat[i] = ifat[i + 1] * (i + 1);\n\
    \  }\n\n  template <typename T> Field eval(const vector<Field> &v, T x) {\n  \
    \  assert(!v.empty());\n    int d = (int)v.size() - 1;\n    if (x <= d)\n    \
    \  return v[x];\n\n    ensure(d + 1);\n\n    pref[0] = suf[d] = 1;\n    for (int\
    \ i = 0; i < d; i++)\n      pref[i + 1] = pref[i] * (x - i);\n    for (int i =\
    \ d; i; i--)\n      suf[i - 1] = suf[i] * (x - i);\n\n    Field ans = 0;\n   \
    \ for (int i = 0; i <= d; i++) {\n      Field l = pref[i] * suf[i] * ifat[i] *\
    \ ifat[d - i];\n      if ((d + i) & 1)\n        l = -l;\n      ans += l * v[i];\n\
    \    }\n    return ans;\n  }\n};\n} // namespace linalg\n} // namespace lib\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Lagrange.cpp
  requiredBy: []
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Lagrange.cpp
layout: document
redirect_from:
- /library/Lagrange.cpp
- /library/Lagrange.cpp.html
title: Lagrange.cpp
---
