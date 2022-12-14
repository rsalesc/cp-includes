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
  bundledCode: "#line 1 \"Euclid.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace math {\nnamespace {\nconstexpr static\
    \ size_t ULL_SIZE = sizeof(unsigned long long);\n\ntemplate <typename T>\nusing\
    \ IsManageableInt =\n    typename conditional<is_integral<T>::value && sizeof(T)\
    \ <= ULL_SIZE,\n                         true_type, false_type>::type;\n} // namespace\n\
    \ntemplate <typename T, typename US = T> struct Euclid {\n  template <typename\
    \ U, typename V> static V safe_mod(U x, V m) {\n    x %= m;\n    if (x < 0)\n\
    \      x += m;\n    return x;\n  }\n\n  template <typename U,\n            typename\
    \ enable_if<IsManageableInt<U>::value>::type * = nullptr>\n  static U safe_mult(U\
    \ a, U b, U m) {\n    a = safe_mod(a, m), b = safe_mod(b, m);\n\n    if (!b) return\
    \ 0;\n    int hi = 63 - __builtin_clzll((unsigned long long)b);\n    U res = 0;\n\
    \    for (int i = hi; i >= 0; i--) {\n      res = safe_mod(res * 2, m);\n    \
    \  if ((b >> i) & 1)\n        res = safe_mod(res + a, m);\n    }\n    return res;\n\
    \  }\n\n  template <typename U,\n            typename enable_if<!IsManageableInt<U>::value>::type\
    \ * = nullptr>\n  static U safe_mult(U a, U b, U m) {\n    return a * b % m;\n\
    \  }\n\n  static T euclid_(T a, T b, T &x, T &y) {\n    if (a == 0) {\n      x\
    \ = 0, y = 1;\n      return b;\n    }\n    T x1, y1;\n    T g = euclid_(b % a,\
    \ a, x1, y1);\n    x = y1 - b / a * x1;\n    y = x1;\n    return g;\n  }\n\n \
    \ static T euclid(T a, T b, T &x, T &y) {\n    T g = euclid_(a, b, x, y);\n  \
    \  if (g < 0)\n      g = -g, x = -x, y = -y;\n    return g;\n  }\n\n  static pair<T,\
    \ T> crt(T a, T b, T m1, T m2) {\n    if (m1 < m2)\n      swap(m1, m2), swap(a,\
    \ b);\n    T xx, yy;\n    T g = euclid(m1, m2, xx, yy);\n    if (safe_mod(a, g)\
    \ != safe_mod(b, g))\n      return {0, 0};\n\n    T mod = m1 / g * m2;\n\n   \
    \ T x = safe_mod<T>(xx, mod);\n    US s = safe_mult<T>(x, (b - a) / g, m2 / g)\
    \ * m1 % mod;\n    T res = safe_mod<US, US>((US)a + s, mod);\n\n    return {safe_mod<T>(res,\
    \ mod), mod};\n  }\n\n  static pair<T, T> crt(const vector<pair<T, T>> &equations)\
    \ {\n    pair<T, T> acc = {0, 1};\n    for (const pair<T, T> &e : equations) {\n\
    \      acc = crt(acc.first, e.first, acc.second, e.second);\n      if (!acc.second)\n\
    \        return {0, 0};\n    }\n    return acc;\n  }\n\n  static bool diophantine_solution(T\
    \ a, T b, T c, T& x0, T& y0, T& g) {\n    g = euclid(a, b, x0, y0);\n    if (c\
    \ % g)\n      return false;\n    x0 *= c/g;\n    y0 *= c/g;\n    return true;\n\
    \  }\n\n  // Give solutions for diophantine in the form [x = x.first * k + x.second].\n\
    \  static bool diophantine_solutions(T a, T b, T c, pair<T, T>& x, pair<T, T>&\
    \ y) {\n    T g;\n    if(!diophantine_solution(a, b, c, x.second, y.second, g))\n\
    \      return false;\n    x.first = b / g;\n    y.first = -a / g;\n    return\
    \ true;\n  }\n\n  // Give parameterized solution (in terms of k) to:\n  // a_1\
    \ * k + b_1 = ... = a_n * k + b_n, i.e, an equation for where those\n  // functions\
    \ meet.\n  static bool linear_equality_system(const vector<pair<T, T>>& v, pair<T,\
    \ T>& res) {\n    assert(!v.empty());\n    res = v[0];\n    for(int i = 1; i <\
    \ v.size(); i++) {\n      pair<T, T> x, y;\n      if (!diophantine_solutions(res.first,\
    \ -v[i].first, v[i].second - res.second, x, y))\n        return false;\n     \
    \ auto num = res.first * x.first;\n      if (num < 0) num = -num;\n      res =\
    \ {\n        num,\n        safe_mod(res.second + safe_mult(res.first, x.second,\
    \ num), num),\n      };\n    }\n    return true;\n  }\n};\n\nusing LongCRT = Euclid<long\
    \ long, unsigned long long>;\n} // namespace math\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_EUCLID\n#define _LIB_EUCLID\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace math {\nnamespace {\nconstexpr static\
    \ size_t ULL_SIZE = sizeof(unsigned long long);\n\ntemplate <typename T>\nusing\
    \ IsManageableInt =\n    typename conditional<is_integral<T>::value && sizeof(T)\
    \ <= ULL_SIZE,\n                         true_type, false_type>::type;\n} // namespace\n\
    \ntemplate <typename T, typename US = T> struct Euclid {\n  template <typename\
    \ U, typename V> static V safe_mod(U x, V m) {\n    x %= m;\n    if (x < 0)\n\
    \      x += m;\n    return x;\n  }\n\n  template <typename U,\n            typename\
    \ enable_if<IsManageableInt<U>::value>::type * = nullptr>\n  static U safe_mult(U\
    \ a, U b, U m) {\n    a = safe_mod(a, m), b = safe_mod(b, m);\n\n    if (!b) return\
    \ 0;\n    int hi = 63 - __builtin_clzll((unsigned long long)b);\n    U res = 0;\n\
    \    for (int i = hi; i >= 0; i--) {\n      res = safe_mod(res * 2, m);\n    \
    \  if ((b >> i) & 1)\n        res = safe_mod(res + a, m);\n    }\n    return res;\n\
    \  }\n\n  template <typename U,\n            typename enable_if<!IsManageableInt<U>::value>::type\
    \ * = nullptr>\n  static U safe_mult(U a, U b, U m) {\n    return a * b % m;\n\
    \  }\n\n  static T euclid_(T a, T b, T &x, T &y) {\n    if (a == 0) {\n      x\
    \ = 0, y = 1;\n      return b;\n    }\n    T x1, y1;\n    T g = euclid_(b % a,\
    \ a, x1, y1);\n    x = y1 - b / a * x1;\n    y = x1;\n    return g;\n  }\n\n \
    \ static T euclid(T a, T b, T &x, T &y) {\n    T g = euclid_(a, b, x, y);\n  \
    \  if (g < 0)\n      g = -g, x = -x, y = -y;\n    return g;\n  }\n\n  static pair<T,\
    \ T> crt(T a, T b, T m1, T m2) {\n    if (m1 < m2)\n      swap(m1, m2), swap(a,\
    \ b);\n    T xx, yy;\n    T g = euclid(m1, m2, xx, yy);\n    if (safe_mod(a, g)\
    \ != safe_mod(b, g))\n      return {0, 0};\n\n    T mod = m1 / g * m2;\n\n   \
    \ T x = safe_mod<T>(xx, mod);\n    US s = safe_mult<T>(x, (b - a) / g, m2 / g)\
    \ * m1 % mod;\n    T res = safe_mod<US, US>((US)a + s, mod);\n\n    return {safe_mod<T>(res,\
    \ mod), mod};\n  }\n\n  static pair<T, T> crt(const vector<pair<T, T>> &equations)\
    \ {\n    pair<T, T> acc = {0, 1};\n    for (const pair<T, T> &e : equations) {\n\
    \      acc = crt(acc.first, e.first, acc.second, e.second);\n      if (!acc.second)\n\
    \        return {0, 0};\n    }\n    return acc;\n  }\n\n  static bool diophantine_solution(T\
    \ a, T b, T c, T& x0, T& y0, T& g) {\n    g = euclid(a, b, x0, y0);\n    if (c\
    \ % g)\n      return false;\n    x0 *= c/g;\n    y0 *= c/g;\n    return true;\n\
    \  }\n\n  // Give solutions for diophantine in the form [x = x.first * k + x.second].\n\
    \  static bool diophantine_solutions(T a, T b, T c, pair<T, T>& x, pair<T, T>&\
    \ y) {\n    T g;\n    if(!diophantine_solution(a, b, c, x.second, y.second, g))\n\
    \      return false;\n    x.first = b / g;\n    y.first = -a / g;\n    return\
    \ true;\n  }\n\n  // Give parameterized solution (in terms of k) to:\n  // a_1\
    \ * k + b_1 = ... = a_n * k + b_n, i.e, an equation for where those\n  // functions\
    \ meet.\n  static bool linear_equality_system(const vector<pair<T, T>>& v, pair<T,\
    \ T>& res) {\n    assert(!v.empty());\n    res = v[0];\n    for(int i = 1; i <\
    \ v.size(); i++) {\n      pair<T, T> x, y;\n      if (!diophantine_solutions(res.first,\
    \ -v[i].first, v[i].second - res.second, x, y))\n        return false;\n     \
    \ auto num = res.first * x.first;\n      if (num < 0) num = -num;\n      res =\
    \ {\n        num,\n        safe_mod(res.second + safe_mult(res.first, x.second,\
    \ num), num),\n      };\n    }\n    return true;\n  }\n};\n\nusing LongCRT = Euclid<long\
    \ long, unsigned long long>;\n} // namespace math\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: Euclid.cpp
  requiredBy: []
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Euclid.cpp
layout: document
redirect_from:
- /library/Euclid.cpp
- /library/Euclid.cpp.html
title: Euclid.cpp
---
